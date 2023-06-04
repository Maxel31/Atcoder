#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
char S[109];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> S[i];
    int M = (N + 1) / 2;
    int T = 0, A = 0;

    for(int i = 1; i <= N; i++){
        if(S[i] == 'T') T++;
        else A++;
        if(T >= M){
            cout << "T" << endl;
            return 0;
        }
        if(A >= M){
            cout << "A" << endl;
            return 0;
        }
    }
}