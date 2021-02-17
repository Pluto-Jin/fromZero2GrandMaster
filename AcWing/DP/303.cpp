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
int n,m,p,d[N],q[N],head,tail;
ll dp[N],tmp[N],a[N],b[N],ab[N];
map<int,int> cnt;

ll cal(int i,int j) {return dp[j]+(b[i]-b[j])*a[i]-(ab[i]-ab[j]);}
ll up(int j,int k) {return dp[j]+ab[j]-dp[k]-ab[k];}
ll down(int j,int k) {return b[j]-b[k];}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>p;
	for (int i=2;i<=n;i++) cin>>d[i],d[i]+=d[i-1];
	while (m--) {
		int h,t; cin>>h>>t;
		cnt[t-d[h]]++;		
	}
	n=0;
	for (auto [i,j]:cnt) {
		a[++n]=i,b[n]=j;
		ab[n]=1ll*i*j;
	}
	for (int i=1;i<=n;i++) b[i]+=b[i-1],ab[i]+=ab[i-1];

	memset(dp,0x3f,sizeof dp); dp[0]=0;
	while (p--) {
		head=tail=0;
		q[tail++]=0;
		for (int i=1;i<=n;i++) {
			while (head+1<tail and up(q[head+1],q[head])<=a[i]*down(q[head+1],q[head]))
				head++;
			tmp[i]=cal(i,q[head]);
			while (head+1<tail and up(i,q[tail-1])*down(q[tail-1],q[tail-2])<=up(q[tail-1],q[tail-2])*down(i,q[tail-1]))
				tail--;
			q[tail++]=i;
		}
		for (int i=1;i<=n;i++) dp[i]=tmp[i];
	}
	cout<<dp[n]<<endl;
	
	return 0;
}
