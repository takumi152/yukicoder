#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <list>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (auto &xx: x) cin >> xx;
  for (auto &yy: y) cin >> yy;

  int maxDistance = 1000000007;
  for (int i = 0; i < n; i++) {
    int dist = x[i] + y[i];
    if (dist < maxDistance) {
      maxDistance = dist;
    }
  }

  vector<int> ans(n+2);
  ans[0] = 0;
  ans[n+1] = maxDistance;
  for (int i = 0; i < n; i++) {
    ans[i+1] = min(x[i], maxDistance);
  }

  cout << maxDistance << endl;
  for (auto &a: ans) cout << a << endl;

  return 0;
}
