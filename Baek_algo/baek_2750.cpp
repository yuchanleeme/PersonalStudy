#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2750

/*
<수 정렬하기>
주요: 오름차순으로 정렬한다.
1. 새로운 배열을 만들어 조건에 맞을 시 저장한다.
2. 중복, 오름차순(선택정렬)을 같은 for문안에서 처리한다.
*/

int main(int argc, char const *argv[]) {

  int N, temp, k = 0;
  int base[1000] = {};
  int result[1001];

  scanf("%d",&N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &base[i]);
  }

  // 선택정렬 (오름차순)
  for (int i = 0; i <N ; i++) {
    temp = i;
    for (int j = i+1; j < N; j++) {
      if(base[temp] >= base[j]){
        temp = j;
      }
    }
    swap(base[i],base[temp]);

    // 중복제거 배열 저장
    if(result[k-1]!= base[i]){
      result[k] = base[i];
      k++;
    }
    else if(k==0){
      result[k] = base[i];
      k++;
    }
  }

  for(int i = 0; i < k; i++) {
    printf("%d\n", result[i]);
  }

  return 0;
}
