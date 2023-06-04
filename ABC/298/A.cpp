#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;
bool check1=false, check2=true;

int main(){
    cin >> N >> S;
    for(int i=0; i<N; ++i){
        if(S[i] == 'o') check1 = true;
        if(S[i] == 'x') check2 = false;
    }
    if(check1 && check2) cout << "Yes" << endl;
    else cout << "No" << endl;  
    return 0;
}