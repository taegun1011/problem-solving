#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9

int x, y;

int fibo[1000];

void fibonacci() {
	fibo[1] = 1;
	fibo[0] = 1;
	for (int i = 2; i < 1000; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int solve(int sc, int sr, int ec, int er) {
	int row = er - sr;
	int col = ec - sc;

	//������
	if (row < 1 || col < 1)
		return INF;

	if (row == col == 1) {
		if (sc == x && sr == y)
			return 1;
		else
			return INF;
	}

	//���� = 0, ���� = 1
	int flag, bigger = max(col, row);

	//����
	if (col > row) {
		flag = 0;
		col -= row;
	}
	else {
		flag = 1;
		row -= col;
	}

	//�ĸ��� �����ϰ� ���� ������ ��ġ�� ���
	if (flag == 0 && x >= sc + col && x < ec - col)
		return bigger;

	if (flag == 1 && y > sr + row - 1 && y <= er - row)
		return bigger;

	//���ο� ��ġ�� ���
	if (flag == 0) {
		if (x >= ec - col)
			return solve(ec - col, sr, ec, er);
		else
			return solve(sc, sr, sc + col, er);
	}
	
	if (flag == 1) {
		if (y > er - row)
			return solve(sc, er - row, ec, er);
		else
			return solve(sc, sr, ec, sr + row);
	}

}

int main() {
	FASTIO;
	fibonacci();

	//��������

	int a, b;
	cin >> a >> b;

	cin >> x >> y;

	int res = solve(0, 0, a, b);

	//2�� 1�� ����
	if (res <= 2) {
		cout << 1 << '\n';
		return 0;
	}

	for (int i = 1; i < 1000; i++)
		if (res == fibo[i])
			cout << i << '\n';
}