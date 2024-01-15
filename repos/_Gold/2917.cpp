#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define INF 1e9

vector<string> graph(501);

//���ͽ�Ʈ���
vector<int> dist(250001, INF);
vector<int> tree;

//BFS��
int visited[250001];

//BFS ���Ž����
int path[250001];
int N, M;

bool inRange(int num) {
	return 0 <= num && num < N * M;
}

bool compare(PII a, PII b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

void dijkstra() {
	//2������ 1��������
	//�����̵� : M, �¿� �̵� : 1
	int dir[4] = { -M, 1, M, -1 };

	//���, ������
	priority_queue<PII, vector<PII>, greater<PII>> pq;

	for (int tr : tree) {
		pq.push({ (dist[tr] = 0), tr });
	}

	int u, w;
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		w = t.first, u = t.second;
		if (dist[u] != w) continue;

		for (int i = 0; i < 4; i++) {
			int v = u + dir[i];
			if (!inRange(v)) continue;

			//���� �̵��� ���� �ٿ�����
			if ((i == 1 && v % M == 0) || (i == 3 && v % M == M - 1)) continue;

			if (dist[v] > w + 1) {
				dist[v] = w + 1;
				pq.push({ dist[v], v });
			}
		}
	}
}

int BFS(int S, int E) {
	int dir[4] = { -M, 1, M, -1 };

	queue<int> Q;
	Q.push(S);
	visited[S] = 1;

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		if (cur == E) {
			int ret = dist[E];
			while (cur != S) {
				cur = path[cur];
				ret = min(ret, dist[cur]);
			}

			return ret;
		}

		//dist��, ��ġ
		vector<PII> v;

		//���ͽ�Ʈ��� �����ϰ� �̵�
		for (int i = 0; i < 4; i++) {
			int next = cur + dir[i];

			if (!inRange(next)) continue;
			if ((i == 1 && next % M == 0) || (i == 3 && next % M == M - 1)) continue;

			if(!visited[next])
				v.push_back({ dist[next], next });
		}

		sort(v.begin(), v.end(), compare);

		//dist���� �ִ��� ���⿡ ���ؼ��� BFS
		if (!v.empty()) {
			int mn = v[0].first;
			for (auto p : v) {
				if (p.first != mn) break;

				int next = p.second;

				visited[next] = 1;
				path[next] = cur;
				Q.push(next);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	int S, E;
	for (int i = 0; i < N; i++) {
		cin >> graph[i];
		//multi-source dijkstra
		for (int j = 0; j < M; j++) {
			int pos = i * M + j;
			if (graph[i][j] == '+')
				tree.push_back(pos);
			if (graph[i][j] == 'V')
				S = pos;
			if (graph[i][j] == 'J')
				E = pos;
		}
	}

	dijkstra();

	cout << BFS(S, E) << '\n';
}