#include <iostream>
using namespace std;
// 알고리즘 2.2절, 2.3절

void merge(int h, int m, const int U[], const int V[], int S[]){

  int i = 0, j = 0, k = 0;
  while(i < h && j < m){
    if(U[i] < V[j]){
      S[k] = U[i];
      i++;
    }
    else{
      S[k] = V[j];
      j++;
    }
    k++;
  }

  if(i >= h){
    for (int p = j; p < m; p++) {
      S[k++] = V[p];
    }
  }
  else{
    for (int p = i; p < h; p++) {
      S[k++] = U[p];
    }
  }

}

void mergesort(int n, int S[]) {

  if(n > 1){
    const int h = n/2, m = n-h;
    int U[h], V[m];

    int idx = 0;
    for (int i = 0; i < h; i++) {
      U[i] = S[idx++];
    }
    for (int i = 0; i < m; i++) {
      V[i] = S[idx++];

    }

    mergesort(h, U);
    mergesort(m, V);

    merge(h, m, U, V, S);

  }

}

int main() {

  int S[7] = {27, 10, 12, 13, 15, 22, 1};
  mergesort(7, S);
  for (int i = 0; i < 7; i++) {
    printf("%d ", S[i]);
  }

  return 0;
}
