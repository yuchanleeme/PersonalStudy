#include <iostream>
#include <cmath>

// 예상되는 입/출력은 제대로 나오지만 채점에서 통과가 안되고 있음
// 다른 풀이과정을 이용 or 풀이를 좀 더 깔끔히 해야함

using namespace std;

// +- 버튼만 이용해서 이동하는 함수
int only_plus_minus(int current_channel, int target_channel){
  return abs(current_channel - target_channel);
}

// 누를 수 있는 수인지 확인 하는 함수
bool is_push_button(int num, int *arr , int length){

  if(num ==0){
    for(int i =0; i < length ; i++){
      if(num%10 == arr[i])
        return false;
    }
  }
  while(num != 0){
    for(int i =0; i < length ; i++){
      if(num%10 == arr[i])
        return false;
    }
    num /=10;
  }
  return true;
}

int main() {
  // https://www.acmicpc.net/problem/1107
  int N,M,result_only,result_i,result_digits =0;
  int current_channel = 100;
  int result_temp = 1000002;
  int result_push = 1000001;

  cin >> N ;
  cin >> M ;

  int broken_buffer[M];
  if(M!=0){
    for(int i = 0; i<M ; i++){
      cin>>broken_buffer[i];
    }
  }

  for(int i = 0; i<1000000 ; i++){
     // cout<< i << " i " <<endl;
    if(is_push_button(i,broken_buffer,sizeof(broken_buffer)/sizeof(int))){
      result_push = only_plus_minus(N,i);
       // cout<< result_push << " result_push " <<endl;
    }
    if(result_temp > result_push){
      result_temp = result_push;
      result_i = i;
       // cout<< result_temp << " result_temp " <<endl;
    }
  }

  while(result_i){
    result_i /= 10;
    ++result_digits;
  }
  if(result_i ==0){
    result_digits = 1;
  }
  result_temp += result_digits;

  result_only = only_plus_minus(current_channel,N);

  if(result_temp > result_only){
    result_temp = result_only;
  }
  if(N==0&&M==0&&is_push_button(0,broken_buffer,sizeof(broken_buffer)/sizeof(int))){
    result_temp = 1;
  }
  else if(M==10){
    result_temp = 0;
  }
  cout<<result_temp<<endl;

  return 0;
}
