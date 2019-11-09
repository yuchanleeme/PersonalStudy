#include <iostream>
using namespace std;
// quicksort pivotpoint를 맨 마지막 원소로 했을 때

int s[8] = {15,22,13,27,32,10,20,25};

void partition(int low, int high, int &pivotpoint){

  int i,j;
  int pivotitem;

  pivotitem = s[high];
  j = low-1;

  for (int i = low; i < high; i++) {
    if(s[i] < pivotitem){
      j++;
      int temp = s[j];
      s[j] = s[i];
      s[i] = temp;
    }

  }
  pivotpoint = j+1;
  int temp = s[pivotpoint];
  s[pivotpoint] = s[high];
  s[high] = temp;
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
  quicksort(0,7);
  for (int i = 0; i < 8; i++) {
    printf("%d ", s[i] );
  }
  return 0;
}
