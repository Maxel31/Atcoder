#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;
    bool FirstIsLarge = true, ElseIsSmall = true;

    // 先頭の文字が大文字かどうか判定
    if(S.at(0) >= 'A' && S.at(0) <= 'Z'){
        FirstIsLarge = true;
    }else{
        FirstIsLarge = false;
    }

    // 2文字目以降の文字が小文字かどうか判定
    for(int i = 1; i < S.size(); ++i){
        if(S.at(i) >= 'a' && S.at(i) <= 'z'){
            ElseIsSmall = true;
        }else{
            ElseIsSmall = false;
            break;
        }
    }

    if(FirstIsLarge && ElseIsSmall){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}