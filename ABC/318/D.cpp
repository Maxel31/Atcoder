#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<vector<int>> D(N+1, vector<int>(N+1));
    rep(i, N){
        for(int j = i+1; j < N; ++j){
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }
    if(N%2 == 1) N++; // Nが奇数の場合は偶数にする
    
    // 再帰関数の定義
    ll ans = 0;
    vector<bool> used(N, false);
    auto f = [&](auto f, ll w) -> void {
        ans = max(ans, w);
        int i =0;
        while(i < N && used[i]) i++;
        if(i == N){
            // 全ての頂点を訪れた
            // ここで答えを更新する
            return;
        }
        used[i] = true;
        for(int j = i+1; j < N; j++){
            if(used[j]) continue;
            used[j] = true;
            f(f, w + D[i][j]);
            used[j] = false; // 元に戻す
        }
        used[i] = false; // 元に戻す
    };
    
    f(f, 0);

    cout << ans << endl;
    return 0;
    
}
