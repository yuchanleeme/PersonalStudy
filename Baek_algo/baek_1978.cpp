#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1978

/*
<소수 찾기>
주요: 자신보다 작은값(1제외)으로 나누었을때 나누어 떨어지지 않는 수를 찾는다.
1. for문을 이용해 2부터 자기 자신 -1 까지 하나씩 나누어본다.
2. 나머지가 없거나 1,2 일때 상황을 비교한다.

*/

int main() {

  int N, res = 0;
  bool res_trigger = true;
  scanf("%d",&N);

  int num[N];
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }

  for (int i = 0; i < N; i++) {
    // 1번 조건
    for (int j = 2; j < num[i] - 1 ; j++) {
      if(num[i] % j == 0){
        res_trigger = false;
        break;
      }
    }

    //2번 조건
    if ((res_trigger || num[i] == 2) && num[i] != 1){
      res++;
    }
    res_trigger = true;
  }

  printf("%d\n",res);

  return 0;
}
