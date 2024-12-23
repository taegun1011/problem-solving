#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph(501, vector<int>(501)), dp(501, vector<int>(501, -1));
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

//�׳� DFS�� ������ ���� ���´�
//�޸������̼��� Ȱ���� �� ������?
//���� �̹� ���� �����ϸ� (dp[i][j] != -1) �� ���� Ȱ���Ѵ�

bool inRange(int num) {
	return num >= 0 && num < N;
}

int DFS(int row, int col) {
	int res = 1;

	for (int i = 0; i < 4; i++) {
		int nr = row + dir[i][0];
		int nc = col + dir[i][1];
		if (inRange(nr) && inRange(nc) && graph[row][col] < graph[nr][nc]) {
			if (dp[nr][nc] != -1) {
				res = max(res, dp[nr][nc] + 1);
			}
			else
				res = max(res, DFS(nr, nc) + 1);
		}
	}

	return dp[row][col] = res;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];


	int res = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			res = max(res, DFS(i, j));

	cout << res << endl;
}

//�޸������̼� -> �̹� ����ص� ���� �����س��� Ȱ���ϸ� �ȴ�
//Ž�� ����� Ư�� ������ �����ϸ� visited�� �ʿ����� ���� ���� �ִ�.
//���⼭�� ��� �ڽź��� ū �����θ� �̵��ϹǷ�, ���� ���� ���� �� �湮�� ���� ������, ���ѷ����� ������ �ʴ´�