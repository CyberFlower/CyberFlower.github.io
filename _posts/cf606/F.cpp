#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef pair<int,int> pii;
const int SZ=400005;
int pre[SZ];
map<int,int> memo;
map<int,int> knd;
vector<int> v;
inline bool myf(pii x, pii y){
    return x>y;
}
void print_arr(int n, int m){
    vector<vector<int>> arr(n,vector<int>(m,0));
    vector<pair<int,int>> t1; 
    vector<int> t2;
    int idx=0;
    for(auto xx:memo) t1.pb({xx.second,xx.first});
    sort(t1.begin(),t1.end(),myf);
    for(auto xx:t1){
        for(int i=0;i<min(xx.first,n);i++) t2.pb(xx.second);
    }
    int x=0,y=0;
    for(int i=0;i<n*m;i++){
        if(arr[x][y]) x=(x+1)%n;
        arr[x][y]=t2[i];
        x=(x+1)%n;
        y=(y+1)%m;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
        cout<<'\n';
    }
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.pb(x);
        memo[x]++;
    }
    int kmx=0;
    for(auto xx:memo){
        knd[xx.second]++; 
        kmx=max(kmx,xx.second);
    }
    for(int i=1;i<=kmx;i++){
        if(knd.find(i)!=knd.end()) pre[i]=pre[i-1]+knd[i];
        else pre[i]=pre[i-1];
    }
    for(int i=n;i>0;i--){
        int stt=(int)sqrt(i);
        int sz=memo.size();
        int xx=0;
        for(int j=1;j*j<=i;j++){
            xx+=sz-pre[j-1];
            //cout<<"AA "<<j<<" "<<xx<<'\n';
            if(i%j) continue;
            if(xx>=i){
                cout<<i<<'\n';
                cout<<j<<" "<<i/j<<'\n';
                print_arr(j, i/j);
                return 0;
            }
        }
    }
    return 0;
}