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

int N, M;

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

void solve() {
  cin >> N;
  vector<int> l(N + 2), r(N + 2), arr(N + 1);
  for (int i = 1; i <= N; i++) cin >> arr[i];

  for (int i = 1; i <= N; i++) {
    l[i] = l[i - 1] ? gcd(l[i - 1], arr[i]) : arr[i];
    r[N + 1 - i] =
        r[N + 2 - i] ? gcd(r[N + 2 - i], arr[N + 1 - i]) : arr[N + 1 - i];
  }

  int mx = -1, ans = 0;
  for (int i = 1; i <= N; i++) {
    int lgcd = l[i - 1], rgcd = r[i + 1];
    int cur = lgcd && rgcd ? gcd(lgcd, rgcd) : (!lgcd ? rgcd : lgcd);
    if (arr[i] % cur) {
      if (cur > mx) {
        mx = cur;
        ans = arr[i];
      }
    }
  }

  if (mx == -1)
    cout << mx << '\n';
  else
    cout << mx << ' ' << ans << '\n';
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}