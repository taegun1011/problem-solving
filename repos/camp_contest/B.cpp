#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int N;
	cin >> N;
	vector<int> v(N);

	for (int& i : v)
		cin >> i;

	//����, �� ������ ������
	sort(v.begin(), v.end());

	int small = 0, big = 0;
	int si = 0, bi = v.size() - 1;
	while (si < bi) {
		big += v[bi--];
		small += v[si++];
	}

	//N�� Ȧ��
	if (si == bi)
		big += v[bi];

	cout << small << ' ' << big << '\n';
}