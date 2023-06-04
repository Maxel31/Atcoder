#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, H, K;
int dx, dy;
int nx = 0, ny = 0;

void move(char command){
    dx = 0; dy = 0;
    if(command == 'R') {
        dx = 1;
    }
    if(command == 'L') {
        dx = -1;
    }
    if(command == 'U') {
        dy = 1;
    }
    if(command == 'D') {
        dy = -1;
    }
}

int main(){
    // 入力
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<int, int>> st;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        st.insert({x,y});
    }

    for(int i = 0; i < N; i++){
        move(S[i]);
        nx += dx; ny += dy;
        if(--H < 0){
            cout << "No" << endl;
            return 0;
        }
        if(H < K and st.count({nx, ny})){
            cout << st.count({nx, ny}) << endl;
            H = K;
            st.erase({nx, ny});
        }
    }
    cout << "Yes" << endl;
    return 0;
}