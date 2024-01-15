#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, i;
	cin >> N >> M;

	vector<string> v;
	string str;
	for (i = 0; i < N; i++) {
		cin >> str; cin >> str;
		v.push_back(str);
	}
	int max = 0, cnt = -1;

	int guitar, song;
	for (int i = 0; i < (1 << N); i++) {
		vector<int> vis(M);
		guitar = song = 0;

		//i : ��� ������ ��Ÿ�� ����
		//j : ����ϴ� ��Ÿ
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				guitar++;
				for (int k = 0; k < M; k++) {
					if (v[j][k] == 'Y' && vis[k] == 0) {
						vis[k] = 1;
						song++;
					}
				}
			}
		}

		if (song > max) {
			//���� ������ �� �������� cnt ����
			max = song;
			cnt = guitar;
		}
		else if (song == max && cnt > guitar) {
			//���� ������ ������ ���� cnt�� �ּҰ�����
			cnt = guitar;
		}
	}

	cout << cnt << endl;
}
