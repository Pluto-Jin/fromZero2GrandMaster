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

const int N=5e5+1;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m;
		ll k; cin>>n>>m>>k;
		for (int i=1;i<=n;i++) cin>>a[i];
		int l=1,r=1,ans=0;
		while (l<=n) {
			for (int up=0,flag=0;~up;up+=flag?-1:1) {
				if (r+(1<<up)>n) {flag=1;continue;}
				int mid=r,p=l,q=0;
				ll cur=0;
				vi tmp(a+mid+1,a+r+(1<<up)+1),ar;
				sort(tmp.begin(),tmp.end());
				while (p<=mid and q<tmp.size()) {
					while (p<=mid and a[p]<=tmp[q]) ar.pb(a[p++]);
					if (p>mid) while (q<tmp.size()) ar.pb(tmp[q++]);
					else while (q<tmp.size() and a[p]>=tmp[q]) ar.pb(tmp[q++]);
					if (q>=tmp.size()) while (p<=mid) ar.pb(a[p++]);
				}	
				for (int i=0,j=(int)ar.size()-1;i<j and i<m;i++,j--) 
					cur+=(1ll*ar[i]-ar[j])*(1ll*ar[i]-ar[j]);
				if (cur<=k) {
					for (int i=0;i<ar.size();i++) a[i+l]=ar[i];
					r+=1<<up;
				} else flag=1;
			}
			l=r+1;
			ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
