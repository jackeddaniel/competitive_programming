#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;

    for(int ti = 0; ti < t; ti++) {

        int n;
        cin>>n;
        vector<int> a;
        vector<int> b;

        for(int i = 0; i < n; i++) {
            int num;
            cin>>num;
            a.push_back(num);
        }

        for(int i = 0; i < n;i++) {
            int num;
            cin>>num;
            b.push_back(num);
        }

        vector<int> fa(n+n+1, 0);
        vector<int> fb(n+n+1, 0);
        
        int p = 0;
        for(int i = 1; i < n; i++) {
            if(a[i-1] != a[i]) {
                fa[a[i-1]] = max(fa[a[i-1]], i - p);
                p = i;
            }
        }
        fa[a[n-1]] = max(fa[a[n-1]], n - 1 - p + 1);


        
        p = 0;
        for(int i = 1; i < n; i++) {
            if(b[i-1] != b[i]) {
                fb[b[i-1]] = max(fb[b[i-1]], i - p);
                p = i;
            }
        }
        fb[b[n-1]] = max(fb[b[n-1]], n-1-p+1);


        int ans = 0;

        for(int i = 0; i < n+n+1; i++) {
            ans = max(ans, fa[i] + fb[i]);
        }
        cout<<ans<<endl;

    }
}
