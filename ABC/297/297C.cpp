#include <bits/stdc++.h>
#include <queue>
using namespace std;

int H,W;
string S[109];

void Change_Word(string s, int w){
    for(int j = 0; j < w-1; j++){
        if(s[j] == 'T' && s[j+1] == 'T'){
            s[j] = 'P';
            s[j+1] = 'C';
            //cout << "Swap!" << endl;
        }
    }
    cout << s << endl;
}

int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> S[i];
        Change_Word(S[i],W);
    }
    return 0;
}