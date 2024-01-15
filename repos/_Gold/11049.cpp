#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int N;
vector<PII> v;

//dp[i][j] : i�� ��ĺ��� j�� ��ı��� ���ϴ� �� ���� Ƚ���� �ּڰ�
int dp[501][501];

void solve() {

	//setup : ������ �� ���
	for (int i = 0; i < N - 1; i++)
		dp[i][i + 1] = v[i].first * v[i].second * v[i + 1].second;

	//k : ���ϴ� ������ ����
	for (int k = 2; k < N; k++) {
		//���� ��ġ, i + k : ������
		for (int i = 0; i < N - k; i++) {
			int min = INT_MAX;

			//�߰�
			for (int j = i; j < i + k; j++) {
				int temp = dp[i][j] + dp[j + 1][i + k] + v[i].first * v[j + 1].first * v[i + k].second;
				if (min > temp)
					min = temp;
			}

			dp[i][i + k] = min;
		}
	}

	cout <<  dp[0][N - 1] << endl;
}

int main() {
	FASTIO;
	
	cin >> N;
	
	int r, c;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		v.push_back({ r,c });
	}

	solve();
}