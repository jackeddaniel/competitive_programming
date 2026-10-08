#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;

    for(int t = 0; t < test_cases; t++) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        unordered_map<char, int> left, right;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            left[s[i]]++;
        }

        for(int i = n - 1; i > -1; i--) {
            if(left.find(s[i]) != left.end()) {
                left[s[i]]--;
                if(left[s[i]] == 0) left.erase(s[i]);
            }
            right[s[i]];
            ans = max(ans,(int)(left.size() + right.size()));

        }


        cout<<ans<<endl;
    }
}
