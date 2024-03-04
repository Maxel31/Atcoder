#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;

    // 1文字ずつカウントするための配列を用意
    int cnt[26] = {0};

    for (int i = 0; i < S.size(); ++i){
        // 1文字ずつカウント
        cnt[S.at(i) - 'a']++;
    }

    // 最も多く出現した文字を探す
    int max = 0; char ans; 
    for (int i = 0; i < 26; ++i){
        if (max < cnt[i]){
            max = cnt[i];
            ans = 'a' + i;
        }
    }

    cout << ans << endl;
    
    return 0;
}