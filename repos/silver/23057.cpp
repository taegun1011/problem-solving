#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> S;
	//���Ʈ����, �� �� ���� ������ set ���� + �� ���� S�� �߰�

	int N;
	cin >> N;

	int val, sum = 0;

	//�ʱ� Set ����
	for (int i = 0; i < N; i++) {
		cin >> val;
		set<int> temp;
		//������� ������ �ӽ� ���� temp

		for (int j : S)
			temp.insert(j + val);

		for (int j : temp)
			S.insert(j);

		S.insert(val);
		sum += val;
	}
	cout << sum - S.size() << endl;
	
}