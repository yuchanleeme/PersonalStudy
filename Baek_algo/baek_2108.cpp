#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// https://www.acmicpc.net/problem/2108

/*
<통계학>
주요: 기본 사칙연산 및 각 통계값의 조건들을 잘 분석하여 한번에 출력한다.
1. 산술평균 : N까지 다 더해서 N으로 나눈다. (round함수 - 반올림)
2. 중앙값 : 배열 정렬 후 중앙 값 출력.
3. 최빈값 : 절댓값이 4000을 넘지 않는것을 이용한다.
4. 범위 : 배열 정렬 후 끝값과 시작값을 빼준다.

*/

int main() {

  int N, sum = 0, temp_s, temp_f, most = 0, a1, a2, a3, a4;
  bool check_trigger = false;
  scanf("%d",&N);

  int base[N];
  int frequency[8001] = {};

  for(int i = 0; i < N; i++){
    scanf("%d",&base[i]);
  }

  // 오름차순 정렬
  sort(base,base+N);

  for (int i = 0; i < N; i++) {
    sum += base[i]; // 총 합 계산
    frequency[base[i]+4000]++; // 빈도 배열 저장
  }

  // 최빈값 계산
  for (int i = 0; i < 8001; i++) {
    if(frequency[i] > most){
      most = frequency[i];
      temp_f = i;
      check_trigger = true;
    }
    else if(frequency[i] == most){
      if(check_trigger == true){
        temp_f = i;
        check_trigger = false;
      }
    }
  }

  a1 = round(double(sum)/N);
  a2 = base[N/2];
  a3 = temp_f - 4000;
  a4 = base[N-1] - base[0];

  printf("%d\n%d\n%d\n%d",a1,a2,a3,a4);

  return 0;
}
