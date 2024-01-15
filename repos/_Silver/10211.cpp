#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int MSS(vector<int>& v);

void solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	cout << MSS(v) << endl;
}

int main() {
	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}

int MSS(vector<int>& v) {
	int size = v.size();
	int ret = v[0], sum = v[0];

	for (int i = 1; i < size; i++) {
		//���� ������� ��� �����ϴ� ���, ���� ������ ���� �����ϴ� ��� �� �ִ�
		sum = max(sum + v[i], v[i]);

		//�� ��긶�� �ִ� ����
		ret = max(ret, sum);
	}

	return ret;
}