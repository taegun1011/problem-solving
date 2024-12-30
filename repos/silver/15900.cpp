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

vector<vector<int>> graph;

int dfs(int cur, int prv, int lv) {
  int ret = 0;
  for (int nxt : graph[cur]) {
    if (nxt == prv) continue;
    ret += dfs(nxt, cur, lv + 1);
  }

  if (!ret) return lv;

  return ret;
}

void solve() {
  cin >> N;
  graph = vector<vector<int>>(N + 1, vector<int>());

  int u, v;
  for (int i = 1; i < N; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  cout << (dfs(1, 0, 0) % 2 ? "Yes" : "No") << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}