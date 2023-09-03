#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    int N, M, P;
    cin >> N >> M >> P;

    if (N < M){
        cout << 0 << endl;
        return 0;
    }

    N -= M;
    int ans = 1;
    ans += N / P;
    cout << ans << endl;
    return 0;
}