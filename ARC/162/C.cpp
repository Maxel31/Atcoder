#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(vector<vector<int>>& graph, vector<int>& A, int v) {
    int next_num = 0;
    for (int child : graph[v]) {
        if (A[child] == -1) {
            int res = f(graph, A, child);
            next_num = max(next_num, res);
        } else {
            next_num = max(next_num, A[child]);
        }
    }
    while (next_num == A[v]) {
        next_num++;
    }
    return A[v] = next_num;
}

int main(){
    int T;
    cin >> T;

    vector<string> results; // テストケースごとの結果を保持するベクター

    for(int i = 1; i <= T; i++){
        int N, K;
        cin >> N >> K;
        vector<int> P(N + 1), A(N + 1);
        for(int i = 2; i <= N; i++) cin >> P[i];
        for(int i = 1; i <= N; i++) cin >> A[i];

        // グラフの作成
        vector<vector<int>> graph(N + 1);
        for (int i = 2; i <= N; i++) {
            int parent = P[i];
            int child = i;
            graph[parent].push_back(child);
        }

        // f(v)の計算
        f(graph, A, 1);

        // Aliceが勝つかどうかの判定
        bool alice_wins = false;
        for (int v = 1; v <= N; v++) {
            if (A[v] == K) {
                alice_wins = true;
                break;
            }
        }

        // 結果の追加
        if (alice_wins) {
            results.push_back("Alice");
        } else {
            results.push_back("Bob");
        }
    }

    // 結果の出力
    for (string result : results) {
        cout << result << endl;
    }

    return 0;
}
