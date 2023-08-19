#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    string S;
    cin >> S;

    // Sから特定の文字を削除する
    string chars = "aiueo";
    for(int i = 0; i < chars.size(); i++){
        S.erase(remove(S.begin(), S.end(), chars[i]), S.end());
    }

    cout << S << endl;
}