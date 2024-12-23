#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//�Ҽ��� �̸� ���� �ʿ䰡 ����.
//'�����佺�׳׽��� ü'��� ������ Ȱ���ص� ��

int main() {
	ll min, max;
	cin >> min >> max;

	int sz = max - min + 1;
	vector<bool> checked(sz + 1);

	for (ll i = 2; (i * i) <= max; i++) {
		ll sqr = i * i;

		ll temp = (min / sqr) * sqr;
		if (min % sqr)
			temp += sqr;

		for (temp; temp <= max; temp += sqr)
			checked[temp - min + 1] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= sz; i++)
		if (!checked[i])
			cnt++;

	cout << cnt << endl;
}