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
		string s; cin>>s;
		vi a;
		for (int i=0;i<n;i++) {
			int cnt=1;
			while (i<n-1 and s[i+1]==s[i]) cnt++,i++;
			a.pb(cnt);
		}
		int fg=0,cnt=0,ans=0;
		for (auto i:a) {
			if (i!=1) {
				if (!fg) ans++;
				else if (cnt>=i-1) ans+=i-1,cnt-=i-1-1;
				else ans+=cnt+1,cnt=0;
			} else fg=1,cnt++;
		}
		ans+=cnt+1>>1;
		cout<<ans<<endl;
	}
	
	return 0;
}
