#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int arr[1000005];

void solve() {
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        arr[i] = i;

    int x, y;
    while(M--){
        cin >> x >> y;
        arr[x] = max(arr[x], y);
    }

    int ans = 0, e = 0;
    for(int i=1;i<=N;i++){
        if(e < i)
            ans++;
        e = max(e, arr[i]);
    }

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}