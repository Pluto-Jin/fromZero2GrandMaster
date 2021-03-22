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

const int N=101;
int f[N][N],a[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) for (int j=0;j<=m;j++) f[i][j]=1<<31;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		int x; cin>>x; a[i][j]=x;
		if (j>=i) chkmax(f[i][j],max(f[i][j-1],f[i-1][j-1]+x));
	}
	int ans=f[n][m];
	cout<<ans<<endl;
	int tmp[101];
	for (int i=n;i;i--) for (int j=1;j<=m;j++) if (f[i][j]==ans) {
		tmp[i]=j;
		ans-=a[i][j];
		break;
	}
	for (int i=1;i<=n;i++) cout<<tmp[i]<<' '; cout<<endl;
	
	return 0;
}
