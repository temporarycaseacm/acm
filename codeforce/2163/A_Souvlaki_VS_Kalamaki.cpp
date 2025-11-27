#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector a(n,0);
    forn(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    for(int i=1;i<n;i+=2){
        if(i<n-1 && a[i] != a[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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