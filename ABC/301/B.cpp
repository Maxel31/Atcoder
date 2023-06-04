#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> A;

void Insert_Number(vector<int> a){
    for(int i=1;i<a.size();i++){
	        if(a[i-1]+1<a[i])a.insert(a.begin()+i,a[i-1]+1);
	        if(a[i-1]-1>a[i])a.insert(a.begin()+i,a[i-1]-1);
	}
    for(auto x:a)cout << x << ' ';
    cout << endl;
}

int main() {
    int n;
	cin >> n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin >> a[i];

    Insert_Number(a);
    return 0;
}
