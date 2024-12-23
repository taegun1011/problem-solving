#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int divisor = 1000000007;
int N;

//2^k�� divisor�� ���� �������� ���
ll pow2(int k) {
	ll base = 2, res = 1;
	while (k) {
		if (k % 2)
			res = res * base % divisor;
		base = base * base % divisor;
		k /= 2;
	}

	return res;
}

ll func(ll i) {
	return pow2(i) - pow2(N - i - 1);
}

int main() {
	cin >> N;

	vector<ll> v(N);
	for (ll& i : v)
		cin >> i;

	//���� �ϰ� ��������
	sort(v.begin(), v.end());

	for (ll i : v)
		i %= divisor;

	vector<int> power;
	for (int i = 0; i < N; i++)
		power.push_back(pow2(i));

	//�Ϲ��� : v[i] * (2^i - 2^(n-i-1))

	ll maxVal = 0, minVal = 0;
	for (int i = 0; i < N; i++) {
		maxVal += v[i] * (power[i] - 1);
		maxVal %= divisor;
		minVal += v[i] * (power[N - i - 1] - 1);
		minVal %= divisor;
	}

	ll score = maxVal - minVal;
	while (score < 0)
		score += divisor;
	score %= divisor;

	cout << score << endl;
}