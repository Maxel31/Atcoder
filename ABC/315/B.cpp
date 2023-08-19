#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    int M;
    int D[109];
    cin >> M;
    for(int i = 1; i <= M; i++) cin >> D[i];

    int TotalDate = 0;
    for(int i = 1; i <= M; i++) TotalDate += D[i];

    int MidDate = (TotalDate + 1) / 2;

    // MidDateは、D[1] + D[2] + ... + D[i] >= MidDateとなる最小のi
    int SumDate = 0;
    int i;
    for(i = 1; i <= M; i++){
        SumDate += D[i];
        if(SumDate >= MidDate) break;
    }

    int leave = MidDate - (SumDate - D[i]);

    cout << i << " " << leave << endl;
}