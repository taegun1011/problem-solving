#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

char op[5] = { '+','-','*','/','('};
int precedence[5] = { 1,1,2,2,3 };

stack<string> Operand;
stack<char> Operator;

void PMP(); //Pop, Merge, Push

bool isOperator(char);
int getPrec(char);

int main() {
	char ch;
	string temp;

	while ((ch = getchar()) != '\n') {

		//�ݴ� ��ȣ
		if (ch == ')') {
			//ó�� ���� ��ȣ�� ���� ������ PMP
			while (Operator.top() != '(') PMP();
			Operator.pop();
		}

		//������
		else if (isOperator(ch)) {
			//���� top �������� �켱������ �� �������� �켱�������� ũ�ų� ���� ���
			while (!Operator.empty() && Operator.top() != '(' && (getPrec(Operator.top()) >= getPrec(ch))) PMP();
			Operator.push(ch);
		}

		//�ǿ�����
		else {
			temp = ch;
			Operand.push(temp);
		}
	}

	//������ 1�� ��
	while (!Operator.empty())
		PMP();

	cout << Operand.top() << endl;
}

bool isOperator(char ch) {
	return (find(op, op + 5, ch) != (op + 5));
}

int getPrec(char ch) {
	return precedence[find(op, op + 5, ch) - op];
}

void PMP() {
	if (Operator.top() == '(') return;
	string op1 = Operand.top(); Operand.pop();
	string op2 = Operand.top(); Operand.pop();
	char oper = Operator.top(); Operator.pop();

	Operand.push(op2 + op1 + oper);
}