#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

vector<vector<int>> G;
vector<int> visited;
vector<int> in_cycle; // 有向閉路に含まれる頂点の順番

bool dfs(int v) {
    visited[v] = 1; // 訪問済みを記録

    // 頂点vから次の頂点へのDFS
    for (int nv : G[v]) {
        if (visited[nv] == 1) {
            // 閉路が見つかったら有向閉路を構成する頂点を記録して終了
            in_cycle.push_back(nv);
            return true;
        } else if (visited[nv] == 0) {
            // 未訪問の頂点に対してDFSを行う
            if (dfs(nv)) {
                in_cycle.push_back(nv);
                return true;
            }
        }
    }

    visited[v] = 2; // 閉路を含まない頂点として記録
    return false;
}

vector<int> findDirectedCycle(int N, const vector<int>& A) {
    G.clear();
    G.resize(N);
    visited.assign(N, 0);
    in_cycle.clear();

    // グラフを構築
    for (int i = 0; i < N; i++) {
        G[A[i] - 1].push_back(i);
    }

    // 有向閉路を探索
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) break; // 有向閉路が見つかったら探索終了
        }
    }

    return in_cycle;
}

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 有向閉路に含まれる頂点の順番を取得
    vector<int> in_cycle = findDirectedCycle(N, A);

    // 有向閉路に含まれる頂点の順番を出力
    if (!in_cycle.empty()) {
        cout << in_cycle.size() << endl;
        for (int v : in_cycle) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
