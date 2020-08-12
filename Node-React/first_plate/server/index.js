const express = require('express')
const app = express()
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser')
const config = require('./config/key');
const {auth} = require('./middleware/auth')
const {User} = require("./models/User");

// application/x-www-form-urlencoded
// 데이터를 분석해서 가져올 수 있게 해줌
app.use(bodyParser.urlencoded({extended: true}));

// applicaion/json
// json 파일을 분석해서 가져올 수 있게 해줌
app.use(bodyParser.json());
app.use(cookieParser());

const mongoose = require('mongoose')
mongoose.connect(config.mongoURI,{
    useNewUrlParser : true, useUnifiedTopology : true, useCreateIndex: true, useFindAndModify: false
}).then(() => console.log('MongoDB Connected...'))
  .catch(err => console.log(err))

app.get('/', (req, res) => res.send('Hello World! here'))

app.get('/api/hello', (req, res)=>{
  res.send("HI")
})

// post를 보내준다.
app.post('/api/users/register', (req, res) => {

  // 회원 가입 할 때 필요한 정보들을 client에서 가져오면
  // 그것들을 데이터 베이스에 넣어준다.  
  const user = new User(req.body)
  // console.log("req.body : " , req.body)
  user.save((err, userInfo) => {
    if(err) return res.json({success: false, err})
    return res.status(200).json({
      success: true
    })
  })

})

// 로그인 라우터
app.post('/api/users/login', (req, res) => {

  // 1. 요청된 이메일을 데이터베이스에 있는지 찾는다.
  User.findOne({ email: req.body.email }, (err, user) => {
    if(!user){
      return res.json({
        loginSuccess: false,
        message: "제공된 이메일에 해당하는 유저가 없습니다."
      })
    }
    // 2. 요청된 이메일이 DB에 있다면 비밀번호가 맞는지 확인한다.
    user.comparePassword(req.body.password, (err, isMatch) =>{
      if(!isMatch)
        return res.json({ loginSuccess: false, message: "비밀번호가 틀렸습니다."})
        // 3. 비밀번호까지 맞다면 토큰을 생성한다.
      user.generateToken((err, user) =>{
        if(err) return res.status(400).senc(err);

        // 토큰을 (쿠키, 로컬스토리지 등) 에 저장한다.
        res.cookie("x_auth", user.token)
        .status(200)
        .json({loginSuccess: true, userId : user._id})
      })
    })
  })
})

app.get('/api/users/auth', auth, (req, res) =>{
  // 여기 까지 미들웨어를 통과해 왔다는 얘기는 Authentication이 True라는 말.
  res.status(200).json({
    _id: req.user._id,
    isAdmin: req.user.role === 0 ? false : true,
    isAuth: true,
    email: req.user.email,
    name: req.user.name,
    lastname: req.user.lastname,
    role: req.user.role,
    image: req.user.image
  })
})

// 로그 아웃
app.get('/api/users/logout', auth, (req, res) => {
  User.findOneAndUpdate({_id: req.user._id},
    {token: ""}, (err, user) =>{
      if(err) return res.json({success: false, err})
      return res.status(200).send({
        success: true
      })
    })
})

const port = 5000
app.listen(port, () => console.log(`Example app listening on port ${port}!`))
