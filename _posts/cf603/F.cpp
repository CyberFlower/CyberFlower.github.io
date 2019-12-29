#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to,rev,cap,cost;
    Edge(int to, int rev, int cap, int cost):
        to(to),rev(rev),cap(cap),cost(cost){}
};
class MCMF{
private:
    const int INF=1e9+7;
    vector<vector<Edge>> graph;
    vector<pair<int,int>> par;
    int n,src,snk;
public:
    MCMF(int n, int src, int snk):n(n),src(src),snk(snk){
        graph.resize(n+5);
        par.resize(n+5);
    }
    void push_edge(int a, int b, int capa, int cst){
        graph[a].push_back(Edge(b,graph[b].size(),capa,cst));
        graph[b].push_back(Edge(a,graph[a].size()-1,0,-cst));
    }
    bool SPFA(){
        vector<int> inq,dst;
        inq.resize(n+5,0);
        dst.resize(n+5,INF);    
        queue<int> q;
        q.push(src); inq[src]=1; dst[src]=0;
        while(!q.empty()){
            int h=q.front(); q.pop();
            inq[h]=0;
            for(int i=0;i<(int)graph[h].size();i++){
                auto e=graph[h][i];
                if(e.cap<=0) continue;
                if(dst[h]<INF && dst[e.to]>dst[h]+e.cost){
                    dst[e.to]=dst[h]+e.cost; par[e.to]={h,i};
                    if(inq[e.to]==0){
                        q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        return dst[snk]!=INF;
    }
    pair<int,int> flow(){
        int work=0,money=0;
        while(SPFA()){
            int c=0, f=INF;
            for(int i=snk;i!=src;i=par[i].first){
                auto &e=graph[par[i].first][par[i].second];
                f=min(f,e.cap);
                c+=e.cost;
            }
            work+=f;
            money+=f*c;
            for(int i=snk;i!=src;i=par[i].first){
                auto &e=graph[par[i].first][par[i].second];
                e.cap-=f;
                graph[e.to][e.rev].cap+=f;
            }
        }
        return {work,money};
    }
};
const int SZ=2005;
int tp[SZ];
int tnp[SZ];
int bp[SZ];
int bnp[SZ];
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    int t; cin>>t;
    for(int i=2;i<=t;i++){
        int x; cin>>x;
        tp[i]=x;
    }
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        tnp[i]=x;
    }
    int b; cin>>b;
    for(int i=2;i<=b;i++){
        int x; cin>>x;
        bp[i]=x;
    }
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        bnp[i]=x;
    }
    MCMF mc=MCMF(b+t+n+3,0,b+t+n+2);
    mc.push_edge(0,1,n,0);
    mc.push_edge(1,2,n,0); mc.push_edge(1,t+2,n,0);
    
    for(int i=2;i<=t;i++) mc.push_edge(tp[i]+1,i+1,n,1);
    for(int i=1;i<=n;i++) mc.push_edge(tnp[i]+1,i+b+t+1,1,0);
    for(int i=2;i<=b;i++) mc.push_edge(bp[i]+t+1,i+t+1,n,1);
    for(int i=1;i<=n;i++) mc.push_edge(bnp[i]+t+1,i+b+t+1,1,0);

    for(int i=1;i<=n;i++)mc.push_edge(i+b+t+1,b+t+n+2,1,0);
    auto xx=mc.flow();
    if(xx.first!=n){
        cout<<"wow";
        return -1;
    }
    cout<<b+t-2-xx.second;
    return 0;
}