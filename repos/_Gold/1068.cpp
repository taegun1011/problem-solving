#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<int>> graph;
int N, K;

int count(int root) {
	//��Ʈ�� ������ Ʈ���� ����
	if (root == K)
		return 0;

	//���� ��� 1 : �ڽ� ��尡 ����
	if (!graph[root].size())
		return 1;

	int ret = 0;
	for (int child : graph[root])
		ret += count(child);

	//���� ��� 2 : �ڽ��� �ִµ� K������ ������尡 0
	if (!ret)
		ret++;

	return ret;
}

void solve() {
	cin >> N;

	graph = vector<vector<int>>(N, vector<int>());
	int rt = 0;
	for (int i = 0; i < N; i++) {
		int par;
		cin >> par;
		if (par < 0)
			rt = i;
		else
			graph[par].push_back(i);
	}

	cin >> K;
	cout << count(rt) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}