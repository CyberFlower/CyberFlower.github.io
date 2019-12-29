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
		int sz=0;
		int test=1;
		for(int i=1;i<10;i++){
			test=10*test;
			if(n<test){
				sz=i;
				break;
			}
		}
		if(sz==0) sz=10;
		int y=1;
		for(int i=1;i<sz;i++) y=y*10+1;
		cout<<(sz-1)*9+n/y<<'\n';
	}
    return 0;
}