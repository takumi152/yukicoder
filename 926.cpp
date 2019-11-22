#include <iostream>
#include <iomanip>
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

  double a, b, c;
  cin >> a >> b >> c;

  double ans = a / (b / c);

  cout << setprecision(12) << ans << endl;

  return 0;
}
