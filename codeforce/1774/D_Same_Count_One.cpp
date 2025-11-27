#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,m;cin>>n>>m;
    vector a(n,vector(m,0));
    int total = 0;
    vector l(n,0);
    forn(i,0,n){
        int temp = 0;
        forn(j,0,m){
            cin>>a[i][j];
            temp += a[i][j];
        }
        l[i] = temp;
        total += temp;
    }
    if(total%n){
        cout<<-1<<"\n";
        return;
    }
    total /= n;
    vector<tuple<int,int,int>> ans;
    forn(i,0,m){
        vector<int> t1,t2;
        forn(j,0,n){
            if(l[j] > total && a[j][i] == 1) t1.emplace_back(j);
            if(l[j] < total && a[j][i] == 0) t2.emplace_back(j);
        }
        forn(k,0,min(t1.size(),t2.size())){
            ans.emplace_back(t1[k]+1,t2[k]+1,i+1);
            l[t1[k]] --;
            l[t2[k]] ++;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto [t1,t2,t3] : ans){
        cout<<t1<<" "<<t2<<" "<<t3<<"\n";
    }
    
    

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