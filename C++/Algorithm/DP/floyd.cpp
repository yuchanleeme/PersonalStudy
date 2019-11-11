#include <iostream>
#include <vector>
using namespace std;
// 알고리즘 3.4절 (3.3절은 생략)

const int INF = 100000;
int n, e, q, r;
vector<vector<int> > p;

// 플로이드 워셜 최단거리 알고리즘 (3.4)
void floyd (int n, const vector<vector<int> > w, vector<vector<int> > d, vector<vector<int> > &p){

  int i, j, k;

  for (i = 1; i <= n; i++) {
    for (j = 1; j<= n; j++) {
      p[i][j] = 0;
    }
  }

  for (int p = 1; p <= n; p++) {
    for (int q = 1; q <= n; q++) {
      d[p][q] = w[p][q];
    }
  }

  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j<= n; j++) {
        if(d[i][k] + d[k][j] < d[i][j]){
          p[i][j] = k;
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }

  // 최종 최단거리 출력 (Dn)
  printf("==== D ====\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(d[i][j] == INF){ printf("   INF");}
      else{ printf("%5d ", d[i][j]);}
    }
    printf("\n");
  }
  printf("\n");
}

// 최단경로 출력 (3.5)
void path(int q, int r){
  if(p[q][r] != 0){
    path(q, p[q][r]);
    printf("v%d ", p[q][r]);
    path(p[q][r], r);
  }
}

int main(int argc, char const *argv[]) {

  // 정점의 개수 및 이음선의 개수 입력
  printf("INPUT 1 : \n");
  scanf("%d %d", &n, &e);

  vector<vector<int> > w(n+1, vector<int>(n+1,INF));
  vector<vector<int> > d(n+1, vector<int>(n+1,0));
  p = vector<vector<int> >(n+1, vector<int>(n+1,0));

  // W 그래프 만들기
  // 1 : 자기 자신으로 가는 가중치 0 만들기
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      w[i][j] = 0;
      break;
    }
  }

  // W 그래프 만들기
  // 2 : 이음선 입력 (%d %d %d : x->y로 가는데 가중치 dist)
  for (int i = 0; i < e; i++) {
    int x, y, dist;
    scanf("%d %d %d", &x, &y, &dist);
    w[x][y] = dist;
  }

  // 입력받은 가중치 W 그래프 확인
  printf("\n==== W ====\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(w[i][j] == INF){ printf("   INF");}
      else{ printf("%5d ", w[i][j]);}
    }
    printf("\n");
  }
  printf("\n");

  // 플로이드 워셜 구현
  floyd (n, w, d, p);

  // path 경로 q, r 입력
  printf("INPUT 2 : \n");
  scanf("%d %d", &q, &r);

  // 경로 출력
  printf("\npath : v%d -> v%d\n", q, r);
  printf("v%d -> ( ", q);
  path(q, r);
  printf(") -> v%d\n", r);

  return 0;
}
