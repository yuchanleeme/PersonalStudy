#include <iostream>
#include <vector>
using namespace std;
// 알고리즘  5.4절

int n , W, total = 0;
vector<string> include;
vector<int> w;

bool promising(int i, int weight, int total){

  return (weight + total >= W) && (weight == W || weight + w[i+1] <= W);
}

void sum_of_subsets(int i, int weight, int total){

  if(promising(i, weight, total)){
    if(weight == W){
      cout << "\nInteger combination : \n";
      for (int k = 1; k <= n ; k++) {
        cout << include[k] << " ";
      }
      cout << "\n=> ";
      for (int k = 1; k <= n ; k++) {
        if(include[k] == "yes")
        {
          cout << w[k] << " ";
        }
      }
      cout << "\n";
    }
    else{
      include[i+1] = "yes";
      sum_of_subsets(i+1, weight + w[i+1], total - w[i+1]);
      include[i+1] = "no";
      sum_of_subsets(i+1, weight, total - w[i+1]);
    }
  }
}

int main(int argc, char const *argv[]) {

  cout << "Input N : ";
  cin >> n;

  include = vector<string>(n+1);
  w = vector<int>(n+1);

  cout << "\n" <<"Input weight : ";
  for (int i = 1; i <=n; i++) {
    cin >> w[i];
    total += w[i];
  }

  cout << "\n" <<"Input W : ";
  cin >> W;

  sum_of_subsets(0, 0, total);
  cout << endl;
  return 0;
}
