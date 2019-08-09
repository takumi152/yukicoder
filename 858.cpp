#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

typedef long long int ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A, B;
  cin >> A >> B;

  ll integer = A / B;
  vector<int> frac(50);
  A %= B;
  for (int i = 0; i < 50; i++) {
    A *= 10;
    frac[i] = A / B;
    A %= B;
  }

  cout << integer << ".";
  for (auto &x: frac) cout << x;
  cout << endl;

  return 0;
}
