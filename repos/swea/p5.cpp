#include <vector>
#include <list>
using namespace std;

#define PII pair<int, int>

vector<int> team;
list<PII> score[6][6];
vector<int> version;
int cur;

//No. 5 [Pro] �������
// �ٽ� ���̵�� 1 : updateTeam �Լ��� 'addAll' ������ ���� ���� ����
// �ٽ� ���̵�� 2 : addAll�� ���Ḯ��Ʈ�� splice �Լ��� ������ ����
// �ٽ� ���̵�� 3 : �ڷ��� ��ȿ�� ���θ� visited ��� '����'���� Ȯ���ϱ� -> �� ������ ���ѵ� �����ϱ�?

void init()
{
	team = vector<int>(100001);
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			score[i][j] = list<PII>();
	version = vector<int>(100001);
	cur = 0;
}

void hire(int mID, int mTeam, int mScore)
{
	team[mID] = mTeam;
	version[mID] = cur++;
	score[mTeam][mScore].push_back({ mID, version[mID] });
}

void fire(int mID)
{
	version[mID] = -1;
}

void updateSoldier(int mID, int mScore)
{
	version[mID] = cur++;
	score[team[mID]][mScore].push_back({ mID, version[mID] });
}

void updateTeam(int mTeam, int mChangeScore)
{
	if (mChangeScore < 0) {
		for (int i = 1; i <= 5; i++) {
			int j = i + mChangeScore;
			j = j < 1 ? 1 : j;
			if (i == j)
				continue;
			score[mTeam][j].splice(score[mTeam][j].begin(), score[mTeam][i]);
		}
	}
	else {
		for (int i = 5; i >= 1; i--) {
			int j = i + mChangeScore;
			j = j > 5 ? 5 : j;
			if (i == j)
				continue;
			score[mTeam][j].splice(score[mTeam][j].begin(), score[mTeam][i]);
		}
	}
}

int bestSoldier(int mTeam)
{
	int max_id = 0;
	for (int i = 5; i >= 1; i--) {
		bool found = false;
		for (PII p : score[mTeam][i]) {
			int id = p.first, v = p.second;
			if (version[id] != v)
				continue;
			found = true;
			max_id = id > max_id ? id : max_id;
		}
		if (found)
			break;
	}

	return max_id;
}