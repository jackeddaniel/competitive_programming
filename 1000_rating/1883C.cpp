#include <iostream>
#include <vector>

using namespace std;

int bt(vector<int>& nums, int i, int prod, int k) {
    if(prod % k == 0) return 0;

    int old = nums[i];
    nums[i]++;

    int new_prod = prod / old;
    new_prod = new_prod * (nums[i]);
    
    int skip = INT_MAX;

    int modify = 1 + bt(nums, i, new_prod, k);
    nums[i] = old;
    if(i < nums.size() - 1) skip = bt(nums, i+1, prod, k);

    int ans = min(modify, skip);
    return ans;
}

int help(vector<int>& nums, int k) {

    int prod = 1;
    for(int n : nums) {
        prod *= n;
    }

    return bt(nums, 0, prod, k); 
}

int main() {
    int n_test_cases;
    cin>>n_test_cases;

    vector<int> res;

    for(int i = 0; i < n_test_cases; i++) {
        int n, k;

        cin>>n>>k;

        vector<int> nums;

        for(int j = 0; j < n; j++) {
            int num;
            cin>>num;
            nums.push_back(num);
        }
        
        int ans = help(nums, k);
        res.push_back(ans);
    }

    for(int n : res) {
        cout<<n<<endl;
    }

}
