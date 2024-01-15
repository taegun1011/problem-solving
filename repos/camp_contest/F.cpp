#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
vector<vector<int>> graph(501, vector<int>(501));
vector<int> adj_list[501];

int DFS(int center) {
	//i�� �����ϰ� ���� ����� j, k�� ����
	//j, k�� ���� �ٸ��� i�� �����ϰ� ���� ����� l, m�� ����

	int ret = 0;

	//j�� ����
	for (int j : adj_list[center]) {

		//j�� ������ k�� ����
		for (int k : adj_list[j]) {
			if (k < j) continue;
			if (graph[k][center])

				//l�� ����
				for (int l : adj_list[center]) {
					if (l <= k) continue;

					//l�� ������ m�� ����
					for (int m : adj_list[l]) {
						if (m < l) continue;

						if (graph[m][center]) {
							ret++;
						}
					}
				}
		}
	}
	

	return ret;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	//c�� ��������
	//graph[i].size() >= 6 �� i�� ����
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (adj_list[i].size() >= 6) {

			//���� 2���� ���� ����� ��
			int wings = DFS(i);

			//������ �������� ������ 2���� ���� ����� ��
			int dudms = (adj_list[i].size() - 4) * (adj_list[i].size() - 5) / 2;
			cnt += wings * dudms;
		}
	}

	cout << cnt << endl;
}