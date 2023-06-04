#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[109], young;
string S[109]; 

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> S[i] >> A[i];
    }

    // 最年少の人を探す
    young = 1;
    for(int i = 2; i <= N; i++){
        if(A[young] > A[i]){
            young = i;
        }
    }

    // 出力
    for(int i = young; i <= N; i++){
        cout << S[i] << endl;
    }
    for(int i = 1; i < young; i++){
        cout << S[i] << endl;
    }
    return 0;
}