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

const int N=2e5+1;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		vi tmp;
		for (int i=1;i<=n;i++) {
			int cnt=1;
			while (i<n and a[i+1]>a[i]) i++,cnt++;
			tmp.pb(cnt);
		}
		tmp[0]--;
		int ans=1,cur=tmp[0];
		for (int i=1;i<tmp.size();) {
			int tt=0;
			for (int j=0;j<cur and i<tmp.size();j++) tt+=tmp[i],i++;
			ans++,cur=tt;	
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
