#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vector<int> B(M);
    for(int i=0; i<M; i++) cin >> B[i];

    // 昇順にソート
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // A と B を結合
    vector<int> C(N + M);
    for(int i=0; i<N; i++) C[i] = A[i];
    for(int i=0; i<M; i++) C[N + i] = B[i]+1;

    ll ans = INF;
    for(int i=0; i<N+M; i++){
        ll cnt_seller = upper_bound(A.begin(), A.end(), C[i]) - A.begin();
        ll cnt_buyer = B.end() - lower_bound(B.begin(), B.end(), C[i]);
        if(cnt_seller >= cnt_buyer) ans = min(ans, (ll)C[i]);
    }
    cout << ans << endl;
    return 0;
}
