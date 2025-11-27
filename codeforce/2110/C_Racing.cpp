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
    vector<int> space;
    forn(i,0,n){
        cin>>a[i];
    } 
  
    vector<pair<int,int>> range(n);
    forn(i,0,n) cin>>range[i].first>>range[i].second;
    vector<pair<int,int>> pro;
    int l = 0, r = 0;
    forn(i,0,n){
        if(a[i] == 1){
            l++;
            r++;
        }
        if(a[i] == -1){
            r++;
        }
        if(range[i].first > r || range[i].second < l){
            cout<<-1<<"\n";
            return;
        }
        l = max(l,range[i].first);
        r = min(r,range[i].second);
        pro.push_back({l,r});
    }
    int d = 0;
    forn(i,0,n){
        if(a[i] == -1) space.push_back(i);
        //cout<<"pro:"<<pro[i].first<<","<<pro[i].second<<"d: "<<d<<"\n";
        if(a[i] == 1) d++;
        while(pro[i].first > d){
            int t = space.back();
            space.pop_back();
            a[t] = 1;
            d++;
        }
    }
    for(auto x : a){
        if(x == -1) cout<<0;
        else cout<<x;
        cout<<" ";
    }
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