#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
	int N;
	cin >> N;
	vector<vector<int>>G(N+1);
	for(int i=1;i<=N;i++){
		int c;
		cin >> c;
		G[i].resize(c);
		for(auto&v:G[i])cin >> v;
	}

	vector<bool>visited(N+1);
	vector<int>ans;
    
	auto dfs=[&](auto self,int v)->void{
		for(auto vv:G[v])if(!visited[vv])self(self,vv);
		ans.push_back(v);
	    visited[v]=true;
	};
	dfs(dfs,1);
	ans.pop_back();  // 1 自身は除く
	for(auto v:ans)cout << v << " ";
    cout << endl;
}