#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    for (int x = 0; x <= N; x++){
        for (int y = 0; x + y <= N; y++){
            for (int z = 0; x + y + z <= N; z++){
                // x,y,z の組の合計がN以下ならOK
                if (x + y + z <= N){
                    cout << x << " " << y << " " << z << endl;
                    continue;
                }
                else break;
            }
        }
    }
    return 0;
}