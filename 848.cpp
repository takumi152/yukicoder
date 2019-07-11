// WIP

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<ll, int> Pli;

vector<Pli> dijkstra(const vector<set<Pii> > &edge, int start) {
  vector<Pli> length(edge.size(), Pli(1000000007LL * 1000000007LL, -1));
  vector<bool> visited(edge.size(), false);
  priority_queue<Pli> que;
  que.push(Pii(0, start)); // negative distance
  length[start].first = 0;
  while (!que.empty()) {
    Pli now = que.top();
    que.pop();
    if (visited[now.second]) continue;
    visited[now.second] = true;
    for (Pii x : edge[now.second]) {
      cout << now.first << " " << now.second << " " << x.first << " " << x.second << endl;
      if (visited[x.second]) continue;
      ll d = -now.first + x.first;
      if (d < length[x.second].first) {
        length[x.second].first = d;
        length[x.second].second = now.second;
        que.push(Pli(-d, x.second));
      }
    }
  }
  return length;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, P, Q, T;
  cin >> N >> M >> P >> Q >> T;
  P--, Q--; // zero index
  vector<set<Pii> > edge;
  for (int i = 0; i < N; i++) edge.push_back(set<Pii>());
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a-1].insert(Pii(c, b-1)); // zero index
    edge[b-1].insert(Pii(c, a-1)); // zero index
  }

  vector<Pli> dFrom0 = dijkstra(edge, 0);
  if (dFrom0[P].first > dFrom0[Q].first) swap(P, Q);
  vector<Pli> dFromP = dijkstra(edge, P);
  vector<Pli> dFromQ = dijkstra(edge, Q);
  if (dFrom0[P].first * 2 > T || dFrom0[Q].first * 2 > T) {
    cout << -1 << endl; // impossible :(
    return 0;
  }
  else if ((dFrom0[P].first + dFromP[Q].first + dFromQ[0].first) <= T) {
    cout << T << endl; // always together :)
    return 0;
  }
  vector<bool> sameShortest(N, false);
  for (int i = 0; i < N; i++) {
    if (dFromP[i].first - dFrom0[P].first == dFromQ[i].first - dFrom0[Q].first) sameShortest[i] = true;
  }
  Pli shortestSameShortest(1000000007LL * 1000000007LL, -1);
  for (int i = 0; i < N; i++) {
    if (sameShortest[i] && dFromQ[i].first < shortestSameShortest.first) shortestSameShortest = Pli(dFromQ[i].first, i);
  }
  int timeLeft = T - dFrom0[P].first * 2;
  int now = shortestSameShortest.second;
  while (now != Q) {
    int next = dFromQ[now].second;
    if (timeLeft - (dFromQ[now].first - dFromQ[next].first) * 2 < 0) break;
    timeLeft -= (dFromQ[now].first - dFromQ[next].first) * 2;
    now = next;
  }
  int ans = dFrom0[shortestSameShortest.second].first + dFrom0[now].first + (T - dFrom0[Q].first * 2);
  cout << ans << endl;
  cout << timeLeft << " " << now << endl;
  for (int i = 0; i < N; i++) cout << dFrom0[i].first << endl;
  for (int i = 0; i < N; i++) cout << dFromP[i].first << endl;
  for (int i = 0; i < N; i++) cout << dFromQ[i].first << endl;
  for (int i = 0; i < N; i++) cout << sameShortest[i] << endl;
  return 0;
}
