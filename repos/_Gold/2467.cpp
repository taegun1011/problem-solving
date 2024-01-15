#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve(vector<int>& v, int N);

int main() {
	FASTIO
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	solve(v, N);
}

void solve(vector<int>& v, int N) {
	//�������ͷ� �糡���� ����� �̵��ϸ鼭
	int i = N - 1, j = 0, sum = 0;
	int ans1, ans2, min = INT_MAX;

	while (j < i) {
		sum = v[i] + v[j];

		//0�� �ƴ� �ּڰ��� ���
		if (abs(sum) < min) {
			min = abs(sum);
			ans1 = v[j], ans2 = v[i];
		}

		if (sum == 0) {
			cout << v[j] << ' ' << v[i] << endl;
			return;
		}

		else if (sum > 0)
			i--;
		else
			j++;
	}

	cout << ans1 << ' ' << ans2 << endl;
}