#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N;
    int A[109], B[109], C[109], D[109];
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // 初期化
    bool masu[109][109];

    for (int i = 1; i <= 100; i++){
        for (int j = 1; j <= 100; j++){
            masu[i][j] = false;
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = A[i]+1; j <= B[i]; j++){
            for (int k = C[i]+1; k <= D[i]; k++){
                masu[j][k] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++){
        for (int j = 1; j <= 100; j++){
            if (masu[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}