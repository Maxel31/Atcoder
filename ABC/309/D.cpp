#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

ll N1, N2, M;

// グラフ内の頂点aとbの最短距離を求める
int get(vector<vector<int>> E, int s){
    int N = E.size();
    vector<int> dist(N, -1);
    queue<int> que;
    dist[s] = 0;
    que.push(s);

    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int nv : E[v]){
            int y = nv;
            if(dist[y] != -1) continue;
            dist[y] = dist[v] + 1;
            que.push(y);
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main(){
    // 入力
    cin >> N1 >> N2 >> M;

    vector<vector<int>> E(N1+N2);
    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        E[a-1].push_back(b-1);
        E[b-1].push_back(a-1);
    }

    // 出力
    cout << get(E, 0) + get(E, N1+N2-1) + 1<< endl;
    return 0;
}