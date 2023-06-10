#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    
    int a = N / 5;
    int b = N % 5;
    if((abs(N - 5 * a) < abs(N - 5 * (a+1)))){
        cout << 5 * a << endl;
    }
    else cout << 5 * (a+1) << endl;
    return 0;
}