#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define PII pair<int, int>

//�� ���� (u, v)�� ����
//mx := max(dist[u], dist[v]), mn := min(dist[u], dist[v])��� ����
//mx�� �� ������ ���� ���� left = length - (mx - mn)
//������ ���ÿ� Ÿ�� ������ ������ left�� ��� Ż ������ �ɸ��� �ð� = left / 2 = (length + mn - mx) / 2
//������ ���ÿ� Ÿ�� �����ϴ� �ð� = mx
//���� ���� (u, v)�� ������ Ÿ�� �� �ɸ��� �ð��� (length + mn - mx) / 2 + mx = (length + mn + mx) / 2 = (length + dist[u] + dist[v]) / 2

void solve() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> dist(N, vector<int>(N, INF));
	for (int i = 0; i < N; i++)
		dist[i][i] = 0;

	vector<vector<int>> edges(M, vector<int>(3));
	for (auto& e : edges) {
		cin >> e[0] >> e[1] >> e[2];
		e[0]--;
		e[1]--;
		dist[e[0]][e[1]] = min(dist[e[0]][e[1]], e[2]);
		dist[e[1]][e[0]] = min(dist[e[1]][e[0]], e[2]);
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	double ans = INF;
	for (int i = 0; i < N; i++) {
		double mx = 0;
		for (auto e : edges) {
			int u = e[0], v = e[1], w = e[2];
			mx = max(mx, (0.0 + dist[i][u] + dist[i][v] + w) / 2);
		}
		ans = min(ans, mx);
	}

	printf("%.1lf\n", ans);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}