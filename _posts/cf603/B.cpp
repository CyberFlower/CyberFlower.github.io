#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int SZ=10005;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> arr;
        map<string,int> vst;
        map<string,int> memo;
        for(int i=0;i<n;i++){
            string x; cin>>x;
            arr.pb(x);
            //vst[x]++;
            memo[x]++;
        }
        int cnt=0;
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(vst.find(arr[i])==vst.end()){
                vst[arr[i]]=1;
                ans.pb(arr[i]);
            }
            else{
                cnt++;
                string tmp=arr[i];
                for(int j=0;j<4;j++){
                    bool flg=false;
                    for(int k=0;k<10;k++){
                        tmp[j]='0'+k;
                        if(vst.find(tmp)==vst.end() && memo.find(tmp)==memo.end()){
                            flg=true;
                            ans.pb(tmp);
                            vst[tmp]=1;
                            break;
                        }
                    }
                    if(flg) break;
                }
            }
        }
        cout<<cnt<<'\n';
        for(string xx:ans) cout<<xx<<'\n';

    }
    return 0;
}