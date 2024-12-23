#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void eratosthenes(int max) {
	long long i, j;
	max = sqrt(max);
	vector<bool> checked(max + 1);

	for (i = 2; i <= max; i++) {
		if (!checked[i]) {
			prime.push_back(i);
			for (j = i * i; j <= max; j += i)
				checked[j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> v(N);
	int max = 0;
	for (int& i : v) {
		cin >> i;
		if (i > max)
			max = i;
	}

	eratosthenes(max);

	for (int i : v) {
		for (int p : prime) {
			while (i % p == 0 && i > 1) {
				cout << p << ' ';
				i /= p;
			}
		}
		if (i != 1)
			cout << i << ' ';
		cout << '\n';
	}
}

//root(max)������ �Ҽ��� ������ ���μ����� ����
//�׷��� ki�� root(max)���� ���� �Ҽ��� ū �Ҽ��� ���ص� ��쵵 �ֱ� ������ ����ؾ� ��