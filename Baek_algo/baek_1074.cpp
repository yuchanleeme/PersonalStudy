#include <iostream>
#include <cmath>
using namespace std;
// https://www.acmicpc.net/problem/1074

/*
<Z>
주요: 구하려하는 위치(r,c)가 어디있는지를 정확히 파악한다.
1. N값이 주어질 때 4^N개씩 각자의 4등분 칸에 들어간다 .(사분면)
2. 주어진 위치가 어디 칸에 속하는지 찾는다.(r,c)를 2^(N-1)로 나눈다. / 앞의 칸의 개수들 다 더한다.
3. 그 칸은 4^(N-1)개씩 4등분 된다.
4. 다시 주어진 위치가 어디 칸에 속하는지 찾는다. / 앞의 칸의 개수들 다 더한다.
5. 주어진 위치가 나올때까지 반복

* 편의상 1 | 2 로 사분면을 나눈다.
        ------
        3 | 4

*/
int find_z(int num, int row, int col){
  int sum = 0;
  int std_row = int(row/pow(2,num-1));
  int std_col = int(col/pow(2,num-1));

  while(num!=0){
    std_row = int(row/pow(2,num-1));
    std_col = int(col/pow(2,num-1));
    if(std_row == 0 && std_col == 0){
      //1번
      sum += 0;
    }
    else if(std_row == 0 && std_col == 1){
      //2번
      sum += 1 * pow(4,num-1); // 1번 더하기
    }
    else if(std_row == 1 && std_col == 0){
      //3번
      sum += 2 * pow(4,num-1); // 1,2번 더하기
    }
    else{
      //4번
      sum += 3 * pow(4,num-1); // 1,2,3번 더하기
    }
    row -= int(std_row * pow(2,num-1)); // 다음 사분면을 찾기 위해 row/col 값을 옮긴다.
    col -= int(std_col * pow(2,num-1));
    num--;
  }

  return sum;
}

int main() {

  int N,c,r;

  cin >> N >> c >> r;

  cout << find_z(N,c,r) << endl;

  return 0;
}
