#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<ll> Q(N), A(N), B(N);
    rep(i, N) cin >> Q[i];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    ll ans = 0;
    for (ll x = 0; x <= *max_element(Q.begin(), Q.end()); ++x) {
        ll y = INF;
        rep(i, N) {
            if (Q[i] < A[i] * x) {
                y = -INF;
                break; // これ以上のxでは料理を作れないため、ループを抜ける
            } else if (B[i] > 0) {
                y = min(y, (Q[i] - A[i] * x) / B[i]);
            }
        }
        ans = max(ans, x + y);
    }
    cout << ans << endl;
    return 0;
}