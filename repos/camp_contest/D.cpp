#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PIS pair<int, string>

vector<PIS> v;

//õ��
int CG[10][10];

//����
int GG[12][12];

int cg(string a, string b) {
	return CG[a[0] - '0'][b[0] - '0'];
}

int gg(string a, string b) {
	return GG[a[1] - 'A'][b[1] - 'A'];
}

int getSum(PIS a, PIS b) {
	return cg(a.second, b.second) + gg(a.second, b.second);
}

int getTripleSum(PIS a, PIS b, PIS c) {
	return getSum(a, b) + getSum(b, c) + getSum(c, a) + a.first + b.first + c.first;
}

int N;

void solve() {
	//1000000C3 == 10^18 �ʹ� �����ɸ�

	//�ѹ��� Ȯ�� �����Ѱ�? �� ������
	int res = getTripleSum(v[0], v[1], v[2]);
	vector<PIS> ans = { v[0], v[1], v[2] };

	//���� ���� �� �Ѱ� �� ����� ������ ��
	for (int i = 3; i < N; i++) {
		vector<PIS> temp(ans);
		for (int j = 0; j < 3; j++) {
			int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;

			//�� ���
			if (res < getTripleSum(temp[idx1], temp[idx2], v[i])) {
				ans[j] = v[i];
				res = getTripleSum(temp[idx1], temp[idx2], v[i]);
			}
		}
	}

	//�Ʊ� ����� ������ �ִ��� ���� �ִ�

	cout << res << endl;
}

int main() {
	FASTIO;
	cin >> N;

	//�Է�
	for (int i = 0; i< 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> CG[i][j];

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			cin >> GG[i][j];

	int n; string str;
	for (int i = 0; i < N; i++) {
		cin >> n >> str;
		v.push_back({ n,str });
	}

	solve();
}