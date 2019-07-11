#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int ll;
typedef pair<ll, int> Pli;

set<ll> getDivisorSet(ll n) {
  set<ll> divisor;
  ll k = 1;
  while (k * k <= n) {
    if (n % k == 0) {
      divisor.insert(k);
      divisor.insert(n / k);
    }
    k++;
  }
  return divisor;
}

int main(){
  ll N, K, M;
  cin >> N >> K >> M;

  set<ll> divisor = getDivisorSet(N);
  set<ll> powerDivisor;
  stack<Pli> st;
  for (ll x : divisor) st.push(Pli(x, K));
  while (!st.empty()) {
    Pli now = st.top();
    st.pop();
    if (now.second <= 0) continue;
    if (now.first > M) continue;
    auto it = powerDivisor.find(now.first);
    if (it != powerDivisor.end()) continue;
    powerDivisor.insert(now.first);
    for (ll x : divisor) st.push(Pli(now.first * x, now.second - 1));
  }
  int ans = powerDivisor.size();
  cout << ans << endl;
  return 0;
}
