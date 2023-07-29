#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

ll MOD = 998244353;
string S;

int main() {
    cin >> S;
    int N = S.size();
    vector<vector<ll>> dp(N+1, vector<ll>(N+1)); 
    // dp(i,j) : i文字目まで見たときに、各k(1 <= k <= i)に対して,num('(') >= num(')) かつ 
    // num('(') >= num(')) = j となるような文字列の個数
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i] != ')') dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+1] %= MOD;
            if(j != 0 && S[i] != '(') dp[i+1][j-1] += dp[i][j];
            dp[i+1][j-1] %= MOD;
        }
    }
    cout << dp[N][0] << endl;
    return 0;
}
