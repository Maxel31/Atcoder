#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, M;
    cin >> N >> M;
    vector<ll> L(N);
    for(int i = 0; i < N; i++){
        cin >> L[i];
        L[i]++;
    }

    // 答えの範囲
    // L の中で最も大きいもの
    ll lower = max(*max_element(L.begin(), L.end()), (ll)1) - 1; //スペース分足しているの引く
    ll upper = reduce(L.begin(), L.end()); // 合計値

    // 貪欲法
    // 二分探索
    while(lower + 1 < upper) {
        ll mid = (lower + upper) / 2;

        int row = 1;
        ll length = 0;
        for(int i = 0; i < N; i++){
            length += L[i];
            if(length > mid){ // はみ出たら改行
                row++;
                length = L[i];
            }
        }

        if(row <= M) upper = mid; // 横幅が足りていれば、もっと小さくできる
        else lower = mid;
    }

    cout << upper - 1 << endl; //スペース分足しているの引く
    return 0;
}