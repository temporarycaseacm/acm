#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,k,t;cin>>n>>k;
    vector a(n,0);
    forn(i,0,n){
        cin>>t;
        if(t <= k) a[i] = -1;
        else a[i] = 1;
    }
    vector pre_sum(n+1,0);
    forn(i,1,n+1){
        pre_sum[i] = pre_sum[i-1] + a[i-1];
    }
    int l = 0, r = n - 1;
    while(l < n && pre_sum[l+1] > 0) l ++;
    while(r >= 0 && pre_sum[n] - pre_sum[r] > 0) r--;
    if(r - l > 1){
        cout<<"YES\n";
        return;
    }
    l++;
  
    while(l < n - 1 && (pre_sum[l+1] > 0 || a[l] > 0)) l ++;
    if(l < n - 1){
        cout<<"YES\n";
        return;
    }
    r--;
    while(r > 0 && (pre_sum[n] - pre_sum[r] > 0 || a[r] > 0))  r--;
    if(r > 0){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    
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