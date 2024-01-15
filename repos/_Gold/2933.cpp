#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

struct B
{
    int y, x;
    bool operator<(const struct B& o)const
    {
        // priorityQ�� �������� top�̴�.
        return y < o.y;
    }
};

int sizeX, sizeY;
const int SIZEMAX = 100;
char m[SIZEMAX][SIZEMAX];
int v[SIZEMAX][SIZEMAX];

const int INTMAX = 123456789;
int minDrop = INTMAX;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

priority_queue<B> moveQ;

void bfs(int cy, int cx, int visit)
{
    minDrop = INTMAX;
    priority_queue<B> visitQ;
    visitQ.push({ cy,cx });

    while (!visitQ.empty())
    {
        int cy = visitQ.top().y;
        int cx = visitQ.top().x;
        visitQ.pop();

        if (v[cy][cx])
            continue;
        v[cy][cx] = visit;
        moveQ.push({ cy,cx });

        int i = cy + 1;
        for (; i < sizeY; i++)
        {
            if (v[i][cx] == visit)
                break;
            if (m[i][cx] == 'x')
            {
                minDrop = min(minDrop, i - 1 - cy);
                cout << visit << ' ' << i << ' ' << cx << ' ' << minDrop << endl;
                break;
            }
        }
        if (i == sizeY) minDrop = min(minDrop, sizeY - 1 - cy);

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (nx < 0 || nx >= sizeX || ny < 0 || ny >= sizeY) continue;
            if (m[ny][nx] == '.') continue;
            if (v[ny][nx]) continue;
            visitQ.push({ ny,nx });
        }
    }
}

int main(int, char**)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> sizeY >> sizeX;
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            cin >> m[i][j];
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        h = sizeY - h;//h������. ����4�� h��3�̸� h�� 1�κ����ȴ�.

        // ������
        int x;
        if (i % 2 == 0) //����
        {
            x = 0;
            for (; x < sizeX; x++)
            {
                if (m[h][x] == 'x')
                    break;
            }
            if (x == sizeX) // not hit
                continue;
        }
        else // ������
        {
            x = sizeX - 1;
            for (; x >= 0; x--)
            {
                if (m[h][x] == 'x')
                    break;
            }
            if (x == -1) // not hit
                continue;
        }

        // �μ���
        m[h][x] = '.';
        memset(v, 0, sizeof(v));

        // ������������ �������� ���鼭 
        for (int j = 0; j < 4; j++)
        {
            int ny = h + dy[j];
            int nx = x + dx[j];
            if (nx < 0 || nx >= sizeX || ny < 0 || ny >= sizeY) continue;
            if (m[ny][nx] == '.') continue;
            if (v[ny][nx]) continue;
            bfs(ny, nx, j + 1); // visitó���ϸ鼭 moveQ���ְ�, minDrop ������
            if (minDrop == 0) // �������� �ʴ� Ŭ������
            {
                priority_queue<B>().swap(moveQ);
                continue;
            }
            else
            {
                while (!moveQ.empty())
                {
                    auto f = moveQ.top();
                    moveQ.pop();
                    m[f.y][f.x] = '.';
                    m[f.y + minDrop][f.x] = 'x';
                }
                break; // �� �� �Ǵ� �� �̻��� Ŭ�����Ͱ� ���ÿ� �������� ��쵵 ����.
            }
        }
    }

    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            cout << m[i][j];
        cout << endl;
    }

    return 0;
}