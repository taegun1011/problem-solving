#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 4000000


vector<int> prime;
bool checked[MAX + 1];

void eratosthenes(int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (!checked[i]) {
			prime.push_back(i);
			for (j = i; j <= n; j += i)
				checked[j] = 1;
		}
	}
}

int main() {
	int n; cin >> n;

	//�ڱ� �ڽ��� �Ҽ��� ��� �信 ���ԵǱ� ������, �Ҽ��� �ڱ� �ڽű��� ���
	eratosthenes(n);

	//1 ������ �Ҽ��� ���� ������ ���� ó��
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
		

	int i, j, cnt, sum;
	j = cnt = sum = 0;
	for (i = 0; i <= prime.size() - 1; i++) {
		sum += prime[i];
		while (sum > n)
			sum -= prime[j++];
			
		if (sum == n)
			cnt++;
	}

	cout << cnt << endl;
}