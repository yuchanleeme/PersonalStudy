#include <iostream>
#include <vector>
using namespace std;
// 알고리즘 5.5절

int n, m;
vector<vector<int> > W;
vector<int> vcolor;

bool promising(int i){

  int j = 1;
  bool swichTrigger = true;
  while (j < i && swichTrigger) {
    if(W[i][j] && vcolor[i] == vcolor[j]){
      swichTrigger = false;
    }
    j++;
  }
  return swichTrigger;
}

void m_coloring(int i){

  int color;
  if(promising(i)){
    if(i == n){
      for (int i = 1; i <= n; i++) {
        cout << vcolor[i] << " ";
      }
      cout << "\n";
    }
    else{
      for (color = 1; color <= m; color++) {
        vcolor[i+1] = color;
        m_coloring(i+1);
      }
    }
  }

}

int main(int argc, char const *argv[]) {

  cout << "Input n m : ";
  cin >> n >> m;

  W = vector<vector<int> >(n+1, vector<int>(n+1, 0));
  vcolor = vector<int> (n+1, 0);

  int graph_line;
  cout << "\nInput graph_line number : \n";
  cin >> graph_line;

  cout << "\nInput graph_line Info : \n";
  cout << " ex) V3 --- V5 => 3 5 \n";

  for (int i = 0; i < graph_line; i++) {
    int x, y;
    cin >> x >> y;
    W[x][y] = true;
    W[y][x] = true; // 비방향이므로
  }

  printf("\nvcolor V%d ~ V%d: \n", 1, n);
  m_coloring(0);


  return 0;
}
