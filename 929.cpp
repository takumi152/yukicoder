#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> b(n);
  for (auto &x: b) cin >> x;

  ll ans = 0;
  int p = 0;
  int q = 0;
  while (p < n) {
    while (p < n) {
      if (b[p] > 0) p++;
      else break;
    }
    while (q < n) {
      if (b[q] < 2) q++;
      else break;
    }
    if (p == n && q == n) break;
    ans += abs(p - q);
    b[p]++;
    b[q]--;
  }

  cout << ans << endl;

  return 0;
}
