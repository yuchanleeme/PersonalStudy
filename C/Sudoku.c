#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void madeSudoku();
bool checkMap(int,int,int);

int BaseMap[9][9];

int main() {
	srand(time(NULL));
	madeSudoku(); // making Sudoku
  return 0;
}

void madeSudoku(){

	int iRow,iCol,tempValue;
	int checkingTrigger = true;

	for(int iRow =0; iRow < 9; iRow++){
		//printf("<1>irow = %d, iCol= %d \n",iRow,iCol);
		for (int iCol = 0; iCol < 9; iCol++) {
			//printf("<2>irow = %d, iCol= %d \n",iRow,iCol);
			while(checkingTrigger == true){
				tempValue = rand()%9 +1;
				if(checkMap(iRow,iCol,tempValue) == true){
					BaseMap[iRow][iCol] = tempValue;
					break;
				}
			}
		}
	}


	for(int k=0; k<9 ;k++){ // 배열에 제대로 들어갔나 확인
		for(int l=0; l<9 ;l++){
		printf("%d ",BaseMap[k][l]);
		}
		printf("\n");
	}
}
bool checkMap(int row, int col, int value){

	for(int i = 0; i<9 ; i++){
		if(BaseMap[row][i] == value){
			return false;
		}
	}
	for(int j = 0; j<9 ; j++){
		if(BaseMap[j][col] == value){
			return false;
		}
	}
	int stdRow = (row/3)*3;
	int stdCol = (col/3)*3;
	for(int x = 0; x<3 ; x++){
		for(int y = 0; y<3 ; y++){
			if(BaseMap[stdRow+x][stdCol+y]==value){
				return false;
			}
		}
	}
	return true;
}
