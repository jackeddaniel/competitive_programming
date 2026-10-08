#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;

    for(int i = 0; i < test_cases; i++) {
        int n;
        long long k;

        cin>>n>>k;


        vector<pair<long long, int>> monsters;
        for(int i = 0; i < n; i++) {
            long long health;
            cin>>health;

            monsters.push_back({health, i+1});
        }


        for(auto& it : monsters) {
            int health = it.first;

            if(health % k == 0) {
                it.first = k;
            } else {
                it.first = health % k;
            }
        }

        sort(monsters.begin(), monsters.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first)
        return a.first > b.first;  // first descending

    return a.second < b.second;     // second ascending
});
        

        for(auto it : monsters) cout<<it.second<<" ";
        cout<<endl;
    }
    
}
