#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2292

/*
<벌집>
주요: 각 둘레 껍질에 해당하는 값들은 도달하는 최소 개수의 방의 값이 같다.
1. 각 값들이 둘레 껍질에 해당하는 조건을 구한다.
2. 그 조건을 만족할 때마다 방 개수값을 하나씩 더해준다.
3. 6의 제곱수가 계차인 계차수열임을 알 수 있다.

*/
int main() {

  int N;
  int bee_shell = 0 , count = 1;

  cin >> N;

  while(N!=1){
    bee_shell++;
    count += 6 * bee_shell;
    if(N <= count){
      break;
    }
  }

  cout << bee_shell+1 <<endl; // 마지막 자기 자신까지 더해준다.

  return 0;
}
