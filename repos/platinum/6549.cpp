#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define INF 987654321

ll calcArea(vector<int>& v, int a, int b) {
	int height = min(v[a], v[b]);
	int width = abs(a - b) + 1;
	return 1ll * height * width;
}

//�߰��� ������ ���� ���簢���� ������ �� �ȴ�
// Ư�� ���̽�
//1. ���� Ű�� �����ؼ� ���� ���
//2. �� ���簢���� Ű�� ������ Ŭ ���
void solve(int N) {

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	stack<int> S1, S2;

	ll ans = 0;

	for (int i = 0; i < N; i++) {
		int min = INF;
		while (!S1.empty() && v[i] > v[S1.top()]) {

			//���̰� min�� ��쿡�� ���̸� ���Ѵ�
			if (v[S1.top()] < min) {
				ans = max(ans, calcArea(v, i, S1.top()));
				min = S1.top();
			}
			S1.pop();
		}
		S1.push(i);
	}

	for (int i = N - 1; i >= 0; i--) {
		int min = INF;
		while (!S2.empty() && v[i] >= v[S2.top()]) {

			//���̰� min�� ��쿡�� ���̸� ���Ѵ�
			if (v[S2.top()] < min) {
				ans = max(ans, calcArea(v, i, S2.top()));
				min = S2.top();
			}
			S2.pop();
		}
		S2.push(i);
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int N;
	cin >> N;

	while (N) {
		solve(N);
		cin >> N;
	}
}