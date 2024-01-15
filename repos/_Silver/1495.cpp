#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, S, M;
vector<int> v;

map<int, int> dp[51];

//n�� 0���� M�����ΰ�?
bool inRange(int n) {
	return n >= 0 && n <= M;
}

int solve() {
	dp[0][S]++;

	//dp[i-1]�� ���� ��ȸ�ϸ� ������ ���� ��� �߰��Ѵ�.
	for (int i = 1; i <= N; i++) {
		for (auto j : dp[i-1]) {
			if (inRange(j.first + v[i]))
				dp[i][j.first + v[i]]++;
			if (inRange(j.first - v[i]))
				dp[i][j.first - v[i]]--;
		}
		if (dp[i].empty())
			return -1;
	}

	int max = -1;
	for (auto i : dp[N])
		if (i.first > max)
			max = i.first;

	return max;
}

int main() {
	cin >> N >> S >> M;

	int val;
	v.push_back(-1);
	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}

	cout << solve() << endl;
}

//��ȭ���� 0,1 2���� ����ϴ� ���� �ƴ϶� ���� ���� ��� �����ϴ� ���� �ٽ�!
//���� �ߺ��� ���� ���� �ؽ����� ��������� checked �迭�� ����ص� �� ��