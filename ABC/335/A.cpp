#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;
    // 最後の位置文字を4に変更
    S.at(S.size()-1) = '4';
    cout << S << endl;
}