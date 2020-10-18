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

int a[301],f[301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for (int i=2;i<=n;i++) for (int j=1;j<=n-i+1;j++) {
		f[j][j+i-1]=1e9;
		for (int k=j;k<=j+i-2;k++) chkmin(f[j][j+i-1],f[j][k]+f[k+1][j+i-1]);
		f[j][j+i-1]+=a[j+i-1]-a[j-1];
	}
	cout<<f[1][n]<<endl;
	
	return 0;
}
