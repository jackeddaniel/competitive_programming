#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int test_case;
    cin>>test_case;

    for(int i = 0; i < test_case; i++) {
        ll n;
        char c;
        string s;

        cin>>n>>c>>s;
        if(c == 'g') {
            cout<<0<<endl;
            continue;
        }

        vector<int> help(2*n, 0);
        s += s;
        
        ll max_r = 0;
        ll max_y = 0;

        int green = -1;
        for(int i = (int)n - 1; i > -1; i--) {
            if(s[i] == 'g') {
                green = i;
            } else {
                if(green != -1) {
                    help[i] = green - i;
                    if(s[i] == 'r') {
                        max_r = max(max_r, (ll)help[i]);
                }
                    if(s[i] == 'y') {
                        max_y = max(max_y, (ll)help[i]);
                    }
                }
            }
        }

        if(c == 'r') cout<<max_r<<endl;
        if(c == 'y') cout<<max_y<<endl;
    }
}
