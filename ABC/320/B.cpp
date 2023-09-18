#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;
    int n = S.size();

    // Sの中の回文であるものの長さの最大値を求める
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            bool ok = true;
            for(int k = i; k <= j; ++k){
                if(S[k] != S[i + j - k]) ok = false;
            }
            if(ok) ans = max(ans, j - i + 1);
        }
    }

    cout << ans << endl;
    return 0;
}