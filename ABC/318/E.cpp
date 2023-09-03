#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

ll c3(ll n){
    return n * (n-1) * (n-2) / 6;
}

int main(){
    int N; 
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> cnt(N+1, 0); // 個数
    vector<ll> sum(N+1, 0); // i
    ll ans = 0;

    // Σ(k)Σ(i) (k-i-1) = Σ(k) ((k-1)Σ(i) - Σ(i))
    rep(k, N){
        ans += ll(k-1) * cnt[A[k]] - sum[A[k]];
        cnt[A[k]]++;
        sum[A[k]] += k;
    }

    rep(i, N) ans -= c3(cnt[i+1]); // 条件.3を満たさないものを引く
    cout << ans << endl;
    return 0;
}