#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1085

/*
<직사각형에서 탈출>
주요: 동서남북으로 이동 시 가장 가까운 거리를 구한다.
1. 각 대각선 꼭짓점의 값들이 (w,h)가 한방향으로 움직였을 때 최대로 도달할 수 있는 값들이다.
2. 두 좌표값과 w,h의 차의 절댓값을 구해주면 된다.

*/

int main() {

  int x,y,w,h,temp=1000;
  int result[4];

  cin >> x >> y >> w >> h;

  result[0] = w-x; // 직사각형 오른쪽 경계선
  result[1] = h-y; // 직사각형 위쪽 경계선
  result[2] = x;   // 직사각형 왼쪽 경계선
  result[3] = y;   // 직사각형 아래쪽 경계선

  for(int i = 0 ; i<4 ; i++){
    if(result[i] <= temp){
      temp = result[i];
    }
  }
  cout << temp << endl;

  return 0;
}
