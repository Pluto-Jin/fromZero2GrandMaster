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
#include<iomanip>

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

const int N=2e5+1;
vector<pll> tmp;
ll n,a[N],b[N],mem[N],cnt;

ll check() {
	int ok=1;
	for (int i=1;ok and i<n;i++) if (b[i]==b[i+1]) ok=0;
	if (n>1 and ok) {
		if (b[tmp[0].se]==mem[tmp[0].se]) {
			b[tmp[0].se]^=1;
			for (int i=1;i<n;i++) if (b[tmp[i].se]==b[tmp[0].se]) {
				b[tmp[i].se]^=1;
				break;
			}
		} else {
			int tt=b[tmp[0].se],pos;
			for (auto [i,j]:tmp) if (b[j]==tt and b[j]!=mem[j]) pos=j;
			for (auto [i,j]:tmp) if (b[j]!=tt) {
				b[j]^=1;
				break;
			}
			b[pos]^=1;
		}
	}
	ll res=0;
	for (int i=1;i<=n;i++) if (b[i]) res-=a[i]; else res+=a[i];
	memcpy(b,mem,sizeof b);
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	tmp.resize(n);
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		tmp[i-1]=mp(abs(a[i]),i);
		if (a[i]<0) mem[i]=b[i]=1,cnt++;
	}
	sort(tmp.begin(),tmp.end());
	ll ans=-1e18;
	if ((cnt+n)%3==0) {
		int pos=0,neg=0;
		for (auto [i,j]:tmp) if (!b[j]) pos++; else neg++;
		if (pos>=1) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (!b[j]) b[j]^=1,tt++;
				if (tt==1) break;
			}
			chkmax(ans,check());
		} 
		if (pos>=4) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (!b[j]) b[j]^=1,tt++;
				if (tt==4) break;
			}
			chkmax(ans,check());
		} 
		if (neg>=2) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (b[j]) b[j]^=1,tt++;
				if (tt==2) break;
			}
			chkmax(ans,check());
		} 
		if (neg>=5) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (b[j]) b[j]^=1,tt++;
				if (tt==5) break;
			}
			chkmax(ans,check());
		} 
	} else if ((cnt+n)%3==1) {
		chkmax(ans,check());
		int pos=0,neg=0;
		for (auto [i,j]:tmp) if (!b[j]) pos++; else neg++;
		if (pos>=3) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (!b[j]) b[j]^=1,tt++;
				if (tt==3) break;
			}
			chkmax(ans,check());
		} 
		if (neg>=3) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (b[j]) b[j]^=1,tt++;
				if (tt==3) break;
			}
			chkmax(ans,check());
		} 
	} else {
		int pos=0,neg=0;
		for (auto [i,j]:tmp) if (!b[j]) pos++; else neg++;
		if (pos>=2) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (!b[j]) b[j]^=1,tt++;
				if (tt==2) break;
			}
			chkmax(ans,check());
		} 
		if (pos>=5) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (!b[j]) b[j]^=1,tt++;
				if (tt==5) break;
			}
			chkmax(ans,check());
		} 
		if (neg>=1) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (b[j]) b[j]^=1,tt++;
				if (tt==1) break;
			}
			chkmax(ans,check());
		} 
		if (neg>=4) {
			int tt=0;
			for (auto [i,j]:tmp) {
				if (b[j]) b[j]^=1,tt++;
				if (tt==4) break;
			}
			chkmax(ans,check());
		} 
	}
	cout<<ans<<endl;
	
	return 0;
}
