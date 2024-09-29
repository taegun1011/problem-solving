#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;

    int a, b;
    while(M--){
        cin >> a >> b;

        int common = min(a, b), left = N - common;
        a -= common; b -= common;
        if(a){
            cout << (a <= left / 2 + 1);
        }else if(b){
            cout << (b <= (left + 1) / 2);
        }
        else
            cout << 1;
        cout << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}