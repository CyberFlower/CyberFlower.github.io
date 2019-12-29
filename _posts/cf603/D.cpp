#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int SZ=200005;
const int AL=30;
vector<int> graph[SZ];
vector<int> alpha[AL];
int vst[SZ];
int dfs(int x){
    vst[x]=1;
    for(int nxt:graph[x]){
        if(vst[nxt]) continue;
        dfs(nxt);
    }
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string x; cin>>x;
        arr.pb(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<=n;i++){
        string x=arr[i-1];
        for(char xx:x) alpha[xx-'a'].pb(i);
    }
    for(int i=0;i<26;i++){
        sort(alpha[i].begin(),alpha[i].end());
        alpha[i].resize(distance(alpha[i].begin(),unique(alpha[i].begin(),alpha[i].end())));
        int sz=alpha[i].size();
        if(sz>1){
            for(int j=1;j<sz;j++){
                graph[alpha[i][0]].pb(alpha[i][j]);
                graph[alpha[i][j]].pb(alpha[i][0]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vst[i]) continue;
        ans++;
        dfs(i);
    }
    cout<<ans;
    return 0;
}