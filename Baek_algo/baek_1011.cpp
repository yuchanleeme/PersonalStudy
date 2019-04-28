#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1011

/*
<Fly me to the Alpha Centauri>
주요: 규칙성을 찾아서 범위를 세워보자.
1. 시작할때와 끝날때는 무조건 1광년 이동으로 끝나야한다.
2. 어디서 시작하고 끝나는지는 중요하지 않다. 둘 사이의 거리만을 이용하면 된다.
3. 1 -> f -> 1  // 수열의 모든 값은 인접 항과의 차이가 1씩만 나야한다.
4. 수열의 총 개수(이동횟수)를 기준으로 분류한다.
  (이동 횟수 -(N), 이동횟수로 이동가능한 최대 광년 - L(N),이동광년 (x-y))
5. N이 홀수/짝수 일때마다 달라진다는 것을 알 수 있다.
6. L(N-1) < y-x <= L(N) 을 만족시키는 N을 찾아 리턴한다.
======================
홀수 : L(N) = 2 * (1~(N+1)/2의 합) - (N+1)/2
짝수 : L(N) = 2 * (1~(N+1)/2의 합)

*/
int main() {

  // x,y 의 범위 고려 시 int가 아닌 unsigned int로 변수형을 선언한다.
  unsigned int T, x, y, dist, N, min, max, temp;

  scanf("%d",&T);
  for(int i = 0; i<T; i++){
    // 변수 초기화
    N = 1;
    min = 0;
    max = 0;

    scanf("%d%d",&x,&y);
    dist = y-x;

    while(true){
      // for문 돌릴 시 시간이 초과 되므로 바로 합을 계산한다.
      temp = (N+1)/2;
      max = (temp * (temp+1)) / 2;

      // 5,6 기준에 맞게 홀수/짝수 에 맞게 범위를 지정해준다.
      if(N % 2 == 0){
        max *= 2;
      }
      else{
        max = 2*max - (N+1)/2;
      }

      // 기준에 부합하면 while문 탈출
      if(min < dist && max >= dist){
        break;
      }
      else{
        min = max;
        max = 0;
        N++;
      }
    }
    // 기준에 맞는 N회 출력
    printf("%d\n",N);
  }
  return 0;
}
