#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int target, m, n;

void solve(vector<int>& A, vector<int>& B) {

	int cnt = 0;
	map<int, int> ps_A, ps_B;
	//A�� B�� ��� ������ ���
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += A[(i + j) % m];
			ps_A[sum]++;

			//���� ��ü ũ���� ����� ���� 1
			if (j == m - 1)
				ps_A[sum] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += B[(i + j) % n];
			ps_B[sum]++;
			if (j == n - 1)
				ps_B[sum] = 1;
		}
	}

	//A�� ���� ���
	for (auto a : ps_A)
		if (a.first == target)
			cnt += a.second;

	//B�� ���� ���
	for (auto b : ps_B)
		if (b.first == target)
			cnt += b.second;

	//A�� B���� ���� ���� ���
	for (auto b : ps_B) {
		if (b.first < target)
			cnt += b.second * ps_A[target - b.first];
	}

	cout << cnt << endl;
}

int main() {

	cin >> target >> m >> n;

	//���� �迭, %�� ����
	vector<int> A(m), B(n);
	for (int i = 0; i < m; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		cin >> B[i];

	solve(A, B);
}

//���� ������� �ʾ��� ��� : �迭 ũ�⸦ ���� ��ü ũ��� ����