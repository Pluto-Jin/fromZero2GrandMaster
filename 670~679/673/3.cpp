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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi ar(n+1),mi(n+1,-1e9),pos(n+1),ans(n+1,1e9);
		for (int i=1;i<=n;i++) {
			cin>>ar[i];
			mi[ar[i]]=max(mi[ar[i]],i-pos[ar[i]]);
			pos[ar[i]]=i;
		}
		for (int i=1;i<=n;i++) if (pos[ar[i]]) mi[ar[i]]=max(mi[ar[i]],n+1-pos[ar[i]]);
		for (int i=1;i<=n;i++) if (mi[i]>-1e9) chkmin(ans[mi[i]],i);
		for (int i=1;i<=n;i++) {
			ans[i]=min(ans[i],ans[i-1]);
			if (ans[i]==1e9) cout<<-1<<' ';
			else cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
