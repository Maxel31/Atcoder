#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 入力
    ll N, Q;
    cin >> N;
    ll A[200009], l[200009], r[200009];
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for (ll i = 1; i <= Q; i++) {
        cin >> l[i] >> r[i];
    }
    
    // 累積和を用いて睡眠時間を計算
    map<ll, ll> sleep_sum;
    for (ll i = 1; i <= N; i++){
        sleep_sum[A[1]] = 0;
        if (i % 2 == 0) {
            sleep_sum[A[i]] = sleep_sum[A[i-1]];
        } else {
            sleep_sum[A[i]] = sleep_sum[A[i-1]] + (A[i] - A[i-1]);
        }
    }

    // クエリに答える
    for (ll i = 1; i <= Q; i++) {
        // A[j] <= l[i] <= A[j+1] を満たすjを二分探索で求める
        // A[k] <= r[i] <= A[k+1] を満たすkを二分探索で求める
        ll j = upper_bound(A, A+N+1, l[i]) - A - 1;
        ll k = upper_bound(A, A+N+1, r[i]) - A - 1;
        // 答えを出力
        sleep_sum[r[i]] = sleep_sum[A[k]] + (r[i] - A[k]) * ((sleep_sum[A[k+1]] - sleep_sum[A[k]]) / (A[k+1] - A[k]));
        sleep_sum[l[i]] = sleep_sum[A[j]] + (l[i] - A[j]) * ((sleep_sum[A[j+1]] - sleep_sum[A[j]]) / (A[j+1] - A[j]));
        cout << sleep_sum[r[i]] - sleep_sum[l[i]] << endl;
    }
    return 0;
}
