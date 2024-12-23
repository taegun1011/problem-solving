#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> v;

//size ������ ������ N�� ���� �� �ִ°�?
bool decision(ll size, int N) {
	if (size == 0)
		return true;

	//sum�� �ִ� : 10000 * (2^31-1) -> long long
	ll sum = 0;
	for (int i : v)
		sum += i / size; {
		if (sum >= N)
			return true;
	}
	
	return false;
}

int main() {
	int K, N;
	cin >> K >> N;

	v.resize(K);
	for (int i = 0; i < K; i++)
		cin >> v[i];

	ll l = 0, r = INT_MAX, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if ((l + r) % 2)
			mid++;

		if (decision(mid, N))
			l = mid;
		else
			r = mid - 1;
	}

	cout << l << endl;
}

//l�� r�� ���� �������� ����ؾ���