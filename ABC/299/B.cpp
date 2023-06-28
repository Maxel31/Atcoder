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
ll T;
ll C[200009], R[200009];

int main(){
    // 入力
    cin >> N >> T;
    C[0] = -9999;
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> R[i];
    }

    int same_color = 0; // Tと同じ色のプレイヤー
    int winner = 0;
    for(int i = 1; i <= N; i++){
        if(C[i] == T){
            same_color++;
            if(R[i] > R[winner]) winner = i;
        }
    }

    if(same_color > 0){
        cout << winner << endl;
        return 0;
    }

    T = C[1];
    winner = 1;
    for(int i = 2; i <= N; i++){
        if(C[i] == T){
            same_color++;
            if(R[i] > R[winner]) winner = i;
        }
    }

    cout << winner << endl;
    return 0;
}