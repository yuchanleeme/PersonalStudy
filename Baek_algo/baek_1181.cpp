#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/1181

/*
<단어 정렬>
주요: 구조체를 이용해 비교한다.
1. 단어 길이와 단어를 멤버로 갖는 구조체를 선언한다.
2. 구조체 배열을 이용해 각 멤버를 저장한다.
3. sort 함수를 이용해 정렬한다. (조건에 맞게)
4. 다음 배열의 값과 같지 않을때만 출력하게 한다.

*/

// Word 구조체
typedef struct Word {
  int length;
  string str;
} Word;

// sort을 위한 compare 함수
bool compare(const Word &a, const Word &b){
  if(a.length == b.length){
    if(a.str.compare(b.str) < 0){ // 사전적으로 a가 b 앞
      return true;
    }
    else{
      return false;
    }
  }
  return a.length < b.length;
}

int main() {

  cin.tie(0);

  int N;
  cin >> N;

  Word words[N];

  // 값 입력
  for (int i = 0; i < N; i++) {
    cin >> words[i].str;
    words[i].length = words[i].str.length();
  }

  // 정렬
  sort(words, words+N, compare);

  // 출력
  for (int i = 0; i < N; i++) {
    if(words[i].str != words[i+1].str)
      cout << words[i].str << endl;
  }

  return 0;
}
