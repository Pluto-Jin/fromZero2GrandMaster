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

const int N=1001,MOD=1e9+7;
int n,m,fen[N][N],a[N],lsh[N],tot;
int id(int x) {return lower_bound(lsh+1,lsh+tot+1,x)-lsh;}
void update(int len,int x,int v) {for(;x<=tot;x+=x&-x)fen[len][x]+=v,fen[len][x]%=MOD;}
int query(int len,int x) {int res=0;for(;x;x-=x&-x)res+=fen[len][x],res%=MOD;return res;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	for (int tc=1;tc<=t;tc++) {
		int n,m; cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i],lsh[i]=a[i];
		sort(lsh+1,lsh+n+1);
		tot=unique(lsh+1,lsh+n+1)-lsh-1;
		for (int i=1;i<=m;i++) for (int j=1;j<=tot;j++) fen[i][j]=0;
		for (int i=1;i<=n;i++) {
			int j=id(a[i]); update(1,j,1);
			for (int len=2;len<=min(i,m);len++) update(len,j,query(len-1,j-1));
		}
		int ans=0;
		for (int i=1;i<=tot;i++) ans+=(MOD+query(m,i)-query(m,i-1))%MOD,ans%=MOD;
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	
	return 0;
}
