#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int T;
    cin >> T;
    char S[2009][2009];
    int length[2009];
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        length[i] = N;
        for(int j = 1; j <= N; j++){
            cin >> S[i][j];
        }
    }

    // 処理
    for(int i = 1; i <= T; i++){
        bool possible = false;
        int N = length[i];
        // 全探索
        for(int j = 1; j < N; j++){
            string left = "", right = "";
            for(int k = 1; k <= j; k++){
                left += S[i][k];
            }
            for(int k = j+1; k <= N; k++){
                right += S[i][k];
            }
            if(left < right){
                possible = true;
                break;
            }
        }

        // 出力
        if(possible){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
