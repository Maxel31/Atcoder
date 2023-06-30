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
    int N, M;
    cin >> N >> M;
    string C[109], D[109];
    int P[109];
    for(int i = 1; i <= N; i++) cin >> C[i];
    for(int i = 1; i <= M; i++) cin >> D[i];
    for(int i = 0; i <= M; i++) cin >> P[i];

    map<string, int> mp;
    for(int i = 1; i <= M; i++) mp[D[i]] = P[i];

    // 処理
    int ans = 0;
    for(int i = 1; i <= N; i++){
        // C[i] に該当する文字列がDにない場合
        if(mp[C[i]] == 0) ans += P[0];
        // C[i] に該当する文字列がDにある場合
        else ans += mp[C[i]];
    }

    // 出力
    cout << ans << endl;
    return 0;
}