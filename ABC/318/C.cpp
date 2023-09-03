#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 入力
    int N, D, K;
    ll P;
    cin >> N >> D >> P;

    vector<ll> F(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    sort(F.begin(), F.end());
    S[0] = F[0];
    for (int i = 0; i < N-1; i++) {
        S[i+1] = S[i] + F[i+1];
    }

    K = (N + D - 1) / D;
    ll ans = P * K;
    for(int i = 0; i < K; i++) ans = min(ans, P * i + S[N - 1 - i * D]);

    cout << ans << endl;
    return 0;
}
