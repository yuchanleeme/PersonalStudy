#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int madeBaseSudoku();
bool checkMap(int,int,int);
void copyMap();
void makeGame();

int BaseMap[9][9];
int gameMap[9][9];
int playerMap[9][9];

bool flag = true;

int main() {
	srand(time(NULL));

	while(flag){
		madeBaseSudoku();// making Sudoku
	}
	copyMap();
	makeGame();


	for(int k=0; k<9 ;k++){ // 배열에 제대로 들어갔나 확인
		for(int l=0; l<9 ;l++){
		printf("%d ",BaseMap[k][l]);
		}
		printf("\n");
	}
printf("===========================\n");

	for(int k=0; k<9 ;k++){ // 배열에 제대로 들어갔나 확인
		for(int l=0; l<9 ;l++){
		printf("%d ",playerMap[k][l]);
		}
		printf("\n");
	}
  return 0;
}

int madeBaseSudoku(){ // BaseMap 을 만드는 함수
//printf("<5>iRow = %d, iCol= %d ,tempValue = %d\n",iRow,iCol,tempValue);

	for(int iRow =0; iRow < 9; iRow++){
	//	printf("iRow= %d \n", iRow );
		for (int iCol = 0; iCol < 9; iCol++) {
		//	printf("irow = %d iCol= %d \n", iRow,iCol);
			if(BaseMap[iRow][iCol]==0)
			{

				for(int temp = 1; temp < 10; temp++){
					if(checkMap(iRow,iCol,temp) == true){
						flag = false;
					//	printf("111111111111111111111111111111111111111111111\n");
						break;
					}
					if(temp==9)	{
						//printf("2222222222222222222222222222222222222222222222\n");
						flag = true;
						for(int resetNum_A = 0; resetNum_A<9 ; resetNum_A++){
							for(int resetNum_B = 0; resetNum_B<9; resetNum_B++){
								BaseMap[resetNum_A][resetNum_B]=0;
							}
						}
						return 0;
						}
				}
				//printf("3333333333333333333333333333333333333333333333\n");
				int tempValue = rand()%9 +1;
			//	printf("irow = %d iCol= %d tempValue = %d \n", iRow,iCol,tempValue);
				if(checkMap(iRow,iCol,tempValue) == true){
					BaseMap[iRow][iCol] = tempValue;
				//	printf("=====================BaseMap[%d][%d] = %d\n",iRow,iCol,BaseMap[iRow][iCol] );
				}
				else{
					iCol--;
				}
			}
		}
	}
	return 1;
}

bool checkMap(int row, int col, int value){ // 전해받은 row,col 자리 배열에 value값이
																						// 들어가도 괜찮은지 확인하는 함수
	for(int i = 0; i<9 ; i++){
		if(BaseMap[row][i] == value){
		//	printf("BaseMap[row(%d)][i(%d)] == value(%d)\n",row,i,value);
			return false;
		}
	}
	for(int j = 0; j<9 ; j++){
		if(BaseMap[j][col] == value){
		//	printf("BaseMap[j(%d)][col(%d)] == value(%d)\n",j,col,value);
			return false;
		}
	}
	int stdRow = (row/3)*3;
	int stdCol = (col/3)*3;
	for(int x = 0; x<3 ; x++){
		for(int y = 0; y<3 ; y++){
			if(BaseMap[stdRow+x][stdCol+y]==value){
			//	printf("BaseMap[stdRow+x(%d)][stdCol+y(%d)] == value(%d)\n",stdRow+x,stdCol+y,value);
				return false;
			}
		}
	}
	return true;
}

void copyMap(){
	for (int i=0; i<9 ; i++){
		for(int j=0; j<9 ; j++){
			gameMap[i][j] = BaseMap[i][j];
		}
	}
}

void makeGame(){

	int randRow, randCol;

	for(int countHole = 0 ; countHole <40;){
		randRow = rand()%9+1;
		randCol = rand()%9+1;
		if(gameMap[randRow][randCol]!=0)
		{
			gameMap[randRow][randCol] = 0;
			countHole++;
		}
	}

	for (int i=0; i<9 ; i++){
		for(int j=0; j<9 ; j++){
			playerMap[i][j] = gameMap[i][j];
		}
	}
}
