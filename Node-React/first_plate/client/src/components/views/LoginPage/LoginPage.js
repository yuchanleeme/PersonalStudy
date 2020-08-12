import React, { useState } from 'react'
import Axios from 'axios'
import { useDispatch } from 'react-redux'
import { loginUser } from '../../../_actions/user_action'

function LoginPage() {

  const dispatch = useDispatch();

  const [Email, setEmail] = useState("")
  const [Password, setPassword] = useState("")

  // 이메일 패스워드 타이핑 하게 해줌
  const onEmailHandler = (event) =>{
    setEmail(event.currentTarget.value)
  }
  const onPasswordHandler = (event) =>{
    setPassword(event.currentTarget.value)
  }

  // submit
  const onSubmitHandler = (event) =>{
    // 계속 새로고침 방지
    event.preventDefault();

    console.log('Email', Email)
    console.log('Password', Password)
    
    let body = {
      email: Email,
      password: Password
    }

    dispatch(loginUser(body))

  }

  return (
    <div style = {{
      display: 'flex', justifyContent: 'center', alignItems: 'center', width:'100%', height: '100vh'
    }}>

      <form style={{display: 'flex', flexDirection: 'column'}}
        onSubmit = {onSubmitHandler}
      >
        <label>Email</label>
        <input type="email" value={Email} onChange={onEmailHandler} />
        <label>Password</label>
        <input type="password" value={Password} onChange={onPasswordHandler} />
        <button>
          Login
        </button>
      </form>
    </div>
  )
}

export default LoginPage
