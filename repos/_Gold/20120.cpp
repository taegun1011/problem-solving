#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF -987654321

//dp[i][j] : i��° ��Ʈ�� �޺� j�� ó������ ���� �ִ�
ll dp[1001][1001];

//visited[i][j] : dp[i][j]�� �ִ��� �� �����ؼ� Ʋ�� Ƚ��
int visited[1001][1001];
int N;
vector<int> v;

ll solve(vector<int>& v);

int main() {
	cin >> N;
	v.push_back(0);

	int val;
	for (int i = 1; i <= N; i++) {
		cin >> val;
		v.push_back(val);
	}

	cout << solve(v) << endl;
}

ll solve(vector<int>& v) {

	//setup : ��� ��Ʈ�� ġ�� ���
	for (int i = 1; i <= N; i++)
		dp[i][i] = dp[i - 1][i - 1] + (ll)v[i] * i;
	
	//fill
	for (int i = 1; i <= N; i++) {

		//dp[i-1][0 ~ i-1] �� �ִ񰪰� �� �ε����� Ž��
		int maxCombo = 0;
		ll maxScore = INF;
		for (int j = 0; j < i; j++)
			if (dp[i - 1][j] > maxScore && visited[i][j] < 3) {
				maxCombo = j;
				maxScore = dp[i - 1][j];
			}

		//dp[i][0] = ���� ������ �������� ��, ���� ���� �� �ִ�
		dp[i][0] = maxScore;

		//�߰��� 1ȸ ���� ��ħ
		visited[i][0] = visited[i - 1][maxCombo] + 1;

		//3ȸ �̻� ��ġ�� 0
		if (visited[i][0] >= 3)
			dp[i][0] = INF;

		//dp[i][1~i] = ���� ������ ���� ��
		//��Ʈ 1 ����, �޺� 1 ���� -> �밢�� �Ʒ��� �̵�
		for (int j = 1; j <= i; j++) {

			//���� ��ġ���� ���� �������� ��� ��� X
			if (visited[i - 1][j - 1] >= 3) {
				dp[i][j] = INF;
				visited[i][j] = visited[i - 1][j - 1];
			}
				

			//�ƴ� ��� �޺���ŭ �ջ�
			else {
				dp[i][j] = dp[i - 1][j - 1] + (ll)v[i] * j;
				visited[i][j] = 0;
			}
		}
	}
	
	return max((ll)0, *max_element(dp[N], dp[N] + N + 1));
}