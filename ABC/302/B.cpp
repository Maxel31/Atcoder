#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H,W;

int x,y;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string str;

int main(){
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            for(int k = 0; k < 8; k++){
                str = "";
                for(int t = 0; t < 5; t++){
                    x = i + dx[k] * t;
                    y = j + dy[k] * t;
                    if(x < 0 || x >= H || y < 0 || y >= W) break;
                    str += S[x][y];
                }
        if(str == "snuke"){
            for(int t = 0; t < 5; t++){
                x = i + dx[k] * t+1;
                y = j + dy[k] * t+1;
                cout << x << " " << y << endl;
            }
            return 0;
        }
            }
        }
    }
    return 0;
}