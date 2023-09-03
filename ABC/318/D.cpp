#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main() {
    // 入力
    ll N;
    ll D[20][20];
    cin >> N;

    // 重み付無向グラフ
    ll cost[20][20];
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            cin >> D[i][j];
            cost[i][j] = D[i][j];
            cost[j][i] = D[i][j];
        }
    }

    // Prim'sアルゴリズムにより最小全域木を求める
    vector<bool> used(N + 1, false);
    vector<ll> min_cost(N + 1, INF);
    min_cost[1] = 0;
    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        int v = -1;
        for (int u = 1; u <= N; u++) {
            if (!used[u] && (v == -1 || min_cost[u] < min_cost[v])) {
                v = u;
            }
        }

        if (v == -1) {
            break;
        }

        used[v] = true;
        ans += min_cost[v];

        for (int u = 1; u <= N; u++) {
            min_cost[u] = min(min_cost[u], cost[v][u]);
        }
    }

    cout << ans << endl;
    return 0;
}
