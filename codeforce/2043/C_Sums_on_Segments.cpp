#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)



void solve(){
    int n;cin>>n;
    vector a(n,0LL);
    forn(i,0,n) cin>>a[i];
    int p = -1;
    forn(i,0,n){
        if(abs(a[i]) != 1){
            p = i;
            break;
        }
    }
    set<int> ans;
    // three situation
    ll mmax = 0LL,mmin = 0LL,lmax = 0LL,lmin = 0LL;
    ll s1 = 0LL,s2 = 0LL,ls = 0LL;
    for(int i = p-1;i>=0;i--){
        ls += a[i];
        lmax = max(lmax,ls);lmin = min(lmin,ls);
        if(s1 > 0) s1 = 0;
        if(s2 < 0) s2 = 0;
        s1 += a[i];
        s2 += a[i];
        mmax = max(mmax,s2);
        mmin = min(mmin,s1);
    }
    for(int k=mmin;k<=mmax;k++) ans.insert(k);
    mmax = 0LL;mmin = 0LL;
    ll rmax = 0LL,rmin = 0LL;
    s1 = 0LL;s2 = 0LL;ll rs = 0LL;
    for(int i=p+1;i<n;i++){
        rs += a[i];
        rmax = max(rmax,rs);rmin = min(rmin,rs);
        if(s1 > 0) s1 = 0;
        if(s2 < 0) s2 = 0;
        s1 += a[i];
        s2 += a[i];
        mmax = max(mmax,s2);
        mmin = min(mmin,s1);
    }
    for(int k=mmin;k<=mmax;k++) ans.insert(k);
    mmin = min(min(min(lmin + rmin,lmin),rmin),0LL);
    mmax = max(max(max(lmax + rmax,lmax),rmax),0LL);
    if(p != -1){
        for(int k=a[p] + mmin;k<=a[p] + mmax; k++) ans.insert(k);
    }

    vector<int> ret;
    ret.assign(all(ans));
    sort(all(ret));
    cout<<ret.size()<<"\n";
    for(auto x : ret) cout<<x<<" ";
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