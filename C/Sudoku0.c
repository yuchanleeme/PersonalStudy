#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_std(int *arr, int num){ // 대표 값 셔플 함수
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

void shuffle_tmp(int *arr, int num){
	int temp =0;
	temp = arr[num];
	arr[num] = arr[num+1];
	arr[num+1] =temp;
}

int checkColumn(int (*arr_bs)[9],int *arr_std,int num_1,int num_2){	// 같은 열에 같은 숫자가 있는지 비교
  															// 같은 거 있으면 0리턴
	printf("<0> num_1==%d,num2==%d\n", num_1 , num_2 );
	for(int i=0; i<num_1; i++){
		//printf("<1> i ==%d,num2==%d\n", i , num_2 )
			if(arr_std[num_2]==arr_bs[i][num_2]){
				printf("<2> arr_std[%d]==%d, arr[%d][%d]==%d\n",num_2, arr_std[num_2] , i,num_2,arr_bs[i][num_2] );
				return 0;
			}
	}
	return 1;
}

void madeSudoku(){
	int BaseMap[9][9]; // 본판 맵
	int StandardNumber[9] = {1,2,3,4,5,6,7,8,9}; // 대표 값을 가진 배열
	int checkingTrigger = 0;
	int some;


				for(int i=0; i<9 ;i++){// 대표 배열을 셔플해서 값들을 본판 맵에 집어 넣음
					//printf("? i : %d \n",i );
					//if(checkingTrigger==1){
					//	printf("! i : %d \n",i );
					//	i--;
					//	printf("!? i : %d \n",i );
					//	checkingTrigger==0;
				//	//	for(int l =0; l<9 ;l++){
					//		BaseMap[i][l] = 0;
					//	}
					//}
					shuffle_std(StandardNumber,9);
						for(int k =0; k <9;k++){
							printf("%d ",StandardNumber[k]);
							}
							printf("\n");

							for(int j=0; j<9 ; j++){
								//printf("checkColumn = %d\n", checkColumn(BaseMap,i,j));
								if(checkColumn(BaseMap,StandardNumber,i,j)==0){
									if(j!=8)
										shuffle_tmp(StandardNumber,j);
									else
										checkingTrigger = 1;
									}
							BaseMap[i][j] = StandardNumber[j];
						}
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
