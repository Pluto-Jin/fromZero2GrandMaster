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

const int N=1e5+1;
int n,g[6],a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=0;i<6;i++) cin>>g[i];
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(g,g+6);
	sort(a,a+n);
	int ans=2e9;
	for (int i=0;i<n;i++) for (int j=0;j<6;j++) if (a[0]-g[0]>=a[i]-g[j]) {
		int cur=0;
		for (int k=1;k<6;k++) {
			int p=lower_bound(a,a+n,a[i]-g[j]+g[k])-a;
			if (p) chkmax(cur,a[p-1]-g[k-1]-(a[i]-g[j])); 
		}
		chkmax(cur,a[n-1]-g[5]-(a[i]-g[j]));
		chkmin(ans,cur);
	}
	cout<<ans<<endl;
	
	return 0;
}
