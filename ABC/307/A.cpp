#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    int A[100009];
    cin >> N;
    for(int i = 1; i <= 7 * N; i++) cin >> A[i];

    int B[100009];
    for(int i = 1; i <= N; i++) B[i] = 0;

    int cnt = 1;
    for(int i = 1; i <= 7 * N; i++){
        B[cnt] += A[i];
        if(i % 7 == 0) cnt++;
    }

    for(int i = 1; i <= N; i++) cout << B[i] << " ";
    cout << endl;
    return 0;
}