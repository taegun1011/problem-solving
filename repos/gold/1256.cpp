#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1000000000

int dp[201][101];

//�� n�� ���ĺ� �� 'a'�� r���� ������ ��
int re_dp(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	if (dp[n][r] != -1)
		return dp[n][r];
	//10�ﺸ�� ũ�� �����÷ο찡 ���� ���ʿ� �� ��꿡 �ʿ䰡 �����Ƿ� �ִ� ����
	return dp[n][r] = min(re_dp(n - 1, r) + re_dp(n - 1, r - 1), MAX);
}

//
void back(int a, int z, int left) {

	//���������� �������� ���� ���ڿ��� ����
	//���� ���ĺ��� ��� ����Ѵ�
	if (left == 1) {
		while (a--)
			cout << 'a';
		while (z--)
			cout << 'z';
		cout << endl;
		return;
	}

	//�� ��ġ���� a�� ����� ��� ����ؼ� ���� �� �ִ� ����� ���� (a+z-1)C(a-1)��
	//a�� ���ų�, (a+z-1)C(a-1) < left�� ��� z�� �����ؾ� �Ѵ�
	
	//ex) ���� a�� 2��, z�� 2��, left = 6 : a�� ���� 3C1 = 3���� ���ڿ��� ���� �� �ִ�
	//6��° ���ڿ��� ���� �ϴµ� a�� ���� 3��°�� �ִ��̴�. ���� z�� ���� �Ѵ�
	if (a == 0 || re_dp(a + z - 1, a - 1) < left) {
		cout << 'z';
		back(a, z - 1, left - re_dp(a + z - 1, a - 1));
	}

	//�װ� �ƴ϶�� a�� �����Ѵ�
	else {
		cout << 'a';
		back(a - 1, z, left);
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N, M, K;
	cin >> N >> M >> K;

	int total = re_dp(N + M, N);

	if (total < K)
		cout << -1 << endl;
	else
		back(N, M, K);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}