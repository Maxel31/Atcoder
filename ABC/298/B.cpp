#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> A,B;

vector<vector<int>> rotate(vector<vector<int>> A){
    vector<vector<int>> res(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            res[j][N-1-i] = A[i][j];
        }
    }
    return res;
}

int main(){
    cin >> N;
    //A.resize(N, vector<int>(N));
    //B.resize(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> B[i][j];
        }
    }
    for(int i=0; i<4; i++){
        A = rotate(A);
        if(A == B){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;  
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << A[i][j];
        }
    }
    cout << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << B[i][j];
        }
    }
    cout << endl;
    return 0;
}