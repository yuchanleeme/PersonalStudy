#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/11650

/*
<좌표 정렬>
주요: 구조체를 이용해 비교한다.
1. X값과 Y값을 멤버로 갖는 구조체를 선언한다.
2. 구조체 배열을 이용해 각 멤버를 저장한다.
3. sort 함수를 이용해 정렬하여 출력한다. (조건에 맞게)

*/

typedef struct Dot{
  int x;
  int y;
}Dot;

// sort을 위한 compare 함수
bool compare(const Dot &a, const Dot &b){
  if(a.x == b.x){
    if(a.y < b.y){ // x값이 같을 때 y값 비교
      return true;
    }
    else{
      return false;
    }
  }
  return a.x < b.x;
}

int main() {

  int N;
  scanf("%d",&N);

  Dot dot[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d",&dot[i].x,&dot[i].y);
  }

  //정렬
  sort(dot,dot+N,compare);

  for (int i = 0; i < N; i++) {
    printf("%d %d\n",dot[i].x,dot[i].y);
  }

  return 0;
}
