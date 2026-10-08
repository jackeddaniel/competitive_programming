#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;

    for(int i = 0; i < test_cases; i++) {
        long long n;
        long long p;

        cin>>n>>p;

        vector<long long> nums;
        vector<long long> weights;
        vector<pair<long long, long long>> villagers;

        for(int i = 0; i < n; i++) {
            long long num;
            cin>>num;
            nums.push_back(num);
        }

        for(int i = 0; i < n; i++) {
            long long weight;
            cin>>weight;

            weights.push_back(weight);
        }

        for(int i = 0; i < n; i++) {
            villagers.push_back({weights[i], nums[i]});
        }

        sort(villagers.begin(), villagers.end());

    
        long long delivered = 1;
        long long min_cost = p;

        for(auto v : villagers) {
            int num = v.second;
            int weight = v.first;

            if(weight >= p) {
                break;
            }

            if(delivered + num > n) {
                min_cost += weight * (n - delivered);
                delivered = n;
                break;
            }

            delivered += num;
            min_cost += weight * num;
        }

        min_cost += (n - delivered) * p;
        cout<<min_cost<<endl;
    }
}
