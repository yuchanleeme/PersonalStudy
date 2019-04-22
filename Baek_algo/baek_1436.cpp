#include <iostream>
#include <string>
using namespace std;

int main(){
  // https://www.acmicpc.net/problem/1436
  int N;
  int num = 0 ,check = 0;
  string temp_value_str;

  cin >> N ;

  while(true){
    num++;
    temp_value_str = to_string(num);

    if(temp_value_str.find("666")!= string::npos){
      check++;
    }
    if(check == N)
      break;
  }
  cout << num <<endl;

  return 0;
}
