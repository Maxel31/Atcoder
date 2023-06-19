#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // 入力
    int N;
    cin >> N;
    vector<int> P(N);
    for(auto &v : P) cin >> v, --v;

    // 転倒数
    int inv = 0;
    // 初期状態の転倒数を数える
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(P[i] > P[j]) inv++;
        }
    }

    // 初期状態の転倒数が奇数ならソート不可
    if(inv % 2 == 1){
        cout << "No" << endl;
        return 0;
    }

    // 初期状態の転倒数が偶数ならソート可能
    cout << "Yes" << endl;

    // 処理の仕方を考える
    vector<pair<int,int>> ops; // i, jの選択を記録する

    // 処理メソッド
    auto act = [&](int i, int j){
        ops.emplace_back(i+1, j+1); // 添え字が0からであることに注意
        vector<int> q, p_new;
        for(int k = 0; k < N; k++){
            if(k == i || k == i + 1) continue;
            q.push_back(P[k]);
        }
        for(int k = 0; k <= j; k++){
            p_new.push_back(q[k]);
        }
        p_new.push_back(P[i]);
        p_new.push_back(P[i+1]);
        for(int k = j + 1; k < N-2; k++) p_new.push_back(q[k]);
        P = p_new;
    };

    // 処理を繰り返す
    while(true){
        int tar = -1;
        for(int i = 0; i < N; i++){
            if(P[i] != i){
                tar = i;
                break; // 昇順にソートされていない最も左にあるもの
            }
        }
        if(tar == -1) break; // 昇順にソートされているなら終了

        int tar_p = -1;
        for(int i = tar; i < N; i++){
            if(P[i] == tar){
                tar_p = i;
                break; // tarの位置にあるもの
            }
        }
        if(tar_p != N-1){
            act(tar_p,tar-1);
        }
        else{
            act(N-2, N-4);
            act(N-2, tar-1);
        }
    }

    // 出力
    cout << ops.size() << endl;
    for(auto v : ops){
        cout << v.first << " " << v.second << endl;
    }
}