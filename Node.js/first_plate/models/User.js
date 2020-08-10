const mongoose = require('mongoose')
const bcrypt = require('bcrypt')
const saltRounds = 10

const userSchema = mongoose.Schema({
    name: {
        type: String,
        maxlength: 50
    },
    email: {
        type: String,
        trim: true,
        unique: 1
    },
    password: {
        type: String,
        minlength: 5
    },
    role: { // 관리자, 참가자 구분
        type: Number,
        default: 0
    },
    image: String,
    token: {    // 유효성
        type: String
    },
    tokenExp: { // 토큰 유효기간
        type: Number
    }
})

// 저장하기 전에 한다.
userSchema.pre('save', function (next){
    var user = this;

    //비밀번호를 바꿀때만 암호화 해준다.
    if(user.isModified('password')){
        // 비밀번호를 암호화 한다.
  
        bcrypt.genSalt(saltRounds, function(err, salt){
            if(err) return next(err)

            // myPlaintextPassword: 순수 비밀번호
            bcrypt.hash(user.password, salt, function(err, hash){
                if(err) return next(err)
                // store hash in your password DB.
                user.password = hash
                next()
            })
        })
    }else{
        next()
    }
})

const User = mongoose.model('User',userSchema)

module.exports = {User}