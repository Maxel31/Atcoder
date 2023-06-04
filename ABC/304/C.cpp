#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 距離の計算
int dist(int x1, int y1, int x2, int y2){
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main(){
    // 入力
    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }

    // 感染してるか
    vector<bool> sick(N, false);
    sick[0] = true;

    // キューで管理
    queue<int> Q;
    Q.push(0); // 最初の感染者

    // 処理
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < N; i++){
            if(dist(X[v], Y[v], X[i], Y[i]) <= D * D && !sick[i]){
                sick[i] = true;
                Q.push(i); // 感染者がキューに詰められる
            }
        }
    }
    
    // 出力
    for(int i = 0; i < N; i++){
        if(sick[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}