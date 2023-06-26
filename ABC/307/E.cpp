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


// 人が円環ではなく1列に並んでいると考える
// 隣り合う2人について同じ数を割り当てないためには直前の人の数が分かっていれば十分
    
// Point: 円環上の dp, 状態の削減
// dp[i][f] : i人目まで数を割り当てる方法のうち，i人目に割り当てた数が
// 一人目の数と同じで(f:ある１(ない０)) ものの個数
    
ll dp[2][1000009];

int main(){
    // 入力
    ll d = 998244353;
    int N, M;
    cin >> N >> M;

    dp[1][1] = M;
    for(int i = 1; i < N; i++){
        // 状態遷移
        dp[0][i+1] += dp[0][i] * (M-2); // 直前と1一人目の分で-2
        dp[1][i+1] += dp[0][i]; // i+1人目は1人目と一緒
        dp[0][i+1] += dp[1][i] * (M-1); // 直前と一人目一緒なので - 1
        // 余りを取る
        dp[0][i+1] %= d;
        dp[1][i+1] %= d;
    }

    // 出力
    cout << dp[0][N] << endl;
    return 0;

}