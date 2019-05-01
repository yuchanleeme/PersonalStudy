#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/11718

/*
<그대로 출력하기>
주요: getline의 이해
1. string 값 text를 할당한다.
2. EOF 까지 계속 출력한다.

*/

int main() {

  string text;

  while (getline(cin,text)) {
    cout << text << endl;
  }

  return 0;
}
