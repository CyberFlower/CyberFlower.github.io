#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define INF (int)1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool isbeauti(string x){
	int sz=x.size();
	for(int i=1;i<sz;i++){
		if(x[i-1]==x[i]) return false;
	}
	return true;
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
	while(t--){
		string s; cin>>s;
		int sz=s.size();
		for(int i=0;i<sz;i++){
			int vst[3]={0,};
			if(s[i]=='?'){
				if(i>0 && s[i-1]!='?') vst[s[i-1]-'a']=1;
				if(i<sz-1 && s[i+1]!='?') vst[s[i+1]-'a']=1;
				for(int j=0;j<3;j++){
					if(vst[j]==0){
						s[i]='a'+j;
						break;
					}
				}
			}
		}
		if(isbeauti(s)) cout<<s<<'\n';
		else cout<<-1<<'\n';
	}
    return 0;
}