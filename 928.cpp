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

  ll p, q, a;
  cin >> p >> q >> a;

  if (p < q) {
    ll ans = 1000000000;
    for (ll i = 1; i <= 1000000000; i++) {
      ll in = i * (p + 100) / 100;
      ll out = (i * (q + 100) / 100) + a;
      if (in >= out) ans--;
      else if (in < out - 3) break;
    }
    cout << ans << endl;
    return 0;
  }
  else if (p == q) {
    if (a == 0) cout << 0 << endl;
    else cout << 1000000000 << endl;
    return 0;
  }

  ll cleft, cright, left, right;

  left = 1;
  right = 1000000000;
  while (left < right) {
    ll center = (left + right) / 2;
    ll in = center * (p + 100) / 100;
    ll out = (center * (q + 100) / 100) + a;
    if (in < out - 3) left = center + 1;
    else right = center - 1;
  }
  cleft = left;

  left = 1;
  right = 1000000000;
  while (left < right) {
    ll center = (left + right) / 2;
    ll in = center * (p + 100) / 100;
    ll out = (center * (q + 100) / 100) + a;
    if (in < out + 3) left = center + 1;
    else right = center - 1;
  }
  cright = left;

  ll ans = cleft - 1;
  for (ll i = cleft; i <= cright; i++) {
    ll in = i * (p + 100) / 100;
    ll out = (i * (q + 100) / 100) + a;
    if (in < out) ans++;
  }

  cout << ans << endl;

  return 0;
}
