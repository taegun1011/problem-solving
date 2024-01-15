#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int TC, n;

	char op; int val, type; //type : 1, -1
	cin >> TC;

	while (TC > 0) {
		TC--;
		cin >> n;

		priority_queue<int, vector<int>> maxH;
		priority_queue<int, vector<int>, greater<int>> minH;
		map<int, int> M;

		while (n > 0) {
			n--;
			cin >> op;
			
			if (op == 'I') {
				cin >> val;
				minH.push(val);
				maxH.push(val);

				M[val]++;
			}
			else if (op == 'D') {
				cin >> type;

				//�ִ� �� ����
				if (type == 1) {
					//���� ���� �Ǿ��־�� �� �ڷḦ Ȯ���Ͽ� ����
					while (!maxH.empty() && M[maxH.top()] == 0) maxH.pop();

					//���� top ����
					if (!maxH.empty()) {
						M[maxH.top()]--;
						maxH.pop();
					}
				}

				//�ּ� �� ����
				else if (type == -1) {
					//���� ���� �Ǿ��־�� �� �ڷḦ Ȯ���Ͽ� ����
					while (!minH.empty() && M[minH.top()] == 0) minH.pop();

					//���� top ����
					if (!minH.empty()) {
						M[minH.top()]--;
						minH.pop();
					}
				}
			}
		}
		while (!maxH.empty() && M[maxH.top()] == 0) maxH.pop();
		while (!minH.empty() && M[minH.top()] == 0) minH.pop();

		if (maxH.empty() || minH.empty())
			cout << "EMPTY" << endl;
		else
			cout << maxH.top() << ' ' << minH.top() << endl;
	}

}