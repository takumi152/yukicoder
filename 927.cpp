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

  string x;
  cin >> x;

  int l = x.length();

  map<char, int> count;
  for (auto &c: x) count[c]++;
  if (count.size() == 1 || count['0'] >= l-1) {
    cout << -1 << endl; // impossible
    return 0;
  }

  sort(x.begin(), x.end());
  int p = 1;
  while (x[p-1] == x[p]) p++;
  swap(x[p-1], x[p]);
  reverse(x.begin(), x.end());

  cout << x << endl;

  return 0;
}
