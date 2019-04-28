#include <iostream>
#include <cmath>
using namespace std;
// https://www.acmicpc.net/problem/1107

/*
<리모컨>
주요: 2가지 경우를 나누어서 생각한다.
1. 근처의 수로 이동후 +- 버튼을 이용해서 이동하는 경우 (result_push)
2. 오직 +- 버튼만 이용해서 이동하는 경우 (result_only)

이 2가지 경우 중에 최솟값을 고르면 된다.

* 1번 조건에서 1000000까지 조사하는 이유
  =>

*/

// +- 버튼만으로 현재위치에서 목표 위치까지 이동할 때 눌리는 버튼의 수를 리턴하는 함수
int only_plus_minus(int current_channel, int target_channel){
  return abs(current_channel - target_channel);
}

// 전해받은 번호가 누를 수 있는 수인지 확인 하는 함수
bool is_push_button(int num, int *arr , int length){

  // 번호가 0 번일 때 비교
  if(num == 0){
    for(int i =0; i < length; i++){
      if(num % 10 == arr[i])
        return false;
    }
  }

  //번호가 0 번이 아닐때 비교
  while(num != 0){
    for(int i = 0; i < length; i++){
      if(num % 10 == arr[i])
        return false;
    }
    num /= 10;
  }

  return true;
}

// 번호를 전달 받아 그 자리수를 리턴하는 함수
int number_digits(int number){

  int result_digits = 0;

  if(number ==0){
    result_digits = 1;
  }
  else{
    while(number){
      number /= 10;
      result_digits++;
    }
  }

  return result_digits;
}

int main() {

  int N, M, result_only, result_i = 0, result_min;
  int current_channel = 100;
  int result_temp = 1000001;
  int result_push = 1000002;

  // 각 종 입력 받는 방법
  cin >> N ;
  cin >> M ;

  int broken_buffer[M];
  if(M != 0){
    for(int i = 0; i<M; i++){
      cin >> broken_buffer[i];
    }
  }
  int buffer_length = sizeof(broken_buffer)/sizeof(int);

  // 1번 조건을 만족 시키는 i 값을 찾는 방법
  for(int i = 0; i < 888888; i++){
    if(is_push_button(i,broken_buffer,buffer_length)){
      result_temp = only_plus_minus(N,i);
      if(result_push > result_temp){
        result_push = result_temp;
        result_i = i;
      }
    }
  }

  // 1,2 번 조건 비교 후 result_min에 값 저장
  result_push += number_digits(result_i);
  result_only = only_plus_minus(current_channel,N);

  if(result_push > result_only){
    result_min = result_only;
  }
  else{
    result_min = result_push;
  }

  cout << result_min << endl;

  return 0;
}
