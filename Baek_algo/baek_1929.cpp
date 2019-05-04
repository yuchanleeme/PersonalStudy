#include <iostream>
#include <math.h>
using namespace std;
// https://www.acmicpc.net/problem/1929

/*
<소수 구하기>
주요: 자신보다 작은값(1제외)으로 나누었을때 나누어 떨어지지 않는 수를 찾는다.
1. for문을 이용해 2부터 자기 자신의 제곱근값 까지 하나씩 나누어본다. (범위 : M ~ N)
  -> 제곱근값까지만 하는 이유 : 몫과 제수 둘중 하나는 반드시 N의 제곱근 이하이기 때문
2. 나머지가 있으면 break하고 res_trigger에 따라 배열에 저장한다.

*/

int main() {

  int M, N, k = 0;
  int res[100000];
  bool res_trigger = true;

  //입력
  scanf("%d %d",&M, &N);

  for (int i = M; i <= N; i++) {
    // 1번 조건
    for (int j = 2; j <= sqrt((i)) ; j++) {
      if(i % j == 0){
        res_trigger = false;
        break;
      }
    }

    //2번 조건
    if ((res_trigger || i == 2) && i != 1){
      res[k] = i;
      k++;
    }
    res_trigger = true;

  }

  // 출력
  for (int i = 0; i < k; i++) {
    printf("%d\n",res[i]);
  }

  return 0;
}
