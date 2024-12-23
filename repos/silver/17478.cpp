#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
string underline = "____";

string chat[4] = { "\"����Լ��� ������?\"\n",
"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n" };

void recursion(int N, int diff) {

	if (diff == N) {
		for (int i = 0; i < diff; i++)
			cout << underline;
		cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < diff; i++)
			cout << underline;
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}

	else if (diff < N) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < diff; j++)
				cout << underline;
			cout << chat[i];
		}
	}

	else return;
	
	recursion(N, diff + 1);

	for (int i = 0; i < diff; i++)
		cout << underline;
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	FASTIO;
	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursion(N, 0);
}