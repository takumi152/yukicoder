// WIP

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

  int N, M;
  cin >> N >> M;
  vector<vector<int> > A(N, vector<int>(M));
  for (auto &x: A) {
    for (auto &y: x) cin >> y;
  }

  vector<vector<int> > dp(M+1, vector<int>(N));

  cout << ans << endl;

  return 0;
}
