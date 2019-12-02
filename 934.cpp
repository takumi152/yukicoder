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

bool ask(vector<int> &query) {
  sort(query.begin(), query.end());
  cout << "? " << query.size() << endl;
  for (auto &x: query) cout << x << " ";
  cout << endl;
  int response;
  cin >> response;
  return response;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<bool> explosive(n);
  for (int i = 0; i < n; i++) {
    vector<int> query;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      query.push_back(j+1);
    }
    explosive[i] = !ask(query);
  }

  int k = 0;
  for (auto x: explosive) {
    if (x) k++;
  }

  cout << "! " << k << endl;
  for (int i = 0; i < n; i++) {
    if (explosive[i]) cout << i+1 << " ";
  }
  cout << endl;

  return 0;
}
