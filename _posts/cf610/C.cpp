#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int SZ=200005;
pii arr[SZ];
int pre[2][SZ];
ll max(ll a, ll b){return a>b?a:b;}
ll min(ll a, ll b){return a<b?a:b;}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m; cin>>m;
    while(m--){
        ll n,t,a,b; cin>>n>>t>>a>>b;
        ll z=0,o=0;
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            arr[i].ss=x;
            if(x==0) z++;
            else o++;
            pre[0][i]=0; pre[1][i]=0;
        }
        for(int i=1;i<=n;i++) cin>>arr[i].ff;
        sort(arr+1,arr+n+1);
        vector<ll> v1,v2;
        ll xx=0;
        for(int i=1;i<=n;i++){
            v1.pb(arr[i].ff);
            xx=xx+(arr[i].ss==0?a:b);
            v2.pb(xx);
            pre[0][i]=pre[0][i-1]+(arr[i].ss==0?1:0);
            pre[1][i]=pre[1][i-1]+(arr[i].ss==1?1:0);
        }
        pre[0][n+1]=z, pre[1][n+1]=o;
        v1.pb(max(arr[n].ff,t));
        int ans=max(0,min(z,(v1[0]-1)/a));
        for(int i=0;i<n;i++){
            if(v2[i]>t) break;
            if(v1[i+1]>v2[i]){
                ll xx=i+1;
                ll tt=v1[i+1]-v2[i]-1;
                if(tt>(z-pre[0][i+1])*a){
                    xx+=(z-pre[0][i+1]);
                    tt-=(z-pre[0][i+1])*a;
                    xx+=min(o-pre[1][i+1],tt/b);
                }
                else xx+=(tt/a);
                ans=max(ans,xx);
            }
        }
        if(v2[n-1]<=t) ans=max(ans,n);
        cout<<ans<<'\n';
    }
    return 0;
}