#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

int madeBaseSudoku();
bool checkMap(int,int,int);
void copyMap();
void makeGame();
void playingGame();
void inputNumber(char, char, char);

int BaseMap[9][9];
int gameMap[9][9];
int playerMap[9][9];
int undoBuffer[5][3];

bool flag = true;
int undoCount = 0;

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
	while(1){
	for(int k=0; k<9 ;k++){ // 배열에 제대로 들어갔나 확인
		for(int l=0; l<9 ;l++){
			if(playerMap[k][l]==0){
				printf(". ");
			}
			else{
				printf("%d ",playerMap[k][l]);
			}
		}
		printf("\n");
	}
	printf("===========================\n");
	playingGame();
	system("cls");
	}
  return 0;
}

int madeBaseSudoku(){ // BaseMap 을 만드는 함수
	for(int iRow =0; iRow < 9; iRow++){
		for (int iCol = 0; iCol < 9; iCol++) {
			if(BaseMap[iRow][iCol]==0)
			{

				for(int temp = 1; temp < 10; temp++){
					if(checkMap(iRow,iCol,temp) == true){
						flag = false;
						break;
					}
					if(temp==9)	{
						flag = true;
						for(int resetNum_A = 0; resetNum_A<9 ; resetNum_A++){
							for(int resetNum_B = 0; resetNum_B<9; resetNum_B++){
								BaseMap[resetNum_A][resetNum_B]=0;
							}
						}
						return 0;
						}
				}
				int tempValue = rand()%9 +1;
				if(checkMap(iRow,iCol,tempValue) == true){
					BaseMap[iRow][iCol] = tempValue;
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

void playingGame(){


	char input[5];
	gets(input);

	printf("INPUT > ");

	if(input[0] > 48 && input[0] <= 57){
		inputNumber(input[0],input[2],input[4]);
		//printf("123\n");
	}
	else if (input[0] == 'v' ||input[0] == 'V') {

	}
	else if (input[0] == 'i' ||input[0] == 'I') {
		printf("ii\n");
	}
	else if (input[0] == 'a' ||input[0] == 'A') {
		printf("aa\n");
	}
	else if (input[0] == 'u' ||input[0] == 'U') {
		printf("u\n");
	}
	else if (input[0] == 'n' ||input[0] == 'N') {
		printf("nn\n");
	}
	else if (input[0] == 'r' ||input[0] == 'R') {
		printf("rr\n");
	}
	else if (input[0] == 'h' ||input[0] == 'H') {
		printf("hh\n");
	}
	else if (input[0] == 'q' ||input[0] == 'Q') {
		printf("qq\n");
	}
	else{
		printf("wrong\n");
	}

}

void inputNumber(char row, char col, char value){
	//printf("row : %d col :%d value: %d\n",row, col, value);
	if(playerMap[row-49][col-49]==0){
		playerMap[row-49][col-49]=value-48;

	}
	else{
		printf("Wrong input!\n");
	}

}
