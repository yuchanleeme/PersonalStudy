#include <iostream>

using namespace std;

int main(){
  char checking_white[8][8];
  char checking_black[8][8];

  int N,M;


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
  char

  for(int i = 0; i<N ; i++){ // 맵 입력
     for(int j = 0; j<M; j++){
      cin >> input_map[i][j];
     }
   }

  for()

  for(int i = 0; i<N ; i++){
       for(int j = 0; j<M; j++){
         cout<<input_map[i][j]<<" ";
       }
       cout<<endl;
  }
  return 0;
}
