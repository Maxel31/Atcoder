#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    ll N, K;
    ll total_medicine = 0;
    cin >> N >> K;
    ll a[N+1], b[N+1];
    for(int i=1; i<=N; i++){
        cin >> a[i] >> b[i];
        total_medicine += b[i];
    }

    if(total_medicine <= K){
        cout << 1 << endl;
        return 0;
    }
    
    pair<ll, ll> p[N+1];
    for(int i=1; i<=N; i++){
        p[i] = make_pair(a[i], b[i]);
    }
    // a[i]の小さい順にソート
    sort(p+1, p+N+1);

    // a[i]日目にb[i]個の薬を飲む
    ll ans = N;
    for(int i=1; i<=N; i++){
        total_medicine -= p[i].second;
        if(total_medicine <= K){
            ans = p[i].first+1;
            break;
        }
    }
    cout << ans <<  endl;
    return 0;
}
