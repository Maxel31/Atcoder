#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    // 入力
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S[i];
    }

    // マス(1,1)からマス(H,W)までの移動ができるか判定する関数
    auto canReachDestination = [&](int x, int y) {
        // 訪問済みのマスを管理する配列
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        
        // 移動するための4方向のベクトル
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        // 深さ優先探索による移動
        stack<pair<int, int>> st;
        st.push({x, y});
        
        while (!st.empty()) {
            auto [curX, curY] = st.top();
            st.pop();
            
            // 目的地に到達した場合、探索を終了
            if (curX == H-1 && curY == W-1) {
                return true;
            }
            
            // マスが訪問済みの場合はスキップ
            if (visited[curX][curY]) {
                continue;
            }
            
            visited[curX][curY] = true;
            
            // 4方向に移動できる場合は次のマスをスタックに追加
            for (int i = 0; i < 4; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                
                // グリッドの範囲内かつ移動先が通行可能な場合はスタックに追加
                if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W && !visited[nextX][nextY]) {
                    if (S[nextX][nextY] == 's' && S[curX][curY] == 'e') {
                        st.push({nextX, nextY});
                    } else if (S[nextX][nextY] == 'n' && S[curX][curY] == 's') {
                        st.push({nextX, nextY});
                    } else if (S[nextX][nextY] == 'u' && S[curX][curY] == 'n') {
                        st.push({nextX, nextY});
                    } else if (S[nextX][nextY] == 'k' && S[curX][curY] == 'u') {
                        st.push({nextX, nextY});
                    } else if (S[nextX][nextY] == 'e' && S[curX][curY] == 'k') {
                        st.push({nextX, nextY});
                    }
                }
            }
        }
        
        return false;
    };

    // マス(1,1)からマス(H,W)までの移動ができるか判定
    bool ans = canReachDestination(0, 0);

    // 結果の出力
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
