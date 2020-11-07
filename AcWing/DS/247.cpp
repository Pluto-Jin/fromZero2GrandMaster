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

#define mid (l+r>>1)
#define lch (x<<1)
#define rch (x<<1|1)

const int N=1e4+1;
int n,tot;
double a[N<<1];
int find(double tmp) {return lower_bound(a,a+tot,tmp)-a;}

struct bian{
	double x1,x2,y;
	bool t;
	bool operator<(const bian &b) {
		return y<b.y;
	}
} line[N<<1];

struct node{
	double len;
	int tg,lo,hi;
} t[N<<3];

void build(int x=1,int l=1,int r=tot-1) {
	t[x]={0,0,l-1,r};
	if (l<r) build(lch,l,mid),build(rch,mid+1,r);
}

void up(int x) {
	if (t[x].tg>0) t[x].len=a[t[x].hi]-a[t[x].lo];
	else if (t[x].lo+1==t[x].hi) t[x].len=0;
	else t[x].len=t[lch].len+t[rch].len;
}

void update(int L,int R,int v,int x=1,int l=1,int r=tot-1) {
	if (L<=l and r<=R) t[x].tg+=v;
	else {
		if (mid>=L) update(L,R,v,lch,l,mid);
		if (mid+1<=R) update(L,R,v,rch,mid+1,r);
	}
	up(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int tc=0;
	while (1) {
		int n; cin>>n;
		if (!n) break;
		for (int i=0;i<n;i++) {
			double x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
			a[i]=x1,a[i+n]=x2;
			line[i]={x1,x2,y1,1},line[i+n]={x1,x2,y2,0};
		}
		sort(a,a+2*n);
		sort(line,line+2*n);
		tot=unique(a,a+2*n)-a;

		build();

		double ans=0;
		for (int i=0;i<2*n;i++) {
			ans+=(line[i].y-line[i-1].y)*t[1].len;
			auto [x1,x2,y,t]=line[i];
			update(find(x1)+1,find(x2),t?1:-1);
		}
		cout<<"Test case #"<<++tc<<endl;
		cout<<"Total explored area: "<<fixed<<setprecision(2)<<ans<<endl<<endl;
	}
	
	return 0;
}
