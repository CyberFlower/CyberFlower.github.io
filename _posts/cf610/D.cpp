#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int query(string x){
    cout<<x<<endl;
    int res; cin>>res;
    if(res==0) exit(0);
    return res;
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string x1=""; string x2="";
    for(int i=0;i<300;i++){
        x1+='a'; x2+='b';
    }
    int a=300-query(x1);
    int b=300-query(x2);
    int sz=a+b;
    int t=sz;
    string ans="", tmp="";
    for(int i=0;i<sz;i++){
        ans+='a'; tmp+='a';
    }
    int bb=0;
    for(int i=0;i<sz-1;i++){
        tmp[i]='b';
        int xx=query(tmp);
        if(xx==b-1){
            ans[i]='b';
            bb++;
        }
        tmp[i]='a';
    }
    if(bb!=b) ans[sz-1]='b';
    query(ans);
    return 0;
}