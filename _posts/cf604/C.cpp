#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        vector<int> v;
        for(int i=0;i<n;i++) cin>>arr[i];
        v.pb(1);
        int idx=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i]) v[idx]++;
            else{
                v.pb(1);
                idx++;
            } 
        }
        int a=0,b=0,c=0;
        int sz=v.size();
        if(sz<3){
            cout<<0<<" "<<0<<" "<<0<<'\n';
            continue;
        }
        a=v[0];
        int p=1;
        while(p<sz && a>=b){
            b+=v[p++];
        }
        if(a>=b){
            cout<<0<<" "<<0<<" "<<0<<'\n';
            continue;            
        }
        while(p<sz && a>=c){
            c+=v[p++];
        }
        if(a>=c || a+b+c>n/2){
            cout<<0<<" "<<0<<" "<<0<<'\n';
            continue;            
        }
        while(p<sz && a+b+c<=n/2){
            c+=v[p++];
        }
        c-=v[p-1];
        cout<<a<<" "<<b<<" "<<c<<'\n';
    }
    return 0;
}