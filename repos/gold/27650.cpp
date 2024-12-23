#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void eratosthenes(int N) {
	long long i, j;
	vector<bool> checked(N + 1);

	for (i = 2; i <= N; i++) {
		if (!checked[i]) {
			prime.push_back(i);
			for (j = i * i; j <= N; j += i)
				checked[j] = 1;
		}
	}
}

int main() {
	int N; cin >> N;

	//N ������ �Ҽ��� ��¼���� ü�� ���� �����Ѵ�
	eratosthenes(N);

	int start = 0, end = prime.size() - 1, mid = (start + end) / 2, rans;
	bool ans;
	//�̺� Ž���� ���� ��Ȯ�� i�� ���Ѵ�
	while (start <= end) {
		cout << "? " << prime[mid] << endl;
		cout << flush;
		cin >> ans;
		//���� Ž�� : 0�� ���� ���
		if (ans == 0) {
			end = mid - 1;
			rans = mid;
		}

		//������ Ž�� : 1�� ���� ���
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	cout << "! " << prime[rans] << endl;
	cout << flush;
}