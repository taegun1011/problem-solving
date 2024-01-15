#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define T tuple<int, PII, int>
#define INF 1e9

//������, ���
vector<PII> graph[801];

//0 : �湮 x, 1 : v1 �湮, 2 : v2 �湮, 3 : v1 v2 �湮
vector<vector<int>> dist(801, vector<int>(4, INF));

int V;

int dijkstra(int v1, int v2) {

	//�Ÿ�, �湮 Ƚ�� (��Ʈ����ŷ), ������
	priority_queue<T, vector<T>, greater<T>> pq;
	if (v1 == 1) {
		pq.push({ (dist[1][1] = 0), {1, 0}, 1 });
	}
	else
		pq.push({ (dist[1][0] = 0), {0, 0}, 1 });

	int u, w, flag1, flag2;
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		w = get<0>(t); auto p = get<1>(t); u = get<2>(t);
		flag1 = p.first, flag2 = p.second;

		if (dist[u][flag1 + flag2 * 2] != w) continue;

		for (auto next : graph[u]) {
			int v = next.first;
			int uv = next.second;
			int nflag1 = min(1, flag1 + (v == v1));
			int nflag2 = min(1, flag2 + (v == v2));
			int nflag = nflag1 + nflag2 * 2;

			if (dist[v][nflag] > w + uv) {
				dist[v][nflag] = w + uv;
				pq.push({ dist[v][nflag], {nflag1, nflag2}, v });
			}
		}
	}

	return dist[V][3] == INF ? -1 : dist[V][3];
}

int main() {
	FASTIO;
	int E;
	cin >> V >> E;

	int u, v, w;
	while (E--) {
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}

	int v1, v2;
	cin >> v1 >> v2;

	cout << dijkstra(v1, v2) << endl;
}

//��Ʈ����ũ ? �� ���'��' �ߺ� �湮�ϴ� ��Ȳ�� �����ؾ��Ѵ�. ���⿣ ���� ������ ������
//���ͽ�Ʈ��� ������ ���� �� Ȯ���ص� �������. ���̻� �ִܰ�ΰ� ���ŵ��� ���� �� ���� ��� �ݺ��ȴ�.