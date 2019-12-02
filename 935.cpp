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
  string s;
  cin >> s;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;
  int q;
  cin >> q;
  vector<ll> k(q);
  for (auto &x: k) cin >> x;

  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    ll power = k[i];
    int killed = 0;
    int p1 = 0, p2 = 0;
    while (p2 <= n) {
      if (power >= 0) {
        if (p2 >= n) break;
        power -= a[p2];
        if (s[p2] == 'E') killed++;
        p2++;
      }
      else {
        power += a[p1];
        if (s[p1] == 'E') killed--;
        p1++;
      }
      if (power >= 0) ans[i] = max(ans[i], killed);
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
