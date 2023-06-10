#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H, W;
    cin >> H >> W;
    char c[H][W];

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> c[i][j];
        }
    }

    // 穴の開いているマスを答える
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(c[i][j] == '.'){
                if(j+1 < W && c[i][j+1] == '#' && i+1 < H && c[i+1][j] == '#'){
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
                if(j-1 >= 0 && c[i][j-1] == '#' && i+1 < H && c[i+1][j] == '#'){
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
                if(i-1 >= 0 && c[i-1][j] == '#' && j+1 < W && c[i][j+1] == '#'){
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
                if(i-1 >= 0 && c[i-1][j] == '#' && j-1 >= 0 && c[i][j-1] == '#'){
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
