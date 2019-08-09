#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

typedef long long int ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y, z;
  cin >> x >> y >> z;
  char s0, s1;
  int t0, t1;
  cin >> s0 >> t0;
  cin >> s1 >> t1;

  vector<set<pair<ll, int> > > edge(8);
  edge[0].emplace(1, 1);
  edge[0].emplace(1, 2);
  edge[1].emplace(1, 2);
  edge[1].emplace(1, 0);
  edge[2].emplace(1, 0);
  edge[2].emplace(1, 1);
  edge[3].emplace(1, 4);
  edge[3].emplace(1, 5);
  edge[4].emplace(1, 5);
  edge[4].emplace(1, 3);
  edge[5].emplace(1, 3);
  edge[5].emplace(1, 4);
  if (s0 != s1) {
    switch (s0) {
      case 'A':
        edge[0].emplace(t0-1, 6);
        edge[6].emplace(t0-1, 0);
        edge[3].emplace(x-t0, 6);
        edge[6].emplace(x-t0, 3);
        break;
      case 'B':
        edge[1].emplace(t0-1, 6);
        edge[6].emplace(t0-1, 1);
        edge[4].emplace(y-t0, 6);
        edge[6].emplace(y-t0, 4);
        break;
      case 'C':
        edge[2].emplace(t0-1, 6);
        edge[6].emplace(t0-1, 2);
        edge[5].emplace(z-t0, 6);
        edge[6].emplace(z-t0, 5);
        break;
    }
    switch (s1) {
      case 'A':
        edge[0].emplace(t1-1, 7);
        edge[7].emplace(t1-1, 0);
        edge[3].emplace(x-t1, 7);
        edge[7].emplace(x-t1, 3);
        break;
      case 'B':
        edge[1].emplace(t1-1, 7);
        edge[7].emplace(t1-1, 1);
        edge[4].emplace(y-t1, 7);
        edge[7].emplace(y-t1, 4);
        break;
      case 'C':
        edge[2].emplace(t1-1, 7);
        edge[7].emplace(t1-1, 2);
        edge[5].emplace(z-t1, 7);
        edge[7].emplace(z-t1, 5);
        break;
    }
  }
  else {
    if (t0 > t1) swap(t0, t1);
    switch (s0) {
      case 'A':
        edge[0].emplace(t0-1, 6);
        edge[6].emplace(t0-1, 0);
        edge[6].emplace(t1-t0, 7);
        edge[7].emplace(t1-t0, 6);
        edge[3].emplace(x-t1, 7);
        edge[7].emplace(x-t1, 3);
        break;
      case 'B':
        edge[1].emplace(t0-1, 6);
        edge[6].emplace(t0-1, 1);
        edge[6].emplace(t1-t0, 7);
        edge[7].emplace(t1-t0, 6);
        edge[4].emplace(y-t1, 7);
        edge[7].emplace(y-t1, 4);
        break;
      case 'C':
        edge[2].emplace(t0-1, 6);
        edge[6].emplace(t0-1, 2);
        edge[6].emplace(t1-t0, 7);
        edge[7].emplace(t1-t0, 6);
        edge[5].emplace(z-t1, 7);
        edge[7].emplace(z-t1, 5);
        break;
    }
  }
  if (s0 != 'A' && s1 != 'A') {
    edge[0].emplace(x-1, 3);
    edge[3].emplace(x-1, 0);
  }
  if (s0 != 'B' && s1 != 'B') {
    edge[1].emplace(y-1, 4);
    edge[4].emplace(y-1, 1);
  }
  if (s0 != 'C' && s1 != 'C') {
    edge[2].emplace(z-1, 5);
    edge[5].emplace(z-1, 2);
  }
  ll ans = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > que;
  que.emplace(0, 6);
  vector<bool> visited(8);
  while (!que.empty()) {
    auto now = que.top();
    que.pop();
    if (now.second == 7) {
      ans = now.first;
      break;
    }
    if (visited[now.second]) continue;
    visited[now.second] = true;
    for (auto &x: edge[now.second]) {
      if (visited[x.second]) continue;
      que.emplace(now.first + x.first, x.second);
    }
  }

  cout << ans << endl;

  return 0;
}
