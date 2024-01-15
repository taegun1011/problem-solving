#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> from[32001], to[32001];
int N, M;

//�ֻ�� ��� i�� ã��
//����ϰ� ���� ����

//�ݺ�
void solve() {
	queue<int> Q;

	for (int i = 1; i <= N; i++)
		if (from[i].empty())
			Q.push(i);

	int cur;
	while (!Q.empty()) {
		cur = Q.front(); Q.pop();
		cout << cur << ' ';

		for (int nxt : to[cur]) {
			from[nxt].erase(find(from[nxt].begin(), from[nxt].end(), cur));

			if (from[nxt].empty())
				Q.push(nxt);
		}
	}

	cout << endl;
}

int main() {
	FASTIO;

	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		to[u].push_back(v);
		from[v].push_back(u);
	}

	solve();
}