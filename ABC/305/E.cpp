#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using P = pair<int,int>;

int main() {
    // 入力
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> to(n);
    // グラフ
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
}

// ダイクストラ法
vector<int> d(n,-1); // -1: 未訪問, 頂点ごとの最短経路長を保持する配列
priority_queue<P> q;
rep(i,k) {
    int p, h;
    cin >> p >> h;
    p--; // 配列の添字に合わせる
    d[p] = h; // 警備条件
    q.emplace(h,p);
}

while (!q.empty()) {
    auto [h,v] = q.top(); q.pop();
    if (d[v] != h) continue;
    for (int u : to[v]) {
        if (d[u] >= h-1) continue;
        d[u] = h-1;
        q.emplace(d[u],u); // uへの最短経路長をh-1で更新
    }
} 

vector<int> ans;
rep(i,n) if (d[i] >= 0) ans.push_back(i+1);
cout << ans.size() << endl;
for (int v : ans) cout << v << ' ';
cout << endl;
return 0;
}