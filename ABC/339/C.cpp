#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll s = 0, m = 0;
    for (ll x : A) {
        s += x;
        m = min(m, s); // 最小値の更新
    }

    cout << s - m << endl; // mが0になるように調整

    return 0;
}