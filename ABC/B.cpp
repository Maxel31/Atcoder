#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL<<60;

int N, D;
char S[109][109];

int main(){
    cin >> N >> D;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= D; j++){
            cin >> S[i][j];
        }
    }

    int max_days = 0; // 選べる日数の最大値

    // 全ての日について考える
    for (int day = 1; day <= D; day++) {
        bool all_free = true; // その日が全員が暇かどうかを示すフラグ
        for (int person = 1; person <= N; person++) {
            if (S[person][day] == 'x') {
                all_free = false;
                break;
            }
        }

        if (all_free) {
            // 全員が暇な日が見つかった場合
            // その日を含む最大の連続日数を求める
            int current_days = 1;
            for (int next_day = day + 1; next_day <= D; next_day++) {
                bool all_free_next = true; // 次の日が全員が暇かどうかを示すフラグ
                for (int person = 1; person <= N; person++) {
                    if (S[person][next_day] == 'x') {
                        all_free_next = false;
                        break;
                    }
                }
                if (all_free_next) {
                    current_days++;
                } else {
                    break;
                }
            }
            max_days = max(max_days, current_days);
        }
    }

    cout << max_days << endl;

    return 0;
}
