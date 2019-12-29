#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int SZ=200005;
int arr[SZ];
int idx[SZ];
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            arr[i+1]=x;
            idx[x]=i+1;
        }
        int l=n+1,r=0;
        string ans="";
        for(int i=1;i<=n;i++){
            l=min(l,idx[i]);
            r=max(r,idx[i]);
            if(r-l+1==i) ans+='1';
            else ans+='0';
        }
        cout<<ans<<'\n';
    }
    return 0;
}