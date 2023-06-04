#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // 入力
    int N, A, B;
    cin >> N >> A >> B;
    int C[309];
    for(int i = 1; i <= N; i++) cin >> C[i];

    int ans;
    for(int i = 1; i <= N; i++){
        if( A + B == C[i]) ans = i;
    }
    cout << ans << endl;
}