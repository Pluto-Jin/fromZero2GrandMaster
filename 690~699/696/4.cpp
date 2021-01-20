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

const int N=2e5+1;
ll a[N],d[N],mi[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,ok=1; cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i],d[i]=a[i]-d[i-1];
			if (d[i]<0) ok=0;
		}
		mi[n]=d[n],mi[n-1]=d[n-1];
		if (d[n]) ok=0;
		for (int i=n-2;i;i--) mi[i]=min(d[i],mi[i+2]);
		for (int i=1;!ok and d[i-1]>=0 and i<n;i++) {
			if (a[i+1]-d[i-1]<0 or a[i]-a[i+1]+d[i-1]<0) continue;	
			if (i+2<=n and mi[i+2]<a[i]*2-a[i+1]*2) continue;
			if (i+3<=n and mi[i+3]<a[i+1]*2-a[i]*2) continue;
			if (n%2==i%2 and d[n]!=a[i]*2-a[i+1]*2) continue;
			if (n%2!=i%2 and d[n]!=a[i+1]*2-a[i]*2) continue;
			ok=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	
	return 0;
}
