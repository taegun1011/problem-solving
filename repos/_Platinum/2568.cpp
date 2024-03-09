#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9

void solve() {
	int N;
	cin >> N;

	vector<PII> arr(N);
	for (PII& p : arr)
		cin >> p.first >> p.second;
	sort(arr.begin(), arr.end());

	vector<int> lis(N, INF);

	//���� arr[i].second�� lis�� ����
	vector<int> len(N);

	for (int i = 0; i < N;i++) {
		PII p = arr[i];
		//��ġ�� �ʴ´ٴ� ������ �ֱ� ������ �¾����� lb�� �ؾ� �´�
		int pos = lower_bound(lis.begin(), lis.end(), p.second) - lis.begin();
		lis[pos] = p.second;
		len[i] = pos;
	}
	
	int ans = lower_bound(lis.begin(), lis.end(), INF) - lis.begin();
	cout << N - ans << endl;

	vector<bool> used(N);

	//��θ� �̷��� ã�ƾ� �ϴ� ����
	//lis �迭�� �ܼ��� lis�� ��� ���Ҹ� ������ �۰� �����ϴ� ��ɸ� �����ϹǷ�,
	//�� ���� ��ġ�� �ּڰ��� �迭�� �� �տ� ����Ǵ� �͵� �����ϴ�. �׷��� �� ���Ҵ� ���� �ؿ� ���Ե��� �ʴ´�.

	//�˰����� ��� ���ҿ� ���� �� ������ �����ϱ� ������ ���Ұ� ����Ǵ� ��ġ�� ������ �ʴ´�.
	//���� �� ���ҿ� ���� lis�� ����Ǵ� ��ġ�� ����Ѵ�.
	//�ظ� �ڿ������� ã�� ������ ���ʺ��� �������� �� ���� ���� ���õǴ� ���Ҵ� �ݵ�� �ؿ� ���Ե��� ����Ǳ� �����̴�

	//����
	//arr : 10 20 0 5 15 25
	//len : 1  2  1 2 3  4
	//�տ������� ã���� 10 20 15 25�� ���´�
	for (int i = N - 1; i >= 0; i--) {
		if (len[i] + 1 == ans) {
			used[i] = true;
			ans--;
		}
	}

	for (int i = 0; i < N; i++)
		if (!used[i])
			cout << arr[i].first << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}