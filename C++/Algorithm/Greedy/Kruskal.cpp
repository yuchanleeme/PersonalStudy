#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 알고리즘 4.2절

int n, m;
typedef int index;
typedef index set_pointer;

// nodetype
struct nodetype
{
  index parent;
  int depth;
};

// Edge의 정보 Vx -> Vy (weight)
typedef struct Edge
{
  int vx;
  int vy;
  int weight;
} edge;

// 전체집합 U
typedef nodetype *universe;
universe U;

// 처음 트리 set 만들 때 필요
void makeset (index i){
  U[i].parent = i;
  U[i].depth = 0;
};

set_pointer find(index i){
  index j;
  j = i;
  while(U[j].parent != j){
    j = U[j].parent;
  }
  return j;
}

// 서로소 집합 합병 함수
void merge(set_pointer p, set_pointer q){
  if(U[p].depth == U[q].depth){
    U[p].depth += 1;
    U[q].parent = p;
  }
  else if(U[p].depth < U[q].depth){
    U[p].parent = q;
  }
  else{
    U[q].parent = p;
  }
}

bool equal (set_pointer p ,set_pointer q){
  if(p == q){
    return true;
  }
  else{
    return false;
  }
}

void initial (int n){
  index i;
  for (i = 0; i <= n; i++) {
    makeset(i);
  }
}

// sort 함수를 위한 comp 함수
bool comp(const Edge& x, const Edge& y){
  return x.weight < y.weight;
}

// kruskal 알고리즘
void kruskal(int n, int m, vector<edge> E, vector<edge> &F){

  int i, j;
  set_pointer p , q;
  edge e;

  sort(E.begin(),E.end(),comp);

  initial(n);
  int e_num = 0; // E의 idx
  while (F.size() < n-1) {
    e = E[e_num++];
    i = e.vx;
    j = e.vy;
    p = find(i);
    q = find(j);
    if(!equal(p,q)){
      merge(p,q);
      F.push_back(e);
    }
  }
}

int main(int argc, char const *argv[]) {

  printf("Input N M : ");
  scanf("%d %d", &n, &m);

  U = (struct nodetype *)malloc(sizeof(struct nodetype) * (n+1)); // U의 구조체 배열 만들기

  vector<edge> E;
  vector<edge> F;

  printf("\nInput Edge Info : ");
  printf("\n ex) V2 -> V3  //  w:(5) => 2 3 5\n");
  for (int i = 0; i < m; i++) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    E.push_back({x,y,w});
  }

  kruskal(n, m, E, F);

  printf("\nset_of_edges F : \n");
  for (int i = 0; i < F.size(); i++) {
    printf("V%d ----  V%d , weight: %d\n", F[i].vx , F[i].vy, F[i].weight);
  }

  return 0;
}
