#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int SZ=200005;
ll arr[SZ];
ll memo[SZ];
ll rem[SZ];
ll max(ll a, ll b){
    return a>b?a:b;
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n,p,k; cin>>n>>p>>k;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            memo[i]=0;
            rem[i]=0;
        }
        sort(arr+1,arr+n+1);
        rem[1]=arr[1];
        for(int i=2;i<=n;i++){
            if(i>=k) rem[i]=rem[i-k]+arr[i];
            else rem[i]=rem[i-1]+arr[i];
        }
        int mx=0;
        memo[1]=(rem[1]<=p?1:0);
        mx=max(mx,memo[1]);
        for(int i=2;i<=n;i++){
            if(i>=k && p>=rem[i]) memo[i]=memo[i-k]+k;
            else if(i<k && p>=rem[i]) memo[i]=memo[i-1]+1;
            mx=max(mx,memo[i]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}