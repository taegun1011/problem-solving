#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>
#define INF 987654321

int n, m;
void solve(graph&);
int func(int si, int sj, int ei, int ej, graph& sum);

//dp[i][j][k][l] : (i,j)���� (k,l)������ ���簢��
//dp[i][j][k][l] : (i,j)���� (k,l) ������ ������ ��� ������ �� + �������� ������
int dp[51][51][51][51];

int main() {
	cin >> n >> m;
	//Į���� n*m - 1��

	graph g(n, vector<int>(m));
	for (vector<int>& row : g)
		for (int& item : row)
			cin >> item;

	solve(g);
}

void solve(graph& g) {

	//2���� ������ ���
	graph sum(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= m; i++)
		sum[1][i] = sum[1][i - 1] + g[0][i - 1];

	for (int i = 1; i <= n; i++)
		sum[i][1] = sum[i - 1][1] + g[i - 1][0];

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i - 1][j - 1];

	//Top-down dp ����
	dp[1][1][n][m] = func(1, 1, n, m, sum);
	cout << dp[1][1][n][m] << endl;
}

int func(int si, int sj, int ei, int ej, graph& sum) {

	int& mn = dp[si][sj][ei][ej];
	if (mn > 0 && mn < INF)
		return mn;

	if (si == ei && sj == ej)
		return mn = 0;

	mn = INF;

	//���η� �ڸ���
	for (int i = si; i < ei; i++)
		mn = min(mn, func(si, sj, i, ej, sum) + func(i + 1, sj, ei, ej, sum));

	//���η� �ڸ���
	for (int j = sj; j < ej; j++)
		mn = min(mn, func(si, sj, ei, j, sum) + func(si, j + 1, ei, ej, sum));

	//�ڸ��� �� ���ݸ��� �������� ���� ��ȯ�Ѵ�
	mn += sum[ei][ej] - sum[si - 1][ej] - sum[ei][sj - 1] + sum[si - 1][sj - 1];
	return mn;
}

//����� dp�� ������ �� �˾ƾ��Ѵ�. dp�� ���ǵ� �� ������ ��