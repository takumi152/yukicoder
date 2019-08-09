// WIP

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

  int N;
  cin >> N;
  vector<pair<ll, ll> > cd(N);
  for (auto &x: cd) cin >> x.first >> x.second;

  vector<ll> single(N);
  vector<ll> multiple(N);
  for (int i = 0; i < N; i++) single[i] = cd[i].first;
  for (int i = 0; i < N; i++) multiple[i] = cd[i].first + cd[i].second;


  return 0;
}
