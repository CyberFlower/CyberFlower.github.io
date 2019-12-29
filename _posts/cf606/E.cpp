#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int SZ=200005;
vector<int> graph_a[SZ]; //not connected by a
vector<int> graph_b[SZ]; //not connected by b
int vst_a[SZ];
int vst_b[SZ];
int n;
void dfs_a(int x){
    vst_a[x]=1;
    for(int nxt:graph_b[x]){
        if(vst_a[nxt]) continue;
        dfs_a(nxt);
    }
}
void dfs_b(int x){
    vst_b[x]=1;
    for(int nxt:graph_a[x]){
        if(vst_b[nxt]) continue;
        dfs_b(nxt);
    }
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int m,a,b; cin>>n>>m>>a>>b;
        for(int i=1;i<=n;i++){
            vst_a[i]=0;
            vst_b[i]=0;
            graph_a[i].clear();
            graph_b[i].clear();            
        }
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            if(x!=a && y!=a){
                graph_a[x].push_back(y);
                graph_a[y].push_back(x);
            }
            if(x!=b && y!=b){
                graph_b[x].push_back(y);
                graph_b[y].push_back(x);                
            }
        }
        dfs_a(a);
        dfs_b(b);
        ll xx=0,yy=0;
        for(int i=1;i<=n;i++){
            if(vst_a[i] && vst_b[i]) continue;
            if(vst_a[i]) xx++;
            if(vst_b[i]) yy++;
        }
        cout<<(xx-1)*(yy-1)<<'\n';
    }
    return 0;
}