#include <iostream>
#include <vector>
using namespace std;
int n, k;
int belt[202];
bool robot[202] = { 0 };
int start_pos = 0;
int end_pos;
int inital_robot_pos = -1;
int result = 1;
int cnt = 0;
bool stop = false;

void print() {
    cout << "START POS : " << start_pos << endl;

    cout << "BELT : ";
    for (int i = 0; i < n; i++)
        cout << belt[i] << ' ';
    cout << "\n       ";
    for (int i = 2 * n - 1; i >= n; i--)
        cout << belt[i] << ' ';
    cout << endl;

    cout << "ROBOT : ";
    for (int i = 0; i < n; i++)
        cout << robot[i] << ' ';
    cout << endl << endl;
}

void rotation_belt() {
    if (start_pos == 0) // 0�̸� �� ���� �ε����� �ű�
        start_pos = 2 * n - 1;
    else
        start_pos--;

    if (end_pos == 0) // 0�̸� �� ���� �ε����� �ű�
        end_pos = 2 * n - 1;
    else
        end_pos--;

    if (robot[end_pos])
        robot[end_pos] = false;
}

void move_robot() {
    if (inital_robot_pos != -1) {
        // ù��° �ܰ迡���� �κ��� ���� ������ �н�
        int idx = end_pos;
        for (int i = 0; i < n - 1; i++) {
            int next = idx; // �κ��� �� ���� ��ġ
            if (idx == 0)
                idx = 2 * n - 1; // ���� ��ġ      
            else
                idx--;

            if (!robot[next] && robot[idx] && belt[next] > 0) {
                // ���� ��ġ�� �κ��� ������
                // ���� ��ġ�� �κ� ���� �ϴ���
                // ���� ��ġ�� �������� 0���� ū��
                belt[next] -= 1; // ������ ����
                if (belt[next] == 0) { // �������� 0�̸�
                    cnt++; // ������ 0 ���� �߰�
                    if (cnt >= k) {
                        stop = true; // ���� flag
                        break;
                    }
                }
                robot[next] = true; // ���� ��ǥ �κ� true
                robot[idx] = false; // ���� ��ǥ �κ��� �Ű����� false
            }
        }
        robot[end_pos] = false; // ������ ��ġ �κ� ������

    }
}

void put_robot() {
    if (belt[start_pos] > 0) {
        belt[start_pos] -= 1; // ������ ����
        if (belt[start_pos] == 0) { // ���� ����
            cnt++;
            if (cnt >= k) {
                stop = true;
            }
        }
        robot[start_pos] = true; // �κ� �ø�
        inital_robot_pos = 0; // �κ� �ø��� ����.
    }
}

int main() {
    cin >> n >> k;
    int temp;
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i];
    }
    end_pos = n - 1;
    while (!stop) {
        cout << "ROTATE\n";
        rotation_belt();
        print();
        cout << "MOVE\n";
        move_robot();
        print();
        cout << "SET\n";
        put_robot();
        print();
        if (stop) // ����
            break;
        result++; // �ܰ� �ϼ�
    }
    cout << result << endl;
    return 0;
}
