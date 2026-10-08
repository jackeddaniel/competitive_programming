#include <iostream>
#include <vector>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;

    for(int i = 0; i < test_cases; i++) {
        int n;
        cin>>n; 
        vector<vector<long long>> arrays;
        
        //build the array of arrays
        for(int i = 0; i < n; i++) {
            int size;
            cin>>size;
            vector<long long> arr;
            for(int i = 0; i < size; i++) {
                int num;
                cin>>num;
                arr.push_back(num);
            }

            sort(arr.begin(), arr.end());
            arrays.push_back(arr);
        }

        long long second_min_sum =0;
        long long s_min_idx = 0;
        long long s_min_val = arrays[0][1];
        long long min_el = arrays[0][0];

        for(int i = 0; i < n; i++) {
            int s_min = arrays[i][1];
            min_el = min(min_el, arrays[i][0]);

            if(s_min < s_min_val) {
                s_min_idx = i;
                s_min_val = s_min;
            }
            second_min_sum += s_min;
        }

        long long min_sz = arrays[s_min_idx].size();

        long long ans = second_min_sum - s_min_val + min_el;
        cout<<ans<<endl;
    }
}
