#include <iostream>
#include <math.h>
using namespace std;
// https://www.acmicpc.net/problem/4948

/*
<베르트랑 공준>
주요: 자신보다 작은값(1제외)으로 나누었을때 나누어 떨어지지 않는 수를 찾는다.
1. for문을 이용해 2부터 자기 자신의 제곱근값 까지 하나씩 나누어본다. (범위 : N < i <= 2*N)
  -> 제곱근값까지만 하는 이유 : 몫과 제수 둘중 하나는 반드시 N의 제곱근 이하이기 때문
2. 나머지가 있으면 break하고 res_trigger에 따라 값을 저장시킨다.

*/

int main() {

  int N, k;
  bool res_trigger = true;

  //입력
  while(true){
    scanf("%d",&N);
    if(N==0){break;}
    k = 0;

    for (int i = N+1; i <= 2*N; i++) {
      // 1번 조건
      for (int j = 2; j <= sqrt((i)) ; j++) {
        if(i % j == 0){
          res_trigger = false;
          break;
        }
      }

      //2번 조건
      if ((res_trigger || i == 2) && i != 1){
        k++;
      }
      res_trigger = true;
    }

    // 출력
    printf("%d\n",k);
  }

  return 0;
}
