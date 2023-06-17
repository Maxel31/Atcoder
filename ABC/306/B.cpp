#include <bits/stdc++.h>
using namespace std;
using ll = long long; // llは今回使えません．
using ull = unsigned long long;

int main(){
    // 入力
    ll A[64];
    ull sum = 0;
    for(int i = 0; i < 64; i++){
        cin >> A[i];
        if(A[i] == 1) sum += (1uLL << i);
    }
    cout << sum << endl;
    return 0;
}