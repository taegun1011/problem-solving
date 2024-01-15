#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9
#define MAX 20000

vector<PII> graph[MAX + 1];
vector<int> dist(MAX + 1, INF);

int V, E;

void dijkstra(int start) {
	//���, ��� ������ �����Ѵ�
	priority_queue<PII, vector<PII>, greater<PII>> pq;

	//�ʱ�ȭ
	dist[start] = 0;
	pq.push({ 0, start });

	int w, u;
	while (!pq.empty()) {
		//pq���� ����� ���� ���� ���Ҹ� ������
		w = pq.top().first;
		u = pq.top().second;
		pq.pop();

		if (dist[u] != w) continue;

		for (auto next : graph[u]) {
			int v = next.first, uv = next.second;

			//���� ��带 ������ �� �Ÿ� ������ �ȴٸ�
			//�Ÿ��� �����ϰ� ť�� �ִ´�
			if (w + uv < dist[v]) {
				dist[v] = w + uv;
				pq.push({ w + uv, v });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> V >> E;

	int K; cin >> K;

	int u, v, w;

	//�ߺ� ������ ���� �Է�
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		graph[u].emplace_back(v, w);
	}

	dijkstra(K);
	for (int i = 1; i <= V; i++)
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
}

//���̽�Ʈ�� ���� (pq ��� ����)
//pq : <���, ������>
//pq ����� ���, visited �ʿ���� �ּҺ�븸 ������ �ʿ� ����
//�ִ� �Ÿ� ������ �Ϸ�Ǹ� �˾Ƽ� pq�� ��� ����