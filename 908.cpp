#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <list>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  getline(cin, s);

  for (int i = 0; i < s.length(); i += 2) {
    if (s[i] == ' ') {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 1; i < s.length(); i += 2) {
    if (s[i] != ' ') {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
