#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;

    vector<int> results; // 各ケースの結果を格納するベクター

    for(int i = 1; i <= T; i++){
        ll N;
        cin >> N;
        ll P[1009];
        for(int i = 1; i <= N; i++) P[i] = i;

        // 復路で一位だった可能性のある人の人数をカウントする変数
        int count = 0;

        // 合計の順位を入力
        ll S[1009];
        for(int i = 1; i <= N; i++) cin >> S[i];

        // 各人の復路で一位だった可能性のあるかどうかを判定し、カウントする
        for(int i = 1; i <= N; i++){
            bool possible = true;
            for(int j = 1; j <= N; j++){
                if(i == j) continue;
                if(S[i] > S[j] && P[i] <= P[j]){
                    possible = false;
                    break;
                }
            }
            if(possible) count++;
        }

        results.push_back(count); // 結果をベクターに追加
    }

    // 結果を一括で出力
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}
