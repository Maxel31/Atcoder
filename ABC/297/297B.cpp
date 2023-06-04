#include <bits/stdc++.h>
#include <queue>
using namespace std;

string S;
string K[2],R[2],B[2];

bool Check1(int x, int y){
    if((x % 2) != (y % 2)) return true;
    else return false;
}

bool Check2(int x, int y, int z){
    if((x < z) && (z < y)) return true;
    else return false;
}

int main(){
    cin >> S;
    if(Check1(S.rfind('B'), S.find('B')) && Check2(S.find('R'), S.rfind('R'), S.find('K'))){
        cout << "Yes" << endl;
    }else cout << "No" << endl;

    return 0;
}