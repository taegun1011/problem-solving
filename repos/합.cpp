#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<string> arr;

ll calc(vector<int>& res){
    ll ret = 0;
    for(auto str : arr){
        ll base = 1;
        for(int i=str.length() - 1;i>=0;i--){
            ret+=base*res[str[i]-'A'];
            base*=10;
        }
    }
    return ret;
}

void solve() {
    cin >> N;
    arr = vector<string> (N);
    for(auto& str : arr)
        cin >> str;

    vector<ll> cnt(10);
    vector<bool> first(10);
    for(auto str : arr){
        ll base = 1;
        for(int i=str.length() - 1;i>=0;i--){
            cnt[str[i] - 'A'] += base;
            base *= 10;
            if(i == 0)
                first[str[i] - 'A'] = true;
        }
    }

    priority_queue<PII> pq;
    for(int i=0;i<10;i++)
        pq.push({cnt[i], i});
    vector<int> res(10);
    int cur = 9;
    int idx1 = 0, idx0 = 0;
    while(cur >= 0){
        auto p = pq.top();
        pq.pop();
        if(cur == 1)
            idx1 = p.second;
        if(cur == 0)
            idx0 = p.second;
        res[p.second] = cur--;
    }

    if(first[idx0])
        swap(res[idx1], res[idx0]);

    cout << calc(res) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}