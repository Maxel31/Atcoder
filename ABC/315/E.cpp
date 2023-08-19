#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

vector<vector<int>> G;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (auto vv : G[v]) {
        if (!visited[vv]) {
            dfs(vv);
        }
    }
    ans.push_back(v);
}

int main() {
	// 入力
    int N;
    cin >> N;

    G.resize(N + 1);
    visited.resize(N + 1, false); // initialize all vertices as not visited

	// 有効グラフの作成
    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        G[i].resize(c);
        for (auto &v : G[i]) cin >> v;
    }

	// 処理,出力
    dfs(1);
    ans.pop_back(); // 1 自身は除く
    for (auto v : ans) cout << v << " ";
    cout << endl;
}
