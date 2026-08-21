#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(string s) {
    int zeros = count(s.begin(), s.end(), '0');
    int ones = s.size() - zeros;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            zeros--;
        } else {
            ones--;
        }

        if(zeros < 0 || ones < 0) {
            return s.size() - i;
        }
    }
    return 0;
}

int main() {
    int n;
    cin>>n;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;

        int ans = solve(s);
        res.push_back(ans);
    }


    for(int i : res) {
        cout<<i<<endl;
    }
}
