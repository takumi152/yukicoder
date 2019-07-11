#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main(){
  ll P, Q, R;
  cin >> P >> Q >> R;
  ll A, B, C;
  cin >> A >> B >> C;
  ll goldLeft = P * (A - 1) + 1;
  ll goldRight = P * A;
  ll silverLeft = Q * (A + B - 1) + 1;
  ll silverRight = Q * (A + B);
  ll bronzeLeft = R * (A + B + C - 1) + 1;
  ll bronzeRight = R * (A + B + C);
  vector<ll> left = {goldLeft, silverLeft, bronzeLeft};
  vector<ll> right = {goldRight, silverRight, bronzeRight};
  ll maxLeft = *max_element(left.begin(), left.end());
  ll minRight = *min_element(right.begin(), right.end());
  if (maxLeft > minRight) cout << -1 << endl;
  else cout << maxLeft << " " << minRight << endl;
  return 0;
}
