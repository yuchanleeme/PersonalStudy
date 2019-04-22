#include<stdio.h>

int main(){
  //https://www.acmicpc.net/problem/1005

  int T;
  int N,K; // 건물 개수, 건설순서규칙
  int D; // 각 건물당 건설에 걸리는 시간

  scanf("%d",&T); // 케이스 개수 입력
  scanf("%d %d",&N,&K); // 건물 개수, 건설순서규칙 입력

  int B[N][3];
  // 건물의 속성 저장 (0: 짓는데 걸리는 시간, 1: 지어졌는지 확인(0/1), 2:
  int XY[K][2]; // 건설 순서 XY 저장

  int sumTime=0; // 총걸리는 시간

  for (int i = 0; i < N; i++) { // 건설에 걸리는 시간
    scanf("%d",&B[i][0]);
  }

  for (int j = 0; j < K; j++) { // 건설 순서
    scanf("%d %d",XY[j][0],XY[j][1]);
  }



}
