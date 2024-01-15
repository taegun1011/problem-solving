#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> v;
vector<int> idx(1000001);
int N;

void LIS() {
	vector<int> lis;

	lis.push_back(v[0]);
	idx[0] = 1;

	for (int i = 1; i < N; i++) {
		vector<int>::iterator pos = lower_bound(lis.begin(), lis.end(), v[i]);
		if (pos == lis.end()) {
			lis.push_back(v[i]);
			idx[i] = lis.size();
		}
		else {
			lis[pos - lis.begin()] = v[i];
			idx[i] = pos - lis.begin() + 1;
		}
	}

	int cur;
	cout << (cur = lis.size()) << endl;
	
	stack<int> ans;

	for (int i = N - 1; i >= 0; i--) {
		if (idx[i] == cur) {
			ans.push(v[i]);
			cur--;
		}
	}

	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
		cout << (ans.empty() ? '\n' : ' ');
	}
}

int main() {
	FASTIO;

	cin >> N;

	v.resize(N);
	for (int& i : v)
		cin >> i;

	LIS();
}

//�� ���Ұ� LIS���� ��ġ�ϴ� (�Ҽ��ִ�) �ε����� ����
//�Ųٷ� Ȯ���ϸ鼭 ������ �´� �� �� ���� ���� ������ ���� ���
//�� Ǯ�̸� �ٸ� �� �������� �� ������ �� ������ ��