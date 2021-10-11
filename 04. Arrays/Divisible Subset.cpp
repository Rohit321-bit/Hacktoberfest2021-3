#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

void solve() {
    int n; cin >> n;
    map<int, vector<int>>hsh;
    vector<int>pre(n+1, 0);
    for(int i = 1; i<=n; i++) {
        cin >> pre[i];
        pre[i] += pre[i-1];

        hsh[pre[i]%n].push_back(i);
    }
    for(auto p: hsh) {
        if(p.first == 0) {
            cout << p.second[0] << '\n';
            for(int j = 1; j<=p.second[0]; j++) cout << j << " "; cout << "\n";
                return;
        } else {
            if(p.second.size() > 1) {
                cout << p.second[1] - p.second[0] << "\n";
                for(int j = p.second[0] + 1; j<=p.second[1]; j++) cout << j << " "; cout << "\n";
                return;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
