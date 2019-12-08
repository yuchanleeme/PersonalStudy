#include <iostream>
#include <vector>
using namespace std;
// 알고리즘  5.6절

void hamiltonian(int);
bool promising(int);

int n , m;
vector<vector<int> > W;
vector<int> vindex;

void hamiltonian(int i){

  int j;

  if(promising(i)){
    if(i == n-1){
      for (int k = 0; k <= n-1; k++) {
        cout << vindex[k] << " ";
      }
      cout << "\n";
    }
    else{
      for (j = 2; j <= n; j++) {
        vindex[i+1] = j;
        hamiltonian(i+1);
      }
    }
  }
}

bool promising(int i){

  int j;
  bool switchTrigger;

  if(i == n-1 && !W[vindex[n-1]][vindex[0]]){
    switchTrigger = false;
  }
  else if(i > 0 && !W[vindex[i-1]][vindex[i]]){
    switchTrigger = false;
  }
  else{
    switchTrigger = true;
    j = 1;
    while(j < i && switchTrigger){
      if(vindex[i] == vindex[j]){
        switchTrigger = false;
      }
      j++;
    }
  }

  return switchTrigger;
}

int main(int argc, char const *argv[]) {

  cout << "Input n m : ";
  cin >> n >> m;

  W = vector<vector<int> > (n+1, vector<int>(n+1, 0));
  vindex = vector<int>(n+1, 0);

  cout << "\n" << "Input graph info : " << "\n";
  cout << " ex) V3 --- V5 : 3 5" << "\n";
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    W[x][y] = 1;
    W[y][x] = 1; // 비방향
  }

  cout << "\n" << "print Hamiltonian Circuits : " << "\n";
  vindex[0] = 1;
  hamiltonian(0);

  return 0;
}
