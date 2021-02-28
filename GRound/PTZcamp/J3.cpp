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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
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

#include<complex>
typedef complex<double> C;
typedef vector<C> vc;
const double PI=acos(-1);
vi rev;

void fft(vc &a,int n,int f) {
	for (int i=0;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=1;i<n;i<<=1) {
		C wi(cos(PI/i),f*sin(PI/i));
		for (int j=0,p=i<<1;j<n;j+=p) {
			C w(1,0);
			for (int k=0;k<i;k++,w*=wi) {
				C t=w*a[j+k+i];
				a[j+k+i]=a[j+k]-t,a[j+k]+=t;
			}
		}
	}
}

template<class T,class T2>
vi conv(const T &aa,int nn,const T2 &bb,int mm) {
	int n=nn,m=mm,len=0; for (m+=n-1,n=1;n<=m;n<<=1) len++;
	for (int i=rev.size();i<n;i++) rev.pb(i?rev[i>>1]>>1|(i&1)<<len-1:0);

	vc a(n),b(n),c(n);
	for (int i=0;i<n;i++) a[i]=i<nn?aa[i]*aa[i]*aa[i]:0,b[i]=i<mm?bb[i]:0;
	fft(a,n,1); fft(b,n,1);
	for (int i=0;i<n;i++) c[i]=a[i]*b[i]; 

	for (int i=0;i<n;i++) a[i]=i<nn?aa[i]:0,b[i]=i<mm?bb[i]*bb[i]*bb[i]:0;
	fft(a,n,1); fft(b,n,1);
	for (int i=0;i<n;i++) c[i]+=a[i]*b[i]; 

	for (int i=0;i<n;i++) a[i]=i<nn?aa[i]*aa[i]:0,b[i]=i<mm?bb[i]*bb[i]:0;
	fft(a,n,1); fft(b,n,1);
	for (int i=0;i<n;i++) c[i]-=a[i]*b[i]*(C){2,0}; 

	fft(c,n,-1);
	vi res; for (int i=0;i<m;i++) res.pb((int)(c[i].real()/n+0.5));
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	vi a(n),b(m);
	map<int,int> v; v['n']=0,v['s']=1,v['e']=2,v['w']=3;
	for (int i=0;i<n;i++) {
		char c; cin>>c;
		if (c=='?') a[i]=0;
		else {
			int x; cin>>x;
			a[i]=x+7*v[c];
		}
	}
	for (int i=0;i<m;i++) {
		char c; cin>>c;
		if (c=='?') b[i]=0;
		else {
			int x; cin>>x;
			b[i]=x+7*v[c];
		}
	}
	reverse(b.begin(),b.end());
	vi res=conv(a,n,b,m);
	int ans=0;
	for (int i=m-1;i<n;i++) if (!res[i]) ans++;
	cout<<ans<<endl;
}
