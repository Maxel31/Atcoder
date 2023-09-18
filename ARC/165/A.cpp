#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

// Nを素因巣分解する
vector<ll> solve (ll n){
    vector<ll> res;
    for(ll i = 2; i * i <= n; ++i){
        while(n % i == 0){
            res.push_back(i);
            n /= i;
        }
    }
    if(n != 1) res.push_back(n);
    return res;
}

int main(){
    // 入力
    int T;
    cin >> T;
    ll N[109];
    rep(i,T) cin >> N[i];

    // 処理
    bool check[109];
    rep(i,T) check[i] = false;
    rep(i,T){
        vector<ll> res = solve(N[i]);
        // resの要素の種類を数える
        ll tmp = res[0];
        for(int j = 1; j < res.size(); ++j){
            if(tmp != res[j]){
                check[i] = true;
                break;
            }
        }
    }

    // 出力
    rep(i,T){
        if(check[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
    
}