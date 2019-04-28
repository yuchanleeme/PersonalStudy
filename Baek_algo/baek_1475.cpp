#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1475

/*
<방 번호>
주요: (6,9)가 나온 개수와 그 나머지가 나온 개수를 비교해서 알고리즘을 파악한다.
1. 0~9까지 몇번 사용했는지 조사한다.
2. 6,9 중 더 많이 사용한 횟수(S)를 저장한다.
3. 6,9를 제외한 숫자 중 가장 많이 사용된 수(K)를 저장한다.
4. S 와 K를 비교해 답을 도출한다.
  1) S == K // S,K가 0일 시 (N이 0) : 1
  1) S <= K : K
  2) S > K :
    (1) 6,9 합이 홀수 : [(num[6]+num[9]) / 2] + 1
    (2) 6,9 합이 짝수 : (num[6]+num[9]) / 2
    (3) =====> 결론 :  (num[6]+num[9] + 1) / 2
*/

int main() {

  int N, result = 0, S = 0, K = 0;
  int num[10] = {};

  cin >> N;

  // num 배열에 0~9 숫자들이 나온개수 더해서 저장
  while(N != 0){
    num[N % 10] += 1;
    N /= 10;
  }

  // S, K 값 저장
  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9){
      if(S < num[i]){
        S = num[i];
      }
    }
    else{
      if(K < num[i]){
        K = num[i];
      }
    }
  }

  // S, K값 비교 => result 도출
  if(S == 0 && K ==0){
      result = 1;
    }
  else if(S <= K){
      result = K;
    }
  else{
    result = (num[6] + num[9] + 1) / 2;
  }

  cout << result << endl;

  return 0;
}
