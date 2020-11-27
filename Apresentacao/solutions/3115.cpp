#include <bits/stdc++.h>

using namespace std;
using Int = unsigned long long int;

const int MAXN = 1e5+1;
vector<pair<int, Int>> graph[MAXN];

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);

void dfs(int v, int p, Int min_cap, vector<Int> &ans){
	ans[v] = min_cap;
	int u;
	Int w;
	for(pair<int, Int> e: graph[v]){
		u = e.first;
		w = e.second;
		if(u == p) continue;
		dfs(u, v, min(w, min_cap),ans);
	}
}

int main(){
	_
	int n, v, u;
	cin >> n;
	vector<Int> ans(n+1);
	Int c;
	for (int i = 1; i < n; ++i)
	{
		cin >> v >> u >> c;
		graph[v].push_back({u, c});
		graph[u].push_back({v, c});
	}

	dfs(n, 1, INT_MAX, ans);

	for (int i = 1; i < n; ++i)
	{
		cout << ans[i];
		if(i!=n-1) cout << " ";
	}

	cout << endl;

	return 0;
}