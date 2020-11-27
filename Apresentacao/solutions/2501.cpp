#include <bits/stdc++.h>

using namespace std;
using Int = unsigned long long int;

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
vector<int> primes;

Int fatores(int n, int m){
	priority_queue<Int, vector<Int>, greater<int>> pq;
	for (int i = 0; i < n; ++i)
	{
		pq.push(primes[i]);
	}
	int count=1;
	Int no;
	while(count <= m){
		no = pq.top();
		pq.pop();
		while(no == pq.top()) pq.pop();
		for(int i=0;i<n;i++){
			pq.push(no*primes[i]);
		}
		count++;
	}
	return no;
}

int main(){
	_
	int m, n;

	while(cin >> n >> m && n!=0 && m!=0){
		primes.reserve(n+1);
		for (int i = 0; i < n; ++i)
		{
			cin >> primes[i];
		}

		Int result = (n==1)? pow(primes[0], m):fatores(n,m);
		cout << result << endl;
	}
	return 0;
}