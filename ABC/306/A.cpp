#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;

int main(){
    cin >> N;
    cin >> S;

    for(int i = 0; i < N; i++) cout << S[i] << S[i];
    cout << endl;
    return 0;
}