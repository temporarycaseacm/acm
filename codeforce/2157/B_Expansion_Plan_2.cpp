#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,x,y;cin>>n>>x>>y;
    string s;cin>>s;
    x = abs(x);y= abs(y);
    int p = n;
    while(x&&y&&p){
        if(s[p-1] == '8'){
            x--;y--;
        }else{
            if(x > y) x--;
            else y--;
        }
        p--;
    }
    if(x&&y) cout<<"NO\n";
    else if(x == 0 && y > p) cout<<"NO\n";
    else if(y == 0 && x > p) cout<<"NO\n";
    else cout<<"YES\n";
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