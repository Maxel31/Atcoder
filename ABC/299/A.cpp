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
    int N;
    string S;
    cin >> N >> S;
    int cnt = 0;
    bool in = false;

    for(int i = 0; i < N; i++){
        if(S[i] == '|'){
            cnt++;
            if(cnt == 2) break;
        }
        if(S[i] == '*'){
            if(cnt == 1) in = true;
            else break;
        }
    }

    if(in) cout << "in" << endl;
    else cout << "out" << endl;
    return 0;
}