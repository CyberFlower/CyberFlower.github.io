#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<int,int> vst;
priority_queue<int> pq;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        while(!pq.empty()){
            pq.pop();
        }
        vst.clear();
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            if(x%2==1) continue;
            vst[x]=1;
        }
        for(auto x:vst){
            pq.push(x.first);
        }
        int ans=0;
        while(!pq.empty()){            
            int t=pq.top(); pq.pop();
            if(t%2==1) continue;
            ans++;
            if(vst.find(t/2)!=vst.end()){
                vst[t/2]++;
                continue;
            }
            vst[t/2]=1;
            pq.push(t/2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}