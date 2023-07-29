#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, M;
char S[109][109];

// TaK Code の条件を満たすか判定する関数
bool isTakCode(int r, int c) {
    // 左上の縦3マス横3マスに含まれる計18マスが全て黒かどうかをチェック
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            if (S[i][j] != '#') return false;
        }
    }
    // 右下の縦3マス横3マスに含まれる計18マスが全て黒かどうかをチェック
    for (int i = r + 6; i < r + 9; i++) {
        for (int j = c + 6; j < c + 9; j++) {
            if (S[i][j] != '#') return false;
        }
    }
    // 左上の縦3マス横3マスに八方位で隣接する計14マスが全て白かどうかをチェック
    for(int i = r; i < r + 4; i++) {
        if(S[i][c+3] != '.') return false;
    }
    for(int i = c; i < c + 4; i++) {
        if(S[r+3][i] != '.') return false;
    }

    // 右下の縦3マス横3マスに八方位で隣接する計14マスが全て白かどうかをチェック
    for(int i = r + 5; i < r + 9; i++) {
        if(S[i][c+5] != '.') return false;
    }
    for(int i = c + 5; i < c + 9; i++) {
        if(S[r+5][i] != '.') return false;
    }
    return true;
}

int main(){
    // 入力
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> S[i][j];
        }
    }

    // 周りを白マスで囲む
    for (int i = 0; i <= N + 1; i++) {
        S[i][0] = '.';
        S[i][M + 1] = '.';
    }

    // TaK Code の条件を満たす箇所を全て出力
    for (int i = 1; i <= N - 8; i++) {
        for (int j = 1; j <= M - 8; j++) {
            if (isTakCode(i, j)) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
