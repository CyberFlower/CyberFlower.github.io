#include <bits/stdc++.h>
using namespace std;
string rev_string(string x){
    string res="";
    for(char a:x) res=a+res;
    return res;
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        unordered_set<string> d;
        vector<string> t;
        vector<int> ny;
        vector<int> nz;
        int arr[4]={0,};
        for(int i=0;i<n;i++){
            string x; cin>>x;
            t.push_back(x);
            int sz=x.size();
            arr[2*(x[0]-'0')+x[sz-1]-'0']++;
            d.insert(x);
        }
        for(int i=0;i<n;i++){
            string x=t[i];
            int sz=x.size();
            if(x[0]!=x[sz-1] && d.find(rev_string(x))==d.end()){
                if(x[0]=='0') ny.push_back(i);
                else nz.push_back(i);
            }
        }
        if(arr[0]>0 && arr[1]==0 && arr[2]==0 && arr[3]>0){
            cout<<-1<<'\n';
            continue;
        }
        int ans=(abs(arr[1]-arr[2]))/2;
        if(arr[1]>arr[2]){
            if(ny.size()>=ans){
                cout<<ans<<'\n';
                for(int i=0;i<ans;i++) cout<<ny[i]+1<<" ";
                cout<<'\n';
            }
            else{
                cout<<-1<<'\n';
                continue;
            }
        }
        else{
            if(nz.size()>=ans){
                cout<<ans<<'\n';
                for(int i=0;i<ans;i++) cout<<nz[i]+1<<" ";
                cout<<'\n';
            }
            else{
                cout<<-1<<'\n';
                continue;
            }
        }
    }
    return 0;
}