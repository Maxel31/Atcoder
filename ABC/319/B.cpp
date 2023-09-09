#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;

    vector<char> ans;
    ans.push_back('1');
    for(int i = 1; i <= N; i++){
        char tmp = '-';
        for(int j = 1; j <= 9; j++){
            if(i % (N / j) == 0 && N % j == 0){
                tmp = '0' + j;
                break;
            }
        }
        ans.push_back(tmp);
    }
    // ansを出力する方法を修正
    for (char c : ans) {
        cout << c;
    }
    cout << endl;
    return 0;
}
