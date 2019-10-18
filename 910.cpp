#include <iostream>
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

  int n;
  cin >> n;
  string s;
  cin >> s;

  int c1 = 0, c3 = 0, c5 = 0, c7 = 0;
  int ans = 0;
  queue<int> q1;
  vector<bool> removed(n);
  for (int i = 0; i < n; i++) {
    char buf = s[i];
    switch (buf) {
      case '1':
        q1.push(i);
        c1++;
        break;
      case '3':
        c3++;
        break;
      case '5':
        c5++;
        break;
      case '7':
        c7++;
        break;
      case '9':
        if (c1 > 0) {
          ans++;
          c1--;
          int r1 = q1.front();
          q1.pop();
          removed[r1] = true;
          removed[i] = true;
        }
        break;
    }
  }
  int rc1 = 0, rc9 = 0;
  for (int i = n-1; i >= 0; i--) {
    char buf = s[i];
    switch (buf) {
      case '1':
        if (!removed[i]) rc1++;
        break;
      case '3':
        break;
      case '5':
        break;
      case '7':
        break;
      case '9':
        if (!removed[i]) rc9++;
        if (rc1 >= 1 && rc9 >= 2) {
          ans++;
          c1--;
          rc1--;
          rc9 -= 2;
        }
        break;
    }
  }
  ans += c1 / 2 + c3 + c5 + c7;

  cout << ans << endl;

  return 0;
}
