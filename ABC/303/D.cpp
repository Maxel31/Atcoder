#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; } // aとbを比較してbの方が大きい場合はaをbで更新する
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; } // aとbを比較してbの方が小さい場合はaをbで更新する

int main(){
    // 入力
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    // dp[i][j]: i文字目まで入力した時点で、j=0ならCapsLook=false, j=1ならCapsLook=true としてかかる最小時間
    vector<vector<ll>> dp(S.size()+1, vector<ll>(2, INF));
    dp[0][0] = 0;

    // 処理
    for(int i = 0; i < S.size(); ++i){
        // CapsLookを押す場合
        chmin(dp[i][0], dp[i][1] + Z); // OFF時
        chmin(dp[i][1], dp[i][0] + Z); // ON時

        // 打鍵
        if(S[i] == 'a'){
            chmin(dp[i+1][0], dp[i][0] + X); // OFF時
            chmin(dp[i+1][1], dp[i][1] + Y); // ON時
        }
        else{
            chmin(dp[i+1][0], dp[i][0] + Y); // OFF時
            chmin(dp[i+1][1], dp[i][1] + X); // ON時
        }
    }
    cout << min(dp[S.size()][0], dp[S.size()][1]) << endl;
    return 0;
}