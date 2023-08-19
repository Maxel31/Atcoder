#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL<<60;

int N;
int F[300009], S[300009];

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> F[i] >> S[i];

    // 最大の満足度を保持する変数
    int ans = 0;

    // ここに追記
    // Sの大きい順にソートする
    vector<pair<int, int>> v;
    for(int i = 1; i <= N; i++) v.push_back(make_pair(F[i], S[i]));
    sort(v.begin(), v.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    // 1番目と2番目のFが違うならそれが答え
    if(v[0].first != v[1].first){
        ans = v[0].second + v[1].second;
        cout << ans << endl;
        return 0;
    }
    else{
        ans = v[0].second + v[1].second / 2;
    }
    for(int i = 2; i < N; i++){
        if(v[0].first != v[i].first){
            ans = max(ans, v[0].second + v[i].second);
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
