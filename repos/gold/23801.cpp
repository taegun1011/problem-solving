#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define PLI pair<ll, int>
#define PII pair<int, int>
#define TLIB tuple<ll, int, bool>
#define MAX (int)1e6
#define INF 1e18

vector<PII> graph[MAX + 1];

//dist[i][0 / 1] : P�� �湮���� ���� / �湮�� i������ �ִܰŸ�
vector<vector<ll>> dist(MAX + 1, vector<ll>(2, INF));
set<int> P;

ll dijkstra(int S, int E) {

	//���, ������, �湮 ����
	priority_queue < TLIB, vector<TLIB>, greater<TLIB>> pq;
	dist[S][0] = 0;
	pq.push({ 0,S,0 });

	int u; ll w; bool f;

	while (!pq.empty()) {
		auto t = pq.top();
		w = get<0>(t);
		u = get<1>(t);
		f = get<2>(t);
		pq.pop();

		if (w != dist[u][f]) continue;

		for (auto next : graph[u]) {
			int v = next.first;
			int uv = next.second;
			bool flag = f || (P.find(v) != P.end());

			if (dist[v][flag] > w + uv) {
				dist[v][flag] = w + uv;

				pq.push({ dist[v][flag],v,flag });
			}
		}
	}

	return (dist[E][1] == INF ? -1 : dist[E][1]);
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;

	int u, v, w;
	while (M--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	int S, E;
	cin >> S >> E;

	int point, node;
	cin >> point;
	while (point--) {
		cin >> node;
		P.insert(node);
	}

	cout << dijkstra(S, E) << '\n';
}

//�����̶� ����ϰ� Ǯ�� �ɵ�
//���ͽ�Ʈ��� �ִܰ�� ������ ������ �˾Ƽ� ����ǹǷ� ���� �߰��� �������� ������ ����