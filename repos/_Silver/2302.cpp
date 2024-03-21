#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//type : ���� ĭ�� ���� ĭ�� ����°�
//0 : �Ѵ� ��, 1 : ���� ��, 2 : ���� ��
int dp[41][3];
int N;
vector<bool> vip;

//���縸 ������� ��� -> ����, �����ʿ� ���� �� �ִ� -> ���� ĭ ���� 2, 1
//�Ѵ� ������� ��� -> ����, ����, �����ʿ� ���� �� �ִ� -> ���� ĭ ���� 0, 2, 1
//���ʸ� ������� ��� -> ���ʿ� ���� �� �ִ� -> ���� ĭ ���� 2
int re_dp(int cur, int type) {
	if (cur > N)
		return type == 2;

	if (dp[cur][type] != -1)
		return dp[cur][type];
	int& ret = dp[cur][type];

	if (vip[cur]) {
		if (type == 1)
			ret = 0;
		else
			ret = re_dp(cur + 1, 2);
	}
	else {
		if (type == 0)
			ret = re_dp(cur + 1, 0) + re_dp(cur + 1, 1) + re_dp(cur + 1, 2);
		else if (type == 1)
			ret = re_dp(cur + 1, 2);
		else
			ret = re_dp(cur + 1, 2) + re_dp(cur + 1, 1);
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int M;
	cin >> N >> M;
	vip.resize(N + 1);

	while (M--) {
		int v;
		cin >> v;
		vip[v] = 1;
	}

	cout << re_dp(1, 2) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}