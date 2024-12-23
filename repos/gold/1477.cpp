#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> arr;

bool check(int x, int left) {
	int N = arr.size();
	for (int i = 1; i < N; i++) {
		//���� ������ x ������ �������� ������
		//x�� 140, ������ 140�̸� �ʿ� �ްԼҴ� 0�� -> -1 �߰�
		//�Է� ���ǿ��� ���� ������ �߻��� �� ����
		left -= (arr[i] - arr[i - 1] - 1) / x;
		if (left < 0)
			return false;
	}
	return true;
}

void solve() {
	int N, M, L;
	cin >> N >> M >> L;

	arr.push_back(0);
	while (N--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	arr.push_back(L);

	int s = 1, e = L, m;

	//NNNNYYYY
	while (s < e) {
		m = (s + e) / 2;
		if (check(m, M))
			e = m;
		else
			s = m + 1;
	}

	cout << s << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}