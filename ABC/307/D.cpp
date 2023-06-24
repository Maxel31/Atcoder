#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    string ans;
    int depth = 0; // それまでの(の数
    for(auto c:S){
        if(c == ')' && depth > 0){
            while(ans.back() != '('){ // (に行きつくまで
                ans.pop_back(); // 末尾要素の消去
            }
            ans.pop_back(); // (を消す
            depth--;
        }
        else{
            ans.push_back(c);
            if(c == '(')depth++;
        }
    }
    cout << ans << endl;
}
