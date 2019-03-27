#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int num){ // 대표 값 셔플 함수
	int temp = 0 ;
	int randomNum = 0;
	for(int i=0; i< num-1; i++)
	{
		randomNum = rand()%9;
		temp = arr[i];
		arr[i] =arr[randomNum];
		arr[randomNum] =temp;
	}
}

int checkColumn(int (*arr)[9]){
	int res = 0;
	for(int i=0; i<9;i++){
		for(int j=0; j<9;j++){
			for(int k=1; j+k<10;k++){
				if (arr[j][i]==arr[j+k][i]) {
					//printf("arr[%d][%d]==arr[%d][%d]\n",j,i,j+k,i);
					return res;
				}
			}
		}
	}
	return res;
}

void madeSudoku(){
	int BaseMap[9][9]; // 본판 맵
	int StandardNumber[9] = {1,2,3,4,5,6,7,8,9}; // 대표 값을 가진 배열
	int checkingTrigger = 0;

		while(true){
			if(checkingTrigger==0){
				for(int i=0; i<9 ;i++){  // 대표 배열을 셔플해서 값들을 본판 맵에 집어 넣음
					shuffle(StandardNumber,9);
					for(int j=0; j<9 ; j++){
						BaseMap[i][j] = StandardNumber[j];
						}
					}
					checkingTrigger = checkColumn(BaseMap);
			}
			else
				break;
		}

		for(int k=0; k<9 ;k++){ // 배열에 제대로 들어갔나 확인
			for(int l=0; l<9 ;l++){
			printf("%d ",BaseMap[k][l]);
			}
  		printf("\n");
		}
}

int main() {
	srand(time(NULL));
	madeSudoku(); // making Sudoku
  return 0;
}