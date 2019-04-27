#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1193

/*
<분수찾기>
주요: 분모, 분자의 합과 개수의 상관관계를 먼저 파악한다.
1. 분모,분자의 합은 1씩 커져간다.
2. 분모 분자의 합을 N이라라 할때 그 전 대각선 줄까지의 개수의 합은 1~(N-2) 까지의 합과 같다.
3. 1~(N-2) 까지의 합을 구한뒤 분모 또는 분자의 값을 더해주면 X번째 분수가 된다.
  (분모,분자의 합 N 이 홀수 일때 -> 분자를 더해줌, 짝수 일때 -> 분모를 더해줌)

  분모 : a ,분자 : b , 분모+분자 : N , 1~(N-2)까지의 합 :S 해당분수 : X
=> N이 홀수 : X = S + a => a = X - S / b = N - a
   N이 짝수 : X = S + b => b = X - S / a = N - b
*/

int main() {

  int a, b, N, X, S = 0;
  cin >> X;

  for(int i = 1 ; X > S ; i++){
    S += i;
    N = i;
  }

  S -= N; // S 만들기
  N += 1; // N 만들기

  if(N % 2 == 0){ // 분모,분자 확립
    b = X - S;
    a = N - b;
  }
  else{
    a = X - S;
    b = N - a;
  }

  cout << a << "/" << b << endl;

  return 0;
}
