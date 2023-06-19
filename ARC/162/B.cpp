#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> P(N);
    bool possible;
    possible = true;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    // 操作回数と各操作でのiとjを記録する変数
    int count = 0;
    vector<pair<int, int>> operations;

    // 操作を繰り返す
    while (count < 2000) {
        bool sorted = true;

        // 順列Pが昇順になっているかチェック
        for (int i = 1; i < N; i++) {
            if (P[i - 1] > P[i]) {
                sorted = false;
                break;
            }
        }

        // 順列が昇順になっていれば操作終了
        if (sorted) {
            possible = true;
            break;
        }

        // 操作を行う
        for (int i = 0; i < N - 1; i++) {
            int j = 0;
            while (j < N - 2) {
                if (P[j] > P[j + 1]) {
                    // 操作を行う
                    int temp = P[j];
                    P[j] = P[j + 1];
                    P[j + 1] = temp;
                    
                    // 操作の情報を記録
                    operations.push_back({i + 1, j});

                    count++;
                    if(count > 2000) {
                        possible = false;
                        break;
                    }
                }
                j++;
            }
        }
    }

    // 結果の出力
    if (!possible) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << count << endl;
        for (auto operation : operations) {
            cout << operation.first << " " << operation.second << endl;
        }
    }

    return 0;
}
