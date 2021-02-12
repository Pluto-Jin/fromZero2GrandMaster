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

const int N=3e5+1;
ll n,s,t[N],c[N],dp[N],q[N],head,tail;

ll cal(int i,int j) {return dp[j]+t[i]*(c[i]-c[j])+s*(c[n]-c[j]);}
ll up(int j,int k) {return dp[j]-dp[k];}
ll down(int j,int k) {return c[j]-c[k];}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>t[i]>>c[i],t[i]+=t[i-1],c[i]+=c[i-1];
	q[tail++]=0;
	for (int i=1;i<=n;i++) {
		while (head+1<tail and up(q[head+1],q[head])<=down(q[head+1],q[head])*(t[i]+s))
			head++;
		dp[i]=cal(i,q[head]);
		while (head+1<tail and up(i,q[tail-1])*down(q[tail-1],q[tail-2])<=up(q[tail-1],q[tail-2])*down(i,q[tail-1]))
			tail--;
		q[tail++]=i;
	}
	cout<<dp[n]<<endl;
	
	return 0;
}
