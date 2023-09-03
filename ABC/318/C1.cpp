#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main() {
    // 入力
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);
    rep(i, N) cin >> F[i];

    // ソート
    sort(F.begin(), F.end());

    // 累積和の計算
    vector<ll> S(N+1);
    S[0] = 0;
    rep(i, N) S[i+1] = S[i] + F[i];

    // 回数券を買う回数で全探索
    ll ans = INF;
    rep(i, 1e9) {
        int r = max(0, N - i * D);
        ll now = S[r] + (ll)P * i;
        ans = min(ans, now);
        if (r == 0) break;
    }

    cout << ans << endl;
    return 0;
}
