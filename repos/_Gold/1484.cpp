#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll diff;
	cin >> diff;

	//diff <= 100000 => cur <= 50001
	ll cur, last = 1, res = 0;
	bool flag = 0;
	for (cur = 1; cur <= 50001; cur++) {

		res = cur * cur;
		while (res - last * last > diff)
			last++;
		if (res - last * last == diff) {
			cout << cur << endl;
			flag = 1;
		}
	}

	if (!flag)
		cout << -1 << endl;
}

//�ݷ� 2
//last�� 0�� ���� �信 ���Խ�Ű�� ����