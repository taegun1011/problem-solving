#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//No. 24 ���� ����
int solve() {
	int n, p;
	cin >> n >> p;

	int ans = 1 + p;

	vector<int> arr(n);
	for (int& x : arr)
		cin >> x;

	int i = 0, j = 1;
	while (j < n && i < j) {
		//��ü arr[j] - arr[i] + 1�� �� j - i + 1���� ������ ���θ� ������, �������� p�� ä���� �Ѵ�
		int diff = arr[j] - arr[i] + i - j;
		if (diff <= p)
			//������ ��������, ���� p (p - diff)��ŭ �Ⱓ�� �ø� ���� �ִ�
			ans = max(ans, arr[j++] - arr[i] + 1 + p - diff);
		else
			i++;
	}
	
	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}

}