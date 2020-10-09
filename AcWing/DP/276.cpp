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

int n,m,k,a[16][16],dp[16][226][16][16][2][2];
bool vis[16][226][16][16][2][2];
int sum(int k,int l,int r) {return a[k][r]-a[k][l-1];}
struct State {
	int k,cnt,l,r,x,y;
} from[16][226][16][16][2][2];

int solve(int k,int cnt,int l,int r,int x,int y) {
	bool &v=vis[k][cnt][l][r][x][y];
	int &d=dp[k][cnt][l][r][x][y],pre=cnt-r+l-1,cur=sum(k,l,r);
	auto &f=from[k][cnt][l][r][x][y];
	if (v) return d; v=1;
	if (cnt==r-l+1) return d=sum(k,l,r);
	if (k==1 or cnt<r-l+1 or !x and !y and cnt>k*(r-l+1)) return d=0;

	for (int i=l;i<=r;i++) for (int j=i;j<=r;j++) if (chkmax(d,cur+solve(k-1,pre,i,j,0,0))) f={k-1,pre,i,j,0,0};
	if (x) for (int i=1;i<=l;i++) for (int j=l;j<=r;j++) if (chkmax(d,cur+solve(k-1,pre,i,j,1,0))) f={k-1,pre,i,j,1,0};
	if (y) for (int i=l;i<=r;i++) for (int j=r;j<=m;j++) if (chkmax(d,cur+solve(k-1,pre,i,j,0,1))) f={k-1,pre,i,j,0,1};
	if (x and y) for (int i=1;i<=l;i++) for (int j=r;j<=m;j++) if (chkmax(d,cur+solve(k-1,pre,i,j,1,1))) f={k-1,pre,i,j,1,1};
	return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j],a[i][j]+=a[i][j-1];
	int ans=0,l,r,row;
	for (int t=1;t<=n;t++)
		for (int i=1;i<=m;i++) for (int j=i;j<=m;j++) if (chkmax(ans,solve(t,k,i,j,1,1))) row=t,l=i,r=j;
	cout<<ans<<endl;
	if (!ans) return 0;
	State cur={row,k,l,r,1,1};
	while (1) {
		for (int i=cur.l;i<=cur.r;i++) cout<<cur.k<<' '<<i<<endl;
		if (cur.r-cur.l+1==cur.cnt) break;
		cur=from[cur.k][cur.cnt][cur.l][cur.r][cur.x][cur.y];
	}
	
	return 0; //so troublesome, XieTuLe!!!!!
}
