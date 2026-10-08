#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(vector<ll>& temps, int n, int k, ll q) {
    ll count = 0;

    int valid = 0;

    for(ll x : temps) {
        if(x <= q) {
            valid++;
        } else {
            valid = 0;
        }

        if(valid >= k) {
            count += valid - k + 1;
        }
    }
    return count;
}

int main() {
    int test_cases;
    cin>>test_cases;

    for(int i = 0; i < test_cases; i++) {
        ll n, k, q;
        cin>>n>>k>>q;

        vector<ll> temps;
        for(int j = 0; j < n; j++) {
            ll num;
            cin>>num;
            temps.push_back(num);
        }

        ll ans = solve(temps, n, k, q);
        cout<<ans<<endl;
    }
}
