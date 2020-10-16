#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,q; cin>>n>>q;
		vi ar(n+2),clr(n+2);
		for (int i=1;i<=n;i++) cin>>ar[i];
		ar[0]=ar[n+1]=0;
		for (int i=1;i<=n;i++) {
			if (ar[i]>ar[i-1] and ar[i]>ar[i+1]) clr[i]=1;
			else if (ar[i]<ar[i-1] and ar[i]<ar[i+1]) clr[i]=-1;
		}
		ll ans=0;
		for (int i=1;i<=n;i++) ans+=1ll*clr[i]*ar[i];
		cout<<ans<<endl;
		for (int i=0;i<q;i++) {
			int x,y; cin>>x>>y;
			for (int k=0;k<2;k++) {
				if (k) swap(x,y);
				int a=ar[x-1],b=ar[x+1],c=ar[x];
				if (y==x-1) a=ar[x-2];
				if (c>a and c>b) ans+=max(a,b)-c;
				if (c<a and c<b) ans+=c-min(a,b);
			}
			swap(ar[x],ar[y]);
			for (int k=0;k<2;k++) {
				if (k) swap(x,y);
				int a=ar[x-1],b=ar[x+1],c=ar[x];
				if (y==x-1) a=ar[x-2];
				if (c>a and c>b) ans+=c-max(a,b);
				if (c<a and c<b) ans+=min(a,b)-c;
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
