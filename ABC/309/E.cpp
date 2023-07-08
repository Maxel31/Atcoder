#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for(int i = 1; i < N; i++){
        cin >> P[i];
        P[i]--;
    }

    // dp[i]: 人iは最大何代先案で保証対象者か
    vector<int> dp(N, -1);

    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--;
        dp[x] = max(dp[x], y);
    }

    for(int i = 1; i < N; i++){
        dp[i] = max(dp[i], dp[P[i]]-1);
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(dp[i] >= 0) ans++;
    }

    cout << ans << endl;
    return 0;
}