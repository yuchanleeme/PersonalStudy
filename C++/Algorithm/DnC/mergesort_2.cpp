#include <iostream>
#include <cstring>
using namespace std;
// 알고리즘 2.4절, 2.5절

int S[] = {38,29,1,34,1,2,4,5,1,2,34,5,1};
void merge_2(int low, int mid, int high){

  int i, j, k;
  int U[high+1];
  i = low; j = mid+1; k = low;

  while (i <= mid && j <= high) {
    if(S[i] < S[j]){
      U[k] = S[i++];
    }
    else{
      U[k] = S[j++];
    }
    k++;
  }

  if(i > mid){
    for (int p = 0; k+p <= high ; p++) {
      U[k+p] = S[j+p];
    }
  }
  else{
    for (int p = 0; k+p <= high ; p++) {
      U[k+p] = S[i+p];
    }
  }

  for (int i = low; i <= high; i++) {
    S[i] = U[i];
  }
}

void mergesort_2(int low, int high) {

  int mid;
  if(low < high){
    mid = (low + high) / 2;
    mergesort_2(low, mid);
    mergesort_2(mid+1, high);
    merge_2(low, mid, high);
  }

}

int main() {

  mergesort_2(0,12);
  for (int i = 0; i < 13; i++) {
    printf("%d ", S[i]);
  }

  return 0;
}
