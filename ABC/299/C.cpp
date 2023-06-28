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

int N;
string S;

int main(){
    // 入力
    cin >> N >> S;

    // 処理
    // 左右方向から走査する

    int ans = 0;
    for(int flip = 0; flip < 2; flip++){
        int level = 0;
        for(int i = 0; i < N; i++){
            if(S[i] == '-'){
                ans = max(ans, level);
                level = 0;
            }
            else level++;
        }
        reverse(S.begin(), S.end());
    }

    if(!ans) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}