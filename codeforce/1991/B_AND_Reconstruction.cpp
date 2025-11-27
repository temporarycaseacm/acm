#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector b(n-1,0);
    forn(i,0,n-1) cin>>b[i];
    vector ans(n,0);
    ans[0] = b[0];
    ans[n-1] = b[n-2];
    forn(i,1,n-1){
        ans[i] = b[i-1] | b[i];
    }
    forn(i,0,n-1){
        if((ans[i]&ans[i+1]) != b[i]){
            cout<<-1<<"\n";
            return;
        }
    }
    for(auto x : ans) cout<<x<<" ";
    cout<<"\n";
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}   