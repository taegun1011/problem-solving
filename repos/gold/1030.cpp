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

// 코드 참고
// https://zerotay.tistory.com/335

bool chk(int size, int val) {
  return val >= size * (N - M) / 2 && val < size * (N + M) / 2;
}

int recur(int size, int r, int c) {
  if (size == 1) return 0;

  int tmp = size / N;
  if (chk(tmp, r) && chk(tmp, c)) return 1;

  return recur(tmp, r % tmp, c % tmp);
}

void solve() {
  int s, r1, r2, c1, c2;
  cin >> s >> N >> M >> r1 >> r2 >> c1 >> c2;
  int size = pow(N, s);

  // 출력할 구간에 대해서만 확인
  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) cout << recur(size, i, j);
    cout << '\n';
  }
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}