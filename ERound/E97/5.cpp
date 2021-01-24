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

const int N=5e5+1;
int a[N],b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i],a[i]-=i;
	for (int i=1;i<=m;i++) cin>>b[i];
	int ok=1,last=-1;
	vi g;
	for (int j=1,i=1;ok and i<=n;i++) {
		if (j<=m and i==b[j]) {
			j++;
			while (ok and g.size() and g.back()>a[i]) {
				if ((int)g.size()<=last) ok=0;
				g.ppb();
			}
			g.pb(a[i]); last=g.size();
		} else {
			if (g.empty() or a[i]>=g.back()) g.pb(a[i]);
			else {
				int p=upper_bound(g.begin(),g.end(),a[i])-g.begin();
				if (last-1<p) g[p]=a[i];
			}
		}
	}
	if (!ok) cout<<-1<<endl;
	else cout<<n-g.size()<<endl;
	
	return 0;
}
