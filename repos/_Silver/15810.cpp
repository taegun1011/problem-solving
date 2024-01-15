#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> v;

ll compute(ll time) {
	ll sum = 0;
	for (int i : v)
		sum += time / i;

	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	ll start = 0, end = 1e12, mid;
	while (start < end) {
		mid = (start + end) / 2;
		ll balloon = compute(mid);
		if (balloon >= M)
			end = mid;
		else
			start = mid + 1;
	}

	cout << end << endl;
}

//�̺�Ž���� �� Ȱ���ϴ°�?
//�ڱ��ڽ��� �����ϴ� �̺�Ž�� - ���� ������ (start '<' end)��
//���� �� �ִ� �ִ� (Ž�� ����)�� �ľ��ϱ�
//10�� ������ ǥ�� : 1ek
//������ decision �Լ� (bool ��ȯ)