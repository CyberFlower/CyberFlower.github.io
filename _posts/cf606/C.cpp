#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char one[3]={'o','n','e'};
char two[3]={'t','w','o'};
const int SZ=1500005;
int vst[SZ];
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        vector<int> ans;
        string s; cin>>s;
        int sz=s.length();
        for(int i=0;i<sz;i++) vst[i]=0;
        for(int i=0;i<sz-2;i++){
            bool flg=true;
            for(int j=0;j<3;j++){
                if(s[i+j]!=two[j]){
                    flg=false;
                    break;
                }
            }
            if(flg){
                if(i<sz-4){
                    bool twone=true;
                    for(int j=1;j<3;j++){
                        if(s[i+2+j]!=one[j]){
                            twone=false;
                            break;
                        }
                    }
                    if(twone){
                        vst[i+2]=1;
                        ans.push_back(i+3);
                    }
                    else ans.push_back(i+2);
                }
                else ans.push_back(i+2);
            }
        }
        for(int i=0;i<sz-2;i++){
            if(vst[i]) continue;
            bool flg=true;
            for(int j=0;j<3;j++){
                if(s[i+j]!=one[j]){
                    flg=false;
                    break;
                }
            }
            if(flg) ans.push_back(i+2);
        }                
        int ans_sz=ans.size();
        cout<<ans_sz<<'\n';
        for(int i=0;i<ans_sz;i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}