#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int a = A[0], b = A[1];
    // A[2]以降の範囲をソート
    sort(A.begin()+2, A.end());
    int ans = 2000000000;
    for(int i = 0; i <= N-2-M; i++){
        ans = min(ans, (max(A[0] - A[2+i], 0) + max(A[1 + i + M] - A[1], 0)));
    }
    cout << ans << endl;
    return 0;
}
