#include <iostream>
using namespace std;
// 알고리즘 2.6절, 2.7절

int s[7] = {5,21,52,7,23,6,2};

void partition(int low, int high, int &pivotpoint){

  int i,j;
  int pivotitem;

  pivotitem = s[low];
  j = low;

  for (int i = low+1; i <= high; i++) {
    if(s[i] < pivotitem){
      j++;
      int temp = s[j];
      s[j] = s[i];
      s[i] = temp;
    }
  }
  pivotpoint = j;
  int temp = s[pivotpoint];
  s[pivotpoint] = s[low];
  s[low] = temp;
}

void quicksort(int low, int high){
  int pivotpoint;

  if(high > low){
    partition(low, high, pivotpoint);
    quicksort(low, pivotpoint-1);
    quicksort(pivotpoint+1, high);
  }

}

int main() {
  quicksort(0,6);
  for (int i = 0; i < 7; i++) {
    printf("%d ", s[i] );
  }
  return 0;
}
