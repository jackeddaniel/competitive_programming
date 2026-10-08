#include <climits>
#include<iostream>
#include<cmath>
#include<numeric>

using namespace std;

using ll = long long;

ll find_lcm(ll i, ll j) {
    if(i == 0 || j == 0) return 0;

    return abs(i)/gcd(i, j) * abs(j);

}

int main() {
    int t;
    cin>>t;


    while(t--) {
        ll n;
        cin>>n;
        ll min_lcm = LLONG_MAX;
        ll a = n;
        ll b = 0;

        for(ll i = 1; i <= n/2; i++) {
            if(n % a != 0) continue;
            ll j = n - i;

            
            ll lcm = find_lcm(i, j);

            if(lcm < min_lcm) {
                min_lcm = lcm;
                a = i;
                b = j;
            }

        }

        cout<<a<<" "<<b<<endl;
    }

}
