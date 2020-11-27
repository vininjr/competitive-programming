#include <bits/stdc++.h> // standard template library (STL)

#define MODL 1300031

using namespace std;

using Int = unsigned long long int;
vector<bool> table;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0); // truque para ler entradas grandes.
    Int I, F, N, T;

    cin >> T;

    while (T--) {
        Int sum = 0, apl;
        cin >> I >> F >> N;
        table.reserve(F-I);
        bool check_1=false, check_2=false;

        for (Int i = 0; i < N; i++) {
            cin >> apl;
            if(check_1) continue;
            if(check_2 && apl % 2 == 0) continue;
            if(apl==1) check_1=true;
            if(apl==2) check_2=true;
            for (Int k = apl; k <= F; k += apl) {
                if(k < I || table[F-k]) continue;
                sum = (sum + k) % MODL;
                table[F-k]=true;
            }
        }
        cout << sum << endl;

    }

    return 0;
}
