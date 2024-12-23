#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int main() {
	FASTIO;

	int N, K;
	cin >> N >> K;

	//����, ����
	priority_queue<PII> pq;

	for (int i = 0; i < N; i++) {
		int v, w;
		cin >> w >> v;
		pq.push({ v, w });
	}

	multiset<int> MS;

	for (int i = 0; i < K; i++) {
		int bag;
		cin >> bag;
		MS.insert(bag);
	}

	ll res = 0;
	while (!pq.empty()) {

		//���� ��� ����
		PII cur(pq.top());
		int v = cur.first, w = cur.second;
		pq.pop();

		//���� �� �ִ� ������ ��ġ
		multiset<int>::iterator iter = MS.lower_bound(w);

		if (iter != MS.end()) {
			res += v;
			MS.erase(iter);
		}

		if (MS.empty()) break;
	}

	cout << res << endl;
}

//multiset ����
//lower_bound�� ���� �޼ҵ�� ����ؾ� O(log n)
//erase ����� ������ �ϸ� �ش� ���� ���� �����ϴ� �ϳ��� �� ���� �ݺ��ڷ� �ؾ���