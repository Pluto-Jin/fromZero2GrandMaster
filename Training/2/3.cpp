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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	vii ans;
	for (int i=1;i<=1+k;i++) for (int j=1;j<=k;j++) ans.eb(i,i+j);
	for (int i=2+k,t=k-1;i<=2*k;i++,t--) {
		for (int j=1;j<=t;j++) ans.eb(i,i+j);
		for (int j=t+1,tmp=1;j<=k;j++,tmp++) ans.eb(i,tmp);
	}
	for (int i=2*k+1;i<=n;i++) for (int j=1;j<=k;j++) ans.eb(i,j);
	int ok=1;
	for (auto [i,j]:ans) if (i>n or j>n) ok=0;
	if (ok) {
		cout<<ans.size()<<endl;
		for (auto [i,j]:ans) cout<<i<<' '<<j<<endl;
	} else cout<<-1<<endl;
	
	return 0;
}
