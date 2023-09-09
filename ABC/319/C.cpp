#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    int c[4][4], check[4][4];
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> c[i][j];
            check[i][j] = 9;
        }
    }

    ll total = 9*8*7*6*5*4*3*2*1;
    bool flag;
    ll cnt;
    double ans;
    // 各マスを何番目に開けるかを全探索
    for(int i = 1; i <= 9; i++){
        if(i == 1) check[1][1] = 1;
        else if(i == 2) check[1][2] = 1;
        else if(i == 3) check[1][3] = 1;
        else if(i == 4) check[2][1] = 1;
        else if(i == 5) check[2][2] = 1;
        else if(i == 6) check[2][3] = 1;
        else if(i == 7) check[3][1] = 1;
        else if(i == 8) check[3][2] = 1;
        else if(i == 9) check[3][3] = 1;
        for(int j = 1; j <= 9; j++){
            if(i == j) continue;
            if(j == 1) check[1][1] = 1;
            else if(j == 2) check[1][2] = 1;
            else if(j == 3) check[1][3] = 1;
            else if(j == 4) check[2][1] = 1;
            else if(j == 5) check[2][2] = 1;
            else if(j == 6) check[2][3] = 1;
            else if(j == 7) check[3][1] = 1;
            else if(j == 8) check[3][2] = 1;
            else if(j == 9) check[3][3] = 1;
            for(int k = 1; k <= 9; k++){
                if(i == k || j == k) continue;
                if(k == 1) check[1][1] = 2;
                else if(k == 2) check[1][2] = 2;
                else if(k == 3) check[1][3] = 2;
                else if(k == 4) check[2][1] = 2;
                else if(k == 5) check[2][2] = 2;
                else if(k == 6) check[2][3] = 2;
                else if(k == 7) check[3][1] = 2;
                else if(k == 8) check[3][2] = 2;
                else if(k == 9) check[3][3] = 2;
                for(int l = 1; l <= 9; l++){
                    if(i == l || j == l || k == l) continue;
                    if(l == 1) check[1][1] = 3;
                    else if(l == 2) check[1][2] = 3;
                    else if(l == 3) check[1][3] = 3;
                    else if(l == 4) check[2][1] = 3;
                    else if(l == 5) check[2][2] = 3;
                    else if(l == 6) check[2][3] = 3;
                    else if(l == 7) check[3][1] = 3;
                    else if(l == 8) check[3][2] = 3;
                    else if(l == 9) check[3][3] = 3;     
                    for(int m = 1; m <= 9; m++){
                        if(i == m || j == m || k == m || l == m) continue;
                        if(m == 1) check[1][1] = 4;
                        else if(m == 2) check[1][2] = 4;
                        else if(m == 3) check[1][3] = 4;
                        else if(m == 4) check[2][1] = 4;
                        else if(m == 5) check[2][2] = 4;
                        else if(m == 6) check[2][3] = 4;
                        else if(m == 7) check[3][1] = 4;
                        else if(m == 8) check[3][2] = 4;
                        else if(m == 9) check[3][3] = 4;     
                        for(int n = 1; n <= 9; n++){
                            if(i == n || j == n || k == n || l == n || m == n) continue;
                            if(n == 1) check[1][1] = 5;
                            else if(n == 2) check[1][2] = 5;
                            else if(n == 3) check[1][3] = 5;
                            else if(n == 4) check[2][1] = 5;
                            else if(n == 5) check[2][2] = 5;
                            else if(n == 6) check[2][3] = 5;
                            else if(n == 7) check[3][1] = 5;
                            else if(n == 8) check[3][2] = 5;
                            else if(n == 9) check[3][3] = 5;     
                            for(int o = 1; o <= 9; o++){
                                if(i == o || j == o || k == o || l == o || m == o || n == o) continue;
                                if(o == 1) check[1][1] = 6;
                                else if(o == 2) check[1][2] = 6;
                                else if(o == 3) check[1][3] = 6;
                                else if(o == 4) check[2][1] = 6;
                                else if(o == 5) check[2][2] = 6;
                                else if(o == 6) check[2][3] = 6;
                                else if(o == 7) check[3][1] = 6;
                                else if(o == 8) check[3][2] = 6;
                                else if(o == 9) check[3][3] = 6;
                                for(int p = 1; p <= 9; p++){
                                    if(i == p || j == p || k == p || l == p || m == p || n == p || o == p) continue;
                                    if(p == 1) check[1][1] = 7;
                                    else if(p == 2) check[1][2] = 7;
                                    else if(p == 3) check[1][3] = 7;
                                    else if(p == 4) check[2][1] = 7;
                                    else if(p == 5) check[2][2] = 7;
                                    else if(p == 6) check[2][3] = 7;
                                    else if(p == 7) check[3][1] = 7;
                                    else if(p == 8) check[3][2] = 7;
                                    else if(p == 9) check[3][3] = 7;
                                    for(int q = 1; q <= 9; q++){
                                        if(i == q || j == q || k == q || l == q || m == q || n == q || o == q || p == q) continue;
                                        if(q == 1) check[1][1] = 8;
                                        else if(q == 2) check[1][2] = 8;
                                        else if(q == 3) check[1][3] = 8;
                                        else if(q == 4) check[2][1] = 8;
                                        else if(q == 5) check[2][2] = 8;
                                        else if(q == 6) check[2][3] = 8;
                                        else if(q == 7) check[3][1] = 8;
                                        else if(q == 8) check[3][2] = 8;
                                        else if(q == 9) check[3][3] = 8;

                                        flag = false;

                                        
                                        if((c[1][1] == c[2][1] && check[1][1] < check[3][1] && check[2][1] < check[3][1]
                                        || (c[1][1] == c[3][1] && check[1][1] < check[2][1] && check[3][1] < check[2][1])
                                        || (c[2][1] == c[3][1] && check[2][1] < check[1][1] && check[3][1] < check[1][1]))){
                                            flag = true;
                                        }

                                        if((c[1][2] == c[2][2] && check[1][2] < check[3][2] && check[2][2] < check[3][2]
                                        || (c[1][2] == c[3][2] && check[1][2] < check[2][2] && check[3][2] < check[2][2])
                                        || (c[2][2] == c[3][2] && check[2][2] < check[1][2] && check[3][2] < check[1][2]))){
                                            flag = true;
                                        }

                                        if((c[1][3] == c[2][3] && check[1][3] < check[3][3] && check[2][3] < check[3][3]
                                        || (c[1][3] == c[3][3] && check[1][3] < check[2][3] && check[3][3] < check[2][3])
                                        || (c[2][3] == c[3][3] && check[2][3] < check[1][3] && check[3][3] < check[1][3]))){
                                            flag = true;
                                        }

                                        if((c[1][1] == c[1][2] && check[1][1] < check[1][3] && check[1][2] < check[1][3]
                                        || (c[1][1] == c[1][3] && check[1][1] < check[1][2] && check[1][3] < check[1][2])
                                        || (c[1][2] == c[1][3] && check[1][2] < check[1][1] && check[1][3] < check[1][1]))){
                                            flag = true;
                                        }

                                        if((c[2][1] == c[2][2] && check[2][1] < check[2][3] && check[2][2] < check[2][3]
                                        || (c[2][1] == c[2][3] && check[2][1] < check[2][2] && check[2][3] < check[2][2])
                                        || (c[2][2] == c[2][3] && check[2][2] < check[2][1] && check[2][3] < check[2][1]))){
                                            flag = true;
                                        }

                                        if((c[3][1] == c[3][2] && check[3][1] < check[3][3] && check[3][2] < check[3][3]
                                        || (c[3][1] == c[3][3] && check[3][1] < check[3][2] && check[3][3] < check[3][2])
                                        || (c[3][2] == c[3][3] && check[3][2] < check[3][1] && check[3][3] < check[3][1]))){
                                            flag = true;
                                        }

                                        if((c[1][1] == c[2][2] && check[1][1] < check[3][3] && check[2][2] < check[3][3]
                                        || (c[1][1] == c[3][3] && check[1][1] < check[2][2] && check[3][3] < check[2][2])
                                        || (c[2][2] == c[3][3] && check[2][2] < check[1][1] && check[3][3] < check[1][1]))){
                                            flag = true;
                                        }

                                        if((c[1][3] == c[2][2] && check[1][3] < check[3][1] && check[2][2] < check[3][1]
                                        || (c[1][3] == c[3][1] && check[1][3] < check[2][2] && check[3][1] < check[2][2])
                                        || (c[2][2] == c[3][1] && check[2][2] < check[1][3] && check[3][1] < check[1][3]))){
                                            flag = true;
                                        }

                                        if(flag) cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // 小数点10桁まで
    cout << fixed << setprecision(10);
    ans = (double)(total - cnt) / (double)total;
    cout << ans << endl;
    return 0;
}