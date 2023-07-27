#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, P, Q;
vector<int> D;

int main(){
    cin >> N >> P >> Q;
    D.resize(N);
    for(int i=0; i<N; i++) cin >> D[i];

    int ans;
    // Dの中での最小値
    int minD = *min_element(D.begin(), D.end());
    int tmp = Q + minD;

    // 出力
    cout << min(P, tmp) << endl;
    return 0;
}