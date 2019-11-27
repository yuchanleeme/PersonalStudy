#include <iostream>
#include <vector>
using namespace std;

const int INF = 2100000000;

typedef struct Edge{

  int vx;
  int vy;
  int weight;

}edge;

void dijkstra(int n, const vector<vector<int> > W, vector<edge> &F){

  int i, vnear;
  vector<int> touch(n+1, 0);
  vector<int> length(n+1, 0);
  edge e;

  for (i = 2; i <= n; i++) {
    touch[i] = 1;
    length[i] = W[1][i];
  }

  int case_time = 0;
  while (case_time != n-1) {
    case_time++;
    int min = INF;
    for (i = 2; i <= n; i++) {
      if(0 <= length[i] && length[i] <= min){
        min = length[i];
        vnear = i;
      }
    }

    e.vx = touch[vnear];
    e.vy = vnear;
    e.weight = W[e.vx][e.vy];

    F.push_back(e);

    for (i = 2; i <= n; i++) {
      if(length[vnear] + W[vnear][i] < length[i]){
        length[i] = length[vnear] + W[vnear][i];
        touch[i] = vnear;
      }
    }
    length[vnear] = -1;
  }
}

int main(int argc, char const *argv[]) {

  int n, m;
  printf("Input N, M : ");
  scanf("%d %d", &n, &m);

  vector<vector<int> > W(n+1, vector<int>(n+1, INF));
  vector<edge> F;

  printf("\nInput Edge info : \n");
  printf(" Ex) V3 -> V4 : 5(weigth) -> 3 4 5\n");

  for (int i = 0; i < m; i++) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    W[x][y] = w;
  }

  dijkstra(n, W, F);

  printf("\nset_of_edges F : \n");
  for (int i = 0; i < F.size(); i++) {
    printf("V%d ----> V%d , weight : %d\n", F[i].vx, F[i].vy, F[i].weight);
  }

  return 0;
}
