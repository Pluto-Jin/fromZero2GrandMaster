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

const int N=1001;
int a[N<<1],cnt[1123456];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		for (int i=1;i<=n<<1;i++) cin>>a[i],cnt[a[i]]++;
		sort(a+1,a+n*2+1,greater<>());
		int ok=0;
		for (int i=2;!ok and i<=n<<1;i++) {
			vii ans; ans.eb(a[1],a[i]); cnt[a[1]]--,cnt[a[i]]--;
			int tar=a[1];
			for (int j=2;j<=n<<1;j++) if (cnt[a[j]]) {
				cnt[a[j]]--;
				if (cnt[tar-a[j]]) ans.eb(a[j],tar-a[j]);
				else break;
				cnt[tar-a[j]]--;
				tar=a[j];
			}
			if (ans.size()==n) {
				cout<<"YES"<<endl<<ans[0].fi+ans[0].se<<endl;
				for (auto [i,j]:ans) cout<<i<<' '<<j<<endl;
				ok=1;
			}
			for (int j=1;j<=n<<1;j++) cnt[a[j]]=0;
			for (int j=1;j<=n<<1;j++) cnt[a[j]]++;
		}
		if (!ok) cout<<"NO"<<endl;
		for (int j=1;j<=n<<1;j++) cnt[a[j]]=0;
	}
	
	return 0;
}
