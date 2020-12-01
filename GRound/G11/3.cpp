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
int n,q,t[N],x[N],y[N],cnt[N],ma[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>q;
	for (int i=1;i<=q;i++) cin>>t[i]>>x[i]>>y[i];
	x[0]=y[0]=1;
	int ans=0;
	set<pii> s;
	s.insert(mp(0,0));
	for (int i=1;i<=q;i++) {
		if (t[i]>=x[i]-1+y[i]-1) for (auto it=s.rbegin();it!=s.rend();it++) {
			auto [c,j]=*it;
			if (t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])) {
				chkmax(cnt[i],cnt[j]+1);
				break;
			}
		}
		chkmax(ans,cnt[i]);
		s.insert(mp(cnt[i],i));
	}
	cout<<ans<<endl;
	
	return 0;
}
