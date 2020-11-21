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

const int N=1001;
int n,h[N];
double d[N];
bool vis[N];
pii a[N];

double dist(int i,int j) {return sqrt((a[i].fi-a[j].fi)*(a[i].fi-a[j].fi)+(a[i].se-a[j].se)*(a[i].se-a[j].se));}

bool check(double mid) {
	double res=0;
	for (int i=1;i<=n;i++) d[i]=1e9,vis[i]=0;
	d[1]=0;
	while (1) {
		int id=-1;
		double mi=1e9;
		for (int i=1;i<=n;i++) if (!vis[i] and chkmin(mi,d[i])) id=i; 
		if (id==-1) break;
		vis[id]=1; res+=mi;
		for (int i=1;i<=n;i++) if (!vis[i]) chkmin(d[i],abs(h[i]-h[id])*1.0-mid*dist(i,id));
	}
	return res>0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (1) {
		cin>>n;
		if (!n) break;
		for (int i=1;i<=n;i++) {
			int x,y,w; cin>>x>>y>>w;
			a[i]=mp(x,y);
			h[i]=w;
		} 
		double lo=0,hi=1e7+1;
		while (hi-lo>1e-5) {
			double mid=lo+(hi-lo)/2;
			if (check(mid)) lo=mid;
			else hi=mid;
		} 
		cout<<fixed<<setprecision(3)<<hi<<endl;
	}
	
	return 0;
}
