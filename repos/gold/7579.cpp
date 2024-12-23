#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//dp[i][j] : i�� �ۿ��� j ����� �Ҹ��� ������ �� �ִ� �޸� 
vector<vector<int>> dp(101, vector<int>(10001));

vector<int> v;
vector<int> cost;
vector<int> sum;
int N, M;

int solve() {
	//setup : ����� �Ҹ����� ������
	for (int i = 1; i <= N; i++)
		dp[i][0] = 0;

	//fill : dp[i][j] = max(dp[i-1][j] (����), dp[i-1][j-cost[i]] + v[i] (����))
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum[i]; j++) {
			if (j < cost[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + v[i]);
		}
	}
	
	for (int i = 0; i < 10001; i++) {
		if (dp[N][i] >= M)
			return i;
	}
}

int main() {
	FASTIO;
	cin >> N >> M;

	v.push_back(-1); cost.push_back(-1); sum.resize(N + 1);
	//1-base

	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}

	for (int i = 0; i < N; i++) {
		cin >> val;
		cost.push_back(val);
		sum[i + 1] = sum[i] + val;
	}

	cout << solve() << endl;
}

//�޸�(�賶 ũ��)�� ũ�Ƿ� �޸� ��� ����� �������� ������ ����