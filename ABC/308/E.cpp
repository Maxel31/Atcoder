#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

// 数を3つ入力して3つの数以外の最小の非負整数を求める
int mex(int a, int b, int c){
    if(a != 0 && b != 0 && c != 0) return 0;
    if(a != 1 && b != 1 && c != 1) return 1;
    if(a != 2 && b != 2 && c != 2) return 2;
    return 3;
}

int main(){
    // 入力
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &i : A) cin >> i;
    string S;
    cin >> S;
    
    // 出現回数を記録する変数
    vector cnt_l(N+1, vector<int>(3)); // M
    vector cnt_r(N+1, vector<int>(3)); // X
    for(int i = 0; i < N; i++){
        cnt_l[i+1] = cnt_l[i];
        if(S[i] == 'M')cnt_l[i+1][A[i]]++;
    }
    for(int i = N-1; i >= 0; i--){
        cnt_r[i] = cnt_r[i+1];
        if(S[i] == 'X')cnt_r[i][A[i]]++;
    }

    ll ans = 0;
    // 処理, E に注目
    for(int i = 0; i < N; i++){
        if(S[i] != 'E') continue;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                ans += (ll)cnt_l[i][j] * cnt_r[i+1][k] * mex(j, k, A[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
