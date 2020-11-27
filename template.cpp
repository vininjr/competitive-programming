#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#include <bits/stdc++.h>

using namespace std;
using Int = unsigned long long int;

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define debug(x) cerr << #x << " = " << x << endl
#define endl '\n'
#define mod 1e9 + 7

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Int a[N];
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
        }
        cout << "1" << endl;
    }
    return 0;
}
