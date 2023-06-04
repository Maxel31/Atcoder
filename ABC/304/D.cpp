#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 最終的にイチゴが1個以上載っている場合に注目して考える

ll W,H;
ll N, A, B;
ll p[200009], q[200009];
ll a[200009], b[200009];

int main(){
    // 入力
    cin >> W >> H;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> p[i] >> q[i];
    }
    cin >> A;
    for(int i=1; i<=A; i++){
        cin >> a[i];
    }
    cin >> B;
    for(int i=1; i<=B; i++){
        cin >> b[i];
    }

    // 外枠
    a[A + 1] = W; b[B + 1] = H;

    // 任意のピースに何個イチゴが載っているか
    map<pair<ll, ll>, ll> mp;
    for(int i = 1; i <= N; i++){
        ll X = lower_bound(a + 1, a + A + 2, p[i]) - a;
        ll Y = lower_bound(b + 1, b + B + 2, q[i]) - b;
        mp[{X, Y}]++;
    }

    // 出力
    ll m = N, M = 0;
    for(auto p : mp) M = max(M, p.second);
    if(mp.size() == (A+1)*(B+1)){
        for(auto p : mp) m = min(m, p.second);
    }
    else m = 0;
    cout << m << " " << M << endl;

    return 0;
}