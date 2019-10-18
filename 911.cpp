// WIP

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a;
  for (auto &x: a) cin >> x;

  vector<vector<int> > swapPoint01(62), swapPoint10(62);
  vector<bool> xor0(62), xor1(62);

  for (int k = 61; k >= 0; k--) {
    ll mask = 1 << k;
    bool lastWas1 = a[n] & mask;
    for (int i = 1; i < n; i++) {
      if ((a[i-1] & mask) != (a[i] & mask)) {
        if (a[i-1] & mask) {
          swapPoint01.push_back(1);
        }
      }
    }
  }

  return 0;
}
