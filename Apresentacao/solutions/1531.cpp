#include <bits/stdc++.h>

using namespace std;
using Int = unsigned long long int;

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);

Int getPisano(Int m){
	Int a=0, b=1, c=a+b;
	for (Int i = 0; i < m*m; ++i)
	{
		c = (a+b) % m; // a+b == m
		a = b;//a=0
		b = c;
		if(a == 0 && b == 1) return i+1;
	}
}

// <f(n), f(n+1)>
// O(logn)
pair<Int, Int> fib(Int n, Int mod){
	if(n==0){
		return {0, 1};
	}
	Int k;
	if(n & 1){
		k = (n-1)/2;
		pair<Int, Int> res = fib(k, mod);
		Int a = res.first; //F(k)
		Int b = res.second; //F(k+1)
		Int c = (a*(2*b - a+mod)) % mod; //F(2k)
		Int d = (a*a)%mod + (b*b)%mod; //F(2k+1)
		return {d % mod, (c+d)%mod};
	}
	else{
		k = n/2;
		pair<Int, Int> res = fib(k, mod);
		Int a = res.first;
		Int b = res.second;
		return {(a*(2*b -a+mod))%mod, (a*a)%mod+(b*b)%mod};
	}
}

int main(){
	Int n,m;

	while(cin >> n >> m){
		Int mod = getPisano(m);
		Int v1 = fib(n, mod).first;
		cout << fib(v1,m).first << endl;
	}
	return 0;
}