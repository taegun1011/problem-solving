#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> v;
int N;

void LIS() {
	vector<int> lis;
	lis.push_back(v[0]);

	for (int i = 1; i < N; i++) {
		//�Ź� v[i]�� �� �� �ִ� ��ġ�� ã�´�
		//���� ��ġ�� ������ v[i]�� ������ �ٲ��ش�
		//��ġ�� �߰����� ������ ��� �� ���� �߰��Ѵ�
		vector<int>::iterator pos = lower_bound(lis.begin(), lis.end(), v[i]);
		if (pos == lis.end())
			lis.push_back(v[i]);
		else
			lis[pos - lis.begin()] = v[i];
	}

	cout << lis.size() << endl;
}

int main() {
	FASTIO;

	cin >> N;
	
	v.resize(N);
	for (int& i : v)
		cin >> i;

	LIS();
}

//LIS��� dp�� Ǯ����ϴ� �� �ƴϴ�
//O(N log N) Ǯ��
//'���� LIS�� �����'��°� ����Ʈ