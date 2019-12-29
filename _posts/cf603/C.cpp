#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        vector<int> ans;
        ans.pb(0);
        int n; cin>>n;
        int xx=sqrt(n);
        for(int i=1;i<=xx;i++){
            ans.pb(n/(n/i));
            ans.pb(n/i);
        }
        sort(ans.begin(),ans.end());
        ans.resize(distance(ans.begin(),unique(ans.begin(),ans.end())));
        cout<<ans.size()<<'\n';
        for(int x:ans) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}