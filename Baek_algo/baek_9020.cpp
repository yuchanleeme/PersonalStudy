#include <iostream>
#include <math.h>
using namespace std;
// https://www.acmicpc.net/problem/9020

/*
<골드바흐의 추측>
주요: 하나씩 찾아본다.
1. 2부터 N/2 까지 하나씩 조사한다. (a = 2,3... N/2  //  b = n-a )
2. a,b가 소수인지 판단하고 둘다 소수이면 그 차이 값을 저장한다.(dif)
3. dif값이 가장 적을 때 a,b를 저장한 res_a, res_b를 출력한다.

*/

int main() {

  int T, N, a, b, dif;
  int res_a, res_b;
  bool a_trigger = true;
  bool b_trigger = true;

  //입력
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {

    scanf("%d", &N);
    dif = 100001;   // 변수 초기화

    for (int i = 2; i <= N/2; i++) {
      a = i;
      b = N - a;

      // a가 소수인지 판단
      for (int j = 2; j <= sqrt((a)); j++) {
        if(a % j == 0){
          a_trigger = false;
          break;
        }
      }

      // b가 소수인지 판단
      for (int k = 2; k <= sqrt((b)); k++) {
        if(b % k == 0){
          b_trigger = false;
          break;
        }
      }

      // a,b가 둘 다 소수이고 그 차이가 가장 적을때를 저장
      if (a_trigger && b_trigger){
          if(dif >= b - a){
            dif = b - a;
            res_a = a;
            res_b = b;
        }
      }
      // 변수 초기화
      a_trigger = true;
      b_trigger = true;
    }

  // 출력
  printf("%d %d\n", res_a, res_b);
  }

  return 0;
}
