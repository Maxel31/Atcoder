#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i++) cin >> X[i] >> Y[i];
    ll dp[300009][2]; // i品目食べた状態がjの時の最大値

    // 初期化
    for(ll i = 0; i <= N; i++) {
        dp[i][0] = -99999999;
        dp[i][1] = -99999999;
    }
    dp[0][0] = 0;
    dp[0][1] = -99999999;

    for(ll i = 0; i < N; i++){
        // i品目の料理を食べる場合
        if(X[i] == 0) dp[i+1][0] = max(dp[i][0], max(dp[i][0], dp[i][1]) + Y[i]);
        if(X[i] == 1) dp[i+1][1] = max(dp[i][1], dp[i][0] + Y[i]);

        // i品目の料理を食べない場合
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}