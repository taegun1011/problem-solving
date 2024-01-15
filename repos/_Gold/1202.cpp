#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

//�� ���濡 ���� �� �ִ� ���� �� ���� ��� ������ ����

int main() {
	FASTIO;

	int N, K;
	cin >> N >> K;
	vector<PII> J(N);

	for (int i = 0; i < N; i++)
		cin >> J[i].first >> J[i].second;

	sort(J.begin(), J.end());

	vector<int> B(K);
	for (int i = 0; i < K; i++)
		cin >> B[i];

	sort(B.begin(), B.end());

	//����
	priority_queue<int> pq;

	ll res = 0;
	int idx = 0;
	for (int i = 0; i < K; i++) {

		while (idx < N && J[idx].first <= B[i])
			pq.push(J[idx++].second);

		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << endl;
}