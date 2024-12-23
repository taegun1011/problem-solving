#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int N, K;

//�迭 A���� n ������ ���� ������ k�� �̻��ΰ�?
bool decision(ll num) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {

		if (N <= num / i)
			cnt += N;
		else
			cnt += num / i;
		if (cnt >= K)
			return true;
	}

	return false;
}

int main() {
	cin >> N >> K;

	//99999 * 99999 : overflow
	ll l = 1, r = (ll)N * N, mid;
	//NNNYYY
	while (l < r) {
		mid = (l + r) / 2;

		if (decision(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
}

//�� ���������� decision�� �����ε� �˾Ƶ���