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

const int N=1e5+1;
ll m,a[N],l[N],dp[N],f[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	int ok=1;
	for (ll i=1,p=1,cur=0;ok and i<=n;i++) {
		cur+=a[i];
		while (p<=i and cur>m) cur-=a[p++];
		if (p>i) ok=0;
		else l[i]=p;	
	}
	if (!ok) cout<<-1<<endl;
	else {
		multiset<ll> s; s.insert((int)1e18);
		deque<int> q;
		for (int i=1;i<=n;i++) {
			while (q.size() and a[q.back()]<=a[i]) {
				int tmp=q.back(); q.ppb();
				if (q.size()) s.erase(s.find(f[q.back()]));
			}
			if (q.size()) s.insert(f[q.back()]=dp[q.back()]+a[i]);
			q.pb(i);
			while (q.size() and q.front()<l[i]) {
				s.erase(s.find(f[q.front()]));
				q.ppf();
			}
			dp[i]=min(dp[l[i]-1]+a[q.front()],*s.begin());
		}		
		cout<<dp[n]<<endl;
	}
	
	return 0;
}
