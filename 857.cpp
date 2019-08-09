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

  ll X, Y, Z;
  cin >> X >> Y >> Z;

  ll count = Z;
  if (X <= Z) count--;
  if (Y <= Z) count--;

  cout << count << endl;

  return 0;
}
