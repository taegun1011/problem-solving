#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define N 9
bool found = false;

vector<string> v(N + 1);

//R[i][j] : i�࿡ j�� �̹� �ִ°�?
vector<vector<bool>> R(N + 1, vector<bool>(N + 1));

//C[i][j] : i���� j�� �̹� �ִ°�?
vector<vector<bool>> C(N + 1, vector<bool>(N + 1));

//SQ[i][j] : i�� �簢���� j�� �̹� �ִ°�?
vector<vector<bool>> SQ(N + 1, vector<bool>(N + 1));

int findSQ(int row, int col) {
	return 1 + (row - 1) / 3 * 3 + (col - 1) / 3;
}

void recursion(int sr, int sc) {
	if (found) return;

	//���� 0 ��ġ �̵�
	int nr = sr, nc = sc;
	while (nr < 10 && v[nr][nc] != '0') {
		if (nc == 9) {
			nc = 1; nr++;
		}
		else
			nc++;
	}

	//�ϼ����� ���
	if (nr == 10) {
		found = 1;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++)
				cout << v[i][j];
			cout << '\n';
		}

		return;
	}

	//���� �� �ִ� ���� �ִ°�
	for (int num = 1; num <= 9; num++) {

		//������ ������ ������ ���
		if (!R[nr][num] && !C[nc][num] && !SQ[findSQ(nr, nc)][num]) {
			v[nr][nc] = num + '0';

			R[nr][num] = C[nc][num] = SQ[findSQ(nr, nc)][num] = 1;

			recursion(nr, nc);

			v[nr][nc] = '0';
			R[nr][num] = C[nc][num] = SQ[findSQ(nr, nc)][num] = 0;
		}
	}
}

void solve() {

	//�Է�
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		v[i] = " " + str;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			//�̹� ä���� ĭ ����
			if (v[i][j] != '0') {
				R[i][v[i][j] - '0'] = 1;
				C[j][v[i][j] - '0'] = 1;
				SQ[findSQ(i, j)][v[i][j] - '0'] = 1;
			}
		}
	}

	recursion(1, 1);
}

int main() {
	FASTIO;

	solve();
}

//toggle�� (!visited[i]) Ȱ���ϸ� ����ϰ� ����
//toggle�� ���ֹǷ� ���� shallow copy�� �ʿ䰡 ����.