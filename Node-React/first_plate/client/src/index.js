import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import * as serviceWorker from './serviceWorker';
import { Provider } from 'react-redux'
import 'antd/dist/antd.css'
import { applyMiddleWare, createStore } from 'redux'
import promiseMiddleware from 'redux-promise';
import ReduxThunk from 'redux-thunk'
import Reducer from './_reducers';

const createStoreWithMiddleware = applyMiddleWare(promiseMiddleware, ReduxThunk)(createStore)

ReactDOM.render(
  <Provider
    store = {createStoreWithMiddleware(Reducer,
      window.___REDUX_DEVTOOLS_EXTENSION__ &&
      WINDOW.___REDUX_DEVTOOLS_EXTENSION__()
      )}
  >
    <App/>
  </Provider>
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();
