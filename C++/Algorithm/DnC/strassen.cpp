#include <iostream>
#include <vector>
using namespace std;
// 알고리즘 2.8절
// 슈트라센 알고리즘 - 행렬곱 알고리즘

// 일반 행렬 곱
void standardMul(int n, vector<int> a[], vector<int> b[], vector<int> c[]){

  int i, j, k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }

}

// 두 행렬 더하기
void sumM(int n, vector<int> x[], vector<int> y[], vector<int> res[]){

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = x[i][j] + y[i][j];
    }
  }

}

// 두 행렬 뺄셈
void subM(int n, vector<int> x[], vector<int> y[], vector<int> res[]){

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = x[i][j] - y[i][j];
    }
  }

}

// 각 부분행렬 분할
void partitionCal(int n, int minI, int maxI, int minJ, int maxJ, vector<int> s[],  vector<int> divide_s[]){

  int idx = 0;
  for (int i = minI; i < maxI; i++) {
    for (int j = minJ; j < maxJ; j++) {
      divide_s[idx].push_back(s[i][j]);
    }
    idx++;
  }

}

// 원 행렬을 4분할해서 저장
void partition(int n, vector<int> s[], vector<int> s11[], vector<int> s12[], vector<int> s21[], vector<int> s22[]) {

  partitionCal(n, 0, n/2, 0, n/2, s, s11);
  partitionCal(n, 0, n/2, n/2, n, s, s12);
  partitionCal(n, n/2, n, 0, n/2, s, s21);
  partitionCal(n, n/2, n, n/2, n, s, s22);

}

// 각 부분행렬 합치기
void mergeCal(int n, int minI, int maxI, int minJ, int maxJ, vector<int> s[],  vector<int> divide_s[]){

  int idx_x = 0, idx_y = 0;
  for (int i = minI; i < maxI; i++) {
    idx_y = 0;
    for (int j = minJ; j < maxJ; j++) {
      s[i][j] = divide_s[idx_x][idx_y++];
    }
    idx_x++;
  }

}

// 계산된 행렬 원행렬로 합치기
void mergeRes(int n, vector<int> s[], vector<int> s11[], vector<int> s12[], vector<int> s21[], vector<int> s22[]) {

  mergeCal(n, 0, n/2, 0, n/2, s, s11);
  mergeCal(n, 0, n/2, n/2, n, s, s12);
  mergeCal(n, n/2, n, 0, n/2, s, s21);
  mergeCal(n, n/2, n, n/2, n, s, s22);

}

// 슈트라센 행렬 곱셈
void strassen (int n, vector<int> a[], vector<int> b[], vector<int> c[]){

  int threshold = 1;

  if(n <= threshold){
    standardMul(n, a, b, c);
  }
  else{
    vector<int> a11[n/2], a12[n/2], a21[n/2], a22[n/2];
    vector<int> b11[n/2], b12[n/2], b21[n/2], b22[n/2];
    vector<int> c11[n/2], c12[n/2], c21[n/2], c22[n/2];
    vector<int> m1[n/2], m2[n/2], m3[n/2], m4[n/2], m5[n/2], m6[n/2], m7[n/2];

    partition(n, a, a11, a12, a21, a22);
    partition(n, b, b11, b12, b21, b22);
    partition(n, c, c11, c12, c21, c22);

    // resX, resY, m1~m7 초기화
    vector<int> resX[n/2], resY[n/2];
    for (int i = 0; i < n/2; i++) {
      for (int j = 0; j < n/2; j++) {
        resX[i].push_back(0);
        resY[i].push_back(0);
        m1[i].push_back(0);
        m2[i].push_back(0);
        m3[i].push_back(0);
        m4[i].push_back(0);
        m5[i].push_back(0);
        m6[i].push_back(0);
        m7[i].push_back(0);
      }
    }

    // m1~m7 계산
    sumM(n/2, a11, a22, resX); // a11 + a22
    sumM(n/2, b11, b22, resY); // b11 + b22
    strassen(n/2, resX, resY, m1);

    sumM(n/2, a21, a22, resX); // a21 + a22
    strassen(n/2, resX, b11, m2);

    subM(n/2, b12, b22, resY); // b12 + b22
    strassen(n/2, a11, resY, m3);

    subM(n/2, b21, b11, resY); // b21 + b11
    strassen(n/2, a22, resY, m4);

    sumM(n/2, a11, a12, resX); // a11 + a12
    strassen(n/2, resX, b22, m5);

    subM(n/2, a21, a11, resX); // a21 - a11
    sumM(n/2, b11, b12, resY); // b11 + b12
    strassen(n/2, resX, resY, m6);

    subM(n/2, a12, a22, resX); // a12 - a22
    sumM(n/2, b21, b22, resY); // b21 + b22
    strassen(n/2, resX, resY, m7);

    // c11 ~ c22 값 계산
    //(m1+m4) - (m5-m7)
    sumM(n/2, m1, m4, resX);
    subM(n/2, m5, m7, resY);
    subM(n/2, resX, resY, c11);

    sumM(n/2, m3, m5, c12);

    sumM(n/2, m2, m4, c21);

    //(m1+m3) - (m2-m6)
    sumM(n/2, m1, m3, resX);
    subM(n/2, m2, m6, resY);
    subM(n/2, resX, resY, c22);

    // c11~ c22 값 합침
    mergeRes(n, c, c11, c12, c21, c22);

  }
}

int main() {

  int n;
  printf("Input N : ");
  scanf("%d", &n);

  vector<int> a[n];
  vector<int> b[n];
  vector<int> c[n];

  printf("\nInput A :\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int input;
      scanf("%d", &input);
      a[i].push_back(input);
    }
  }

  printf("\nInput B :\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int input;
      scanf("%d", &input);
      b[i].push_back(input);
      c[i].push_back(0); // c 값 0으로 초기화
    }
  }

  strassen(n, a, b, c);

  printf("\nres C :\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}
