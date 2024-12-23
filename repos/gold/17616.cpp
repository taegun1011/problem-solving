#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> higher[100001], lower[100001];
bool visited[100001];
enum {high = 1, low};

int DFS(int node, int type) {
	int ret = 1;
	visited[node] = 1;

	//node�� ������ �� �׷������� Ž��
	if (type == high) {
		for (int next : lower[node]) {
			if (!visited[next])
				ret += DFS(next, type);
		}
	}
	else {
		for (int next : higher[node]) {
			if (!visited[next])
				ret += DFS(next, type);
		}

	}

	return ret;
}



int main() {
	FASTIO;
	int N, M, X;
	cin >> N >> M >> X;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		//higher : u�� v���� ����
		//lower : u�� v���� ����
		higher[u].push_back(v);
		lower[v].push_back(u);
	}

	int highest = DFS(X, high);

	memset(visited, 0, sizeof(visited));
	int lowest = N - DFS(X, low) + 1;

	cout << highest << ' ' << lowest << endl;

	//���� ��� : N - DFS_lower
	//�ְ� ��� : DFS_higher + 1
}

//������Ʈ ũ�⸦ ���Ϸ��� ret = 1�� �ʱ�ȭ�ؾ���