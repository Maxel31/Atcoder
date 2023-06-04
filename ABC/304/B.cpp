#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

int main(){
    // 入力
    cin >> N;
    
    // 処理
    int scale = N / 1000;
    int cnt = 0;
    while(scale > 0){
        scale /= 10;
        cnt++;
    }

    // 出力
    if(cnt == 0) cout << N << endl;
    else{
        cout << N - N % ((ll)pow(10, (cnt))) << endl;
    }
    return 0;
}