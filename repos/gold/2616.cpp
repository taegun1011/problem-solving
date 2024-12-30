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

vector<int> arr, psum;
int dp[50001][4];

int re_dp(int cur, int left) {
  if (cur > N || left <= 0) return 0;

  if (dp[cur][left] != -1) return dp[cur][left];

  int& ret = dp[cur][left] = re_dp(cur + 1, left);
  int nxt = min(N, cur + M - 1);
  ret = max(ret, re_dp(nxt + 1, left - 1) + psum[nxt] - psum[cur - 1]);

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));

  cin >> N;
  arr = vector<int>(N + 1);
  psum = vector<int>(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    psum[i] = psum[i - 1] + arr[i];
  }
  cin >> M;
  cout << re_dp(1, 3) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}