#include <iostream>
#include <vector>
using namespace std;
const int INF = 2100000000;

vector<vector<int> > p;

void order (int i, int j){

  if(i == j) cout << "A" << i;
  else{
    int k = p[i][j];
    cout << "(";
    order(i, k);
    order(k+1, j);
    cout << ")";
  }
}

int minmult(int n, const vector<int> d, vector<vector<int> > &p){

  int res;
  int i, j , k, diagonal;
  vector<vector<int> > M(n+1, vector<int>(n+1, INF)); // 아직 값 할당이 안된 부분은 INF 처리

  for (i = 1; i <= n; i++) {
    M[i][i] = 0;
  }

  for (diagonal = 1; diagonal <= n-1; diagonal++) {
    for (i = 1; i <= n - diagonal; i++) {
      j = i + diagonal;
      for (k = i; k <= j-1 ; k++) {
        int comp_value = M[i][k] + M[k+1][j] + d[i-1] *d[k] *d[j];
        if(comp_value < M[i][j]){
          M[i][j] = comp_value;
          p[i][j] = k;
        }
      }
    }
  }
  return M[1][n];
}

int main(int argc, char const *argv[]) {

  int N;
  printf("Input Matrix Number : ");
  scanf("%d", &N);

  vector<int> mat_intfo; // 행렬 열의 정보를 입력받는 배열
  p = vector<vector<int> >(N+1, vector<int>(N+1,0)); // order 저장 배열

  // 행렬 A x B 의 B값 저장 , 단 첫 행렬은 A,B 값 저장
  // 차례대로 곱셈을 할 수 있게 행렬 값 A, B가 무조건 주어진다고 가정
  printf("\nInput Matix Info : ");
  printf("\n ex) 2 X 3 => 2 3\n");
  for (int i = 0; i < N; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    if(i == 0){ mat_intfo.push_back(A);}
    mat_intfo.push_back(B);
  }

  // 연쇄 행렬 최소곱 계산
  int min_ans = minmult(N, mat_intfo, p);
  printf("\nMin Ans : %d\n", min_ans);

  // 최소곱의 최적 순서 출력
  printf("\nMin Optimal Order : ");
  order(1, N);
  printf("\n");

  return 0;
}
