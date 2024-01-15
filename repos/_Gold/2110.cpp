#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool decision(int dist, int C) {
	int cnt = 1;
	int front = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[front] >= dist) {
			cnt++;
			front = i;
		}

		if (cnt >= C)
			return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, C;
	cin >> N >> C;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	//���� ��, �Ÿ��� �̺�Ž���ϸ� �� �Ÿ����� ��ġ ������ ������ ���� ���Ѵ�

	int l = 0, r = 1e9, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (decision(mid, C))
			l = mid;
		else
			r = mid - 1;
	}

	cout << l << endl;
}

//�� ������?
//�� v[0]���� ����ϴ� ���� ������?
//v[1] ~ v[3] >= dist�� v[0] ~ v[3]�� >= dist
//�ִ� YYYNNN, �ּ� NNNYYY�� �׸��� �׸���