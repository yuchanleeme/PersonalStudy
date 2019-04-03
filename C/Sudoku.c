#include <stdio.h>										// 포인터를 사용하지 않고 만들기
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

int madeBaseSudoku();
bool checkBaseMap(int,int,int);
bool checkplayerMap(int,int,int);
void copyMap();
void makeGame();
void playingGame();
void inputNumber(char, char, char);
void inputMap();

int BaseMap[9][9];  // 답지 스도쿠
int gameMap[9][9];	// 구멍이 뚫려있는 복사본
int playerMap[9][9];// 플레이어의 답안지
int undoBuffer[5][3];

bool mapMakeflag = true; // madeBaseSudoku 함수를 실행시켜주기 위한 트리거
bool rsTrigger = true; // 리셋을 할때 필요한 트리거
bool gameTrigger = true; // 게임을 진행하기 위한 트리거
int undoCount = 0;
clock_t start, end;

int main() {
	srand(time(NULL));
	while (gameTrigger){
		while(rsTrigger){
			while(mapMakeflag){
				madeBaseSudoku();// making Sudoku
			}
			copyMap();
			makeGame();
			rsTrigger = false;
		}


		for(int k=0; k<9 ;k++){ // 배열에 제대로 들어갔나 확인
		for(int l=0; l<9 ;l++){
				printf("%d ",BaseMap[k][l]);
			}
			printf("\n");
		}
		printf("===========================\n");
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

	}
	return 0;
}


int madeBaseSudoku(){ // BaseMap 을 만드는 함수
	for(int iRow =0; iRow < 9; iRow++){
		for (int iCol = 0; iCol < 9; iCol++) {
			if(BaseMap[iRow][iCol]==0)
			{
				for(int temp = 1; temp < 10; temp++){
					if(checkBaseMap(iRow,iCol,temp) == true){
						mapMakeflag = false;
						break;
					}
					if(temp==9)	{
						mapMakeflag = true;
						for(int resetNum_A = 0; resetNum_A<9 ; resetNum_A++){
							for(int resetNum_B = 0; resetNum_B<9; resetNum_B++){
								BaseMap[resetNum_A][resetNum_B]=0;
							}
						}
						return 0;
						}
				}
				int tempValue = rand()%9 +1;
				if(checkBaseMap(iRow,iCol,tempValue) == true){
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

bool checkBaseMap(int row, int col, int value){ // 전해받은 row,col 자리 배열에 value값이
																						// 들어가도 괜찮은지 확인하는 함수
	for(int i = 0; i<9 ; i++){
		if(BaseMap[row][i] == value){
			//printf("BaseMap[row(%d)][i(%d)] == value(%d)\n",row,i,value);
			return false;
		}
	}
	for(int j = 0; j<9 ; j++){
		if(BaseMap[j][col] == value){
			//printf("BaseMap[j(%d)][col(%d)] == value(%d)\n",j,col,value);
			return false;
		}
	}
	int stdRow = (row/3)*3;
	int stdCol = (col/3)*3;
	for(int x = 0; x<3 ; x++){
		for(int y = 0; y<3 ; y++){
			if(BaseMap[stdRow+x][stdCol+y]==value){
				//printf("BaseMap[stdRow+x(%d)][stdCol+y(%d)] == value(%d)\n",stdRow+x,stdCol+y,value);
				return false;
			}
		}
	}
	return true;
}

bool checkPlayerMap(int row, int col, int value){ // 전해받은 row,col 자리 배열에 value값이
																						// 들어가도 괜찮은지 확인하는 함수
	for(int i = 0; i<9 ; i++){
		if(playerMap[row][i] == value){
			//printf("BaseMap[row(%d)][i(%d)] == value(%d)\n",row,i,value);
			return false;
		}
	}
	for(int j = 0; j<9 ; j++){
		if(playerMap[j][col] == value){
			//printf("BaseMap[j(%d)][col(%d)] == value(%d)\n",j,col,value);
			return false;
		}
	}
	int stdRow = (row/3)*3;
	int stdCol = (col/3)*3;
	for(int x = 0; x<3 ; x++){
		for(int y = 0; y<3 ; y++){
			if(playerMap[stdRow+x][stdCol+y]==value){
				//printf("BaseMap[stdRow+x(%d)][stdCol+y(%d)] == value(%d)\n",stdRow+x,stdCol+y,value);
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
	printf("INPUT> ");
	gets(input);

	for (int k = 0; k < 5; k++) {
		printf("'%c'",input[k]);
	}
	printf("\n");

	if(input[0] >= 48 && input[0] <= 57){						// 행, 열 , 숫자 입력받음
		inputNumber(input[0],input[2],input[4]);
		//printf("123\n");
	}
	else if (input[0] == 'v' ||input[0] == 'V') {   // 스도쿠 조건에 맞는지 확인
		int temp;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if(gameMap[i][j]!=playerMap[i][j]){
					temp = playerMap[i][j];
					playerMap[i][j] = 0;
					if(checkPlayerMap(i,j,temp)==false){
							playerMap[i][j] = temp;
							printf("***(%d,%d) is wrong answer\n",i+1,j+1);
						return ;
					}
					playerMap[i][j] = temp;
				}
			}
		}
	}
	else if (input[0] == 'i' ||input[0] == 'I') {
		inputMap();
		rsTrigger = true;
		mapMakeflag = true;
		printf("ii\n");
	}
	else if (input[0] == 'a' ||input[0] == 'A') {		// 현 게임을 다시 시작함
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				playerMap[i][j]=gameMap[i][j];
			}
		}
		printf("aa\n");
	}
	else if (input[0] == 'u' ||input[0] == 'U') {
		printf("u\n");
	}
	else if (input[0] == 'n' ||input[0] == 'N') {
		rsTrigger = true;
		mapMakeflag = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				BaseMap[i][j]=0;
			}
		}
		printf("nn\n");
	} // 새로운 게임을 만드는 함수
	else if (input[0] == 'r' ||input[0] == 'R') {
		printf("rr\n");
	}
	else if (input[0] == 'h' ||input[0] == 'H') {
		printf("hh\n");
	}
	else if (input[0] == 'q' ||input[0] == 'Q') {
		gameTrigger = false;
		printf("qq\n");
	}
	else{
		printf("wrong\n");
	}

}

void inputNumber(char row, char col, char value){
	//printf("row : %d col :%d value: %d\n",row, col, value);
	if(playerMap[row-49][col-49]==0 || gameMap[row-49][col-49] == 0){
		playerMap[row-49][col-49]=value-48;
	}
	else{
		printf("Wrong input!\n");
	}

}

void inputMap(){
	int count = 9;
	int temp[9][9];

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			scanf("%d",&temp[i][j]);
		}
	}

	for (int k = 0; k < count; k++) {
		for (int l = 0; l < count; l++) {
			BaseMap[k][l] = temp[k][l];
		}
	}
}
