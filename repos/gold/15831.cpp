#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M, B, W;

void solve() {
  cin >> N >> B >> W;
  string str;
  cin >> str;

  int l = 0, r, b = 0, w = 0, ans = 0;
  for (r = 0; r < N; r++) {
    b += str[r] == 'B';
    w += str[r] == 'W';
    while (l < r && b > B) {
      b -= str[l] == 'B';
      w -= str[l] == 'W';
      l++;
    }
    if (b <= B && w >= W) ans = max(ans, r - l + 1);
  }

  cout << ans << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}