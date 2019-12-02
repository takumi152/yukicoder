#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  vector<bool> x(32), y(32);
  for (int i = 0; i < 32; i++) {
    x[i] = (a & 1);
    y[i] = (b & 1);
    a >>= 1;
    b >>= 1;
  }

  int c = 0;
  for (int i = 0; i < 32; i++) {
    if (x[i] && !y[i]) {
      cout << 0 << endl; // impossible
      return 0;
    }
    else if (!x[i] && y[i]) c++;
  }

  int ans = 1;
  for (int i = 0; i < c - 1; i++) ans <<= 1;

  cout << ans << endl;

  return 0;
}
