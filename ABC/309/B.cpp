#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N;
    int A[109][109], B[109][109];
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            char s;
            cin >> s;
            if(s == '0') A[i][j] = 0;
            else A[i][j] = 1;
            B[i][j] = A[i][j];
        }
    }


for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
        if(i == 1 && j != 1) B[i][j] = A[1][j-1];
        if(i == N && j != N) B[i][j] = A[N][j+1];
        else if(i == 1) B[i][j] = A[1][j-1];
        else if(i == N) B[i][j] = A[N][j+1];
        else if(j == 1) B[i][j] = A[i+1][1];
        else if(j == N) B[i][j] = A[i-1][N];
    }
}
B[1][1] = A[2][1];
B[N][N] = A[N-1][N];

    // 出力
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << B[i][j];
        }
        cout << endl;
    }
    return 0;
}