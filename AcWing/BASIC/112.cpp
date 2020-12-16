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
int x[N],y[N];
pair<double,int> a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,d,ok=1; cin>>n>>d;
	for (int i=1;i<=n;i++) {
		cin>>x[i]>>y[i];
		if (y[i]>d) ok=0;
		else a[i]=mp(sqrt(d*d-y[i]*y[i])+x[i],i);
	}
	if (!ok) cout<<-1<<endl;
	else {
		sort(a+1,a+n+1);
		int ans=0;
		for (int i=1;i<=n;i++) if (a[i].se) {
			auto [pos,id]=a[i]; ans++;
			for (int j=i+1;j<=n and a[j].fi-pos<=2*d;j++) if (a[j].se) {
				int xx=x[a[j].se],yy=y[a[j].se];
				if ((xx-pos)*(xx-pos)+yy*yy<=d*d) a[j].se=0;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
