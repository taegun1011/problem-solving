#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define matrix vector<vector<int>>
#define INF 987654321

int dp[1001][3];

int solve(matrix& cost);

int main() {
	int N;
	cin >> N;

	matrix cost(N, vector<int>(3));
	for (vector<int>& row : cost)
		for (int& i : row)
			cin >> i;

	cout << solve(cost) << endl;
}

int solve(matrix& cost) {
	//0 : red, 1 : green, 2 : blue

	int size = cost.size(), ret = INF;
	
	//ù ���� start��° ������ �ϴ� ���
	for (int start = 0; start < 3; start++) {

		//������ start�� ĥ�ϵ��� �ʱ�ȭ
		for (int i = 0; i < 3; i++)
			dp[1][i] = INF;

		dp[1][start] = cost[0][start];

		for (int i = 2; i <= size; i++) {
			for (int j = 0; j < 3; j++) {

				//��ⷯ ������ �̿��� �ٸ� �� ������ �ּڰ��� ���Ѵ�.
				int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;
				int minIdx = dp[i - 1][idx1] < dp[i - 1][idx2] ? idx1 : idx2;

				dp[i][j] = dp[i - 1][minIdx] + cost[i - 1][j];
			}
		}

		//������ ���� start�� ����� �����Ѵ�
		dp[size][start] = INF;
		ret = min({ret, dp[size][0], dp[size][1] , dp[size][2] });
	}

	return ret;
}									 


//���� : min({}), ��ⷯ�������� �� ���ϰ� �ۼ�, 2���� �迭 &�� �Է¹ޱ�