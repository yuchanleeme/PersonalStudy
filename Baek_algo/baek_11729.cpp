#include <iostream>
#include <cmath>
using namespace std;

/*
<하노이탑 알고리즘>
주요: n 개의 원반을 from 에서 to로 by를 이용하여 옮긴다.
1. 시작장대(from)에 있는 n-1개의 원반을 보조장대(by) 에 옮긴다.   => 이 시행에서는 to가 보조가 되어버림
2. 시작장대(from)에 1개남은 원반을 목표장대(to)로 옮긴다.
3. 보조장대(by)에 있는 n-1개 원판을 목표장대(to)로 옮긴다.       => 이 시행에서는 from이 보조가 되어버림

hanoi 함수는 (원반의 개수(n), 시작(from), 보조(by), 목표(to)) 를 인자로 받는다.
=> 재귀함수를 진행하면서 시작,보조,목표는 각각 상황에 맞게 달라질 수 있다.
=> 1,2번을 진행하고 3번을 진행 할 때 시작,보조,목표 장대만 달라졌지 주요 알고리즘과 똑같다는 것을 생각해야한다.
  (ex. n=3에서 1,2번을 진행하면 (0 - 1/2 - 3 ) 이 구조인데 3이 없다고 가정하면
  다음 알고리즘은 가운데 장대를 3이 있던 장대를 보조해서 0이 있는 장대로 옮기는 것과 같다.)
*/
void hanoi(int n, int from, int by, int to){

  if(n==1){
    cout << from <<" "<<to<<endl;
  }
  else{
    hanoi(n-1,from,to,by);
    cout << from <<" "<<to<<endl;
    hanoi(n-1,by,from,to);
  }
}

int main() {

  int N;

  cin >> N;
  cout << pow(2,N) -1 <<endl;
  hanoi(N,1,2,3);

  return 0;
}
