#include <iostream>
#include <vector>
using namespace std;
// 알고리즘 3.9절

const float INF = 2100000000;

void optsearchtree (int n, const vector<float> p, float& minavg, vector<vector<int> > &R){
  int i, j, k, diagonal;
  vector<vector<float> > A (n+2, vector<float>(n+1, INF)); // A 초기화

  for (i = 1; i <= n; i++) {
    A[i][i-1] = 0;
    A[i][i] = p[i];
    R[i][i] = i;
    R[i][i-1] = 0;
  }

  A[n+1][n] = 0;
  R[n+1][n] = 0;

  for (diagonal = 1; diagonal <= n-1; diagonal++) {
    for (i = 1; i <= n-diagonal; i++) {
      j = i + diagonal;
      float sum_per = 0;
      for (k = i; k <= j; k++) {
        float comp_value = A[i][k-1] + A[k+1][j];
        if(comp_value < A[i][j]){
          A[i][j] = comp_value;
          R[i][j] = k;
        }
        sum_per += p[k];
      }
      A[i][j] += sum_per;
    }
  }
  minavg = A[1][n];
}

int main(int argc, char const *argv[]) {

  // 원소의 개수 N 입력
  int N;
  printf("Input N : ");
  scanf("%d", &N);

  // p 입력 (p[i] 는 i째 원소를 찾을 확률)
  vector<float> p;
  p.push_back(0);
  printf("\nInput percentage : \n");
  for (int i = 0; i < N; i++) {
    float input;
    scanf("%f", &input);
    p.push_back(input);
  }

  float minavg;
  vector<vector<int> > R (N+2, vector<int>(N+1, 0));

  optsearchtree(N, p, minavg, R);

  printf("\nminavg : %.3f\n", minavg);

  printf("\n========== R ==========\n");
  for (int i = 1; i <= N+1; i++) {
    for (int j = 0; j <= N; j++) {
      if(i - j <= 1)
        printf("%3d ", R[i][j]);
      else{
        printf("    ");
      }
    }
    printf("\n");
  }
  return 0;
}
