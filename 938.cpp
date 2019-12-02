#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstdlib>
#include <queue>
#include <set>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

  set<string> cheater, clean;
  for (int i = 0; i < n; i++) {
    cheater.insert(a[i]);
    auto it1 = clean.find(a[i]);
    if (it1 != clean.end()) clean.erase(it1);
    auto it2 = cheater.find(b[i]);
    if (it2 == cheater.end()) clean.insert(b[i]);
  }

  vector<string> ans;
  set<string> checked;
  for (int i = 0; i < n; i++) {
    auto it1 = clean.find(b[i]);
    auto it2 = checked.find(b[i]);
    if (it1 != clean.end() && it2 == checked.end()) {
      ans.push_back(b[i]);
      checked.insert(b[i]);
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
