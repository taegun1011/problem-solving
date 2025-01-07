// 참고: justicehui.github.io/sunrin-ps/2018/11/10/BOJ15918/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

vector<int> arr;
vector<bool> visited;

int recur(int i) {
  if (i + 1 == N * 2) return 1;
  int ret = 0;

  if (!arr[i]) {
    for (int j = 1; j <= N; j++) {
      if (!visited[j]) {
        if (i + j + 1 < N * 2 && !arr[i + j + 1]) {
          arr[i] = arr[i + j + 1] = j;
          visited[j] = true;
          ret += recur(i + 1);
          visited[j] = false;
          arr[i] = arr[i + j + 1] = 0;
        }
      }
    }
    return ret;
  }
  return recur(i + 1);

  return ret;
}

void solve() {
  int x, y, t;
  cin >> N >> x >> y;
  t = y - x - 1;

  arr = vector<int>(N * 2);
  arr[x - 1] = arr[y - 1] = t;

  visited = vector<bool>(N + 1);
  visited[t] = true;

  cout << recur(0) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}