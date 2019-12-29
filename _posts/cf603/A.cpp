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
		int a,b,c; cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(a>c) swap(a,c);
		if(b>c) swap(b,c);
		int ans=0;
		int tmp=min(a,(c-b));
		ans+=tmp; 
		a-=tmp; 
		c-=tmp;

		if(a!=0){
			if(a%2==0){
				ans+=a;
				b-=a/2; c-=a/2;
			}
			else{
				ans+=a;
				int xx=a/2;
				b-=xx;
				c-=(xx+1);
			}
		}
		ans+=min(b,c);
		cout<<ans<<'\n';
	}
    return 0;
}