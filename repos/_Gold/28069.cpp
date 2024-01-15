#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 1000000

int dp[MAX + 1];

//�ʺ� �켱 Ž��, ���� ��ȹ�� : 0���� N���� �ִܰŸ��� ã�� �뵵
// 
//�ٽ� : K >= dp[N]�̸� True
//�ּ� �̵� Ƚ���� dp�� �̿��� ���� dp[N]���̴�.
//0�� ��ܿ��� ������ ���� ��ġ ��ȭ ���� �̵� Ƚ���� ��Ƣ�� ��ų �� �ִ�.

void solve(int N, int K) {
	fill(dp, dp + MAX + 1, INF);

	for (int i = 1; i <= 5; i++)
		dp[i] = i;

	for (int i = 4; i < N; i++) {
		dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
		if (i + i / 2 <= N)
			dp[i + i / 2] = min(dp[i] + 1, dp[i + i / 2]);
	}

	if (K >= dp[N])
		cout << "minigimbob\n";
	else
		cout << "water\n";
}

int main() {
	int N, K;
	cin >> N >> K;

	solve(N, K);
}