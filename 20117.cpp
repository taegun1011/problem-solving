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

void solve() {
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  sort(arr.begin(), arr.end());
  int sum = 0;
  for (int i = N - 1; i >= N / 2; i--) {
    sum += arr[i];
    if (i != N - 1 - i) sum += arr[i];
  }

  cout << sum << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}