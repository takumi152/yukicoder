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

  string s;
  cin >> s;

  int p = 0;
  int n = s.size();
  string buf;
  bool good = true;
  while (p < n) {
    if (s[p] != ',') buf += s[p];
    else {
      if (buf != "AC") {
        good = false;
        break;
      }
      buf = "";
    }
    p++;
  }
  if (buf != "AC") {
    good = false;
  }

  if (good) cout << "Done!" << endl;
  else cout << "Failed..." << endl;

  return 0;
}
