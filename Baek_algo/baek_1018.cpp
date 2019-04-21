#include <iostream>

using namespace std;

int main(){
  //https://www.acmicpc.net/problem/1018
  char checking_white[8][8];
  char checking_black[8][8];

  int N,M;
  int count_b = 0;
  int count_w = 0;
  int count_res = 100;

  for (int i = 0 ; i < 8 ; i++){
    for (int j = 0; j < 8 ; j++){
      if( (i+j)%2 == 0){
        checking_white[i][j] = 'B';
      }
      else{
        checking_white[i][j] = 'W';
      }
    }
  } // checking_white 판 만들기
  for (int i = 0 ; i < 8 ; i++){
    for (int j = 0; j < 8 ; j++){
      if( (i+j)%2 == 0){
        checking_black[i][j] = 'W';
      }
      else{
        checking_black[i][j] = 'B';
      }
    }
  } // cehcking_blakc 판 만들기


  cin >> N >> M;

  char input_map[N][M];

  for(int i = 0; i<N ; i++){ // 맵 입력
     for(int j = 0; j<M; j++){
      cin >> input_map[i][j];
     }
   }
  for(int i = 0; i < N-7; i++){
     for (int j = 0; j < M-7; j++) {

       for(int x = 0 ; x < 8 ; x++){
         for(int y = 0; y < 8 ; y++){
           if(input_map[x+i][y+j]!=checking_black[x][y]){
             count_b++;
           }
           if(input_map[x+i][y+j]!=checking_white[x][y]){
             count_w++;
           }
         }
       }
       if(count_res > count_b){
         count_res = count_b;
       }
       if(count_res > count_w){
         count_res = count_w;
       }
       count_b = 0;
       count_w = 0;

     }
   }

  cout<<count_res<<endl;

  return 0;
}
