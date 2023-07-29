#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL<<60;

int N;
string S;

int main(){
    cin >> N >> S;
    int count_A=0, count_B=0, count_C=0;
    for(int i=0; i<N; i++){
        if(S.at(i)=='A') count_A++;
        else if(S.at(i)=='B') count_B++;
        else if(S.at(i)=='C') count_C++;
        if(count_A >= 1 && count_B >= 1 && count_C >= 1){
            cout << i+1 << endl;
            return 0;
        }
    }
}