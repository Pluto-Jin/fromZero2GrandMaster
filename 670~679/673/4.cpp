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
		int sum=0;
		vi ar(n+1),ans;
		for (int i=1;i<=n;i++) cin>>ar[i],sum+=ar[i];
		if (sum%n) {cout<<-1<<endl;continue;}
		sum/=n;
		for (int i=2;i<=n;i++) {
			int x=i-ar[i]%i;
			if (x!=i) ar[1]-=x,ar[i]+=x,ans.pb(1),ans.pb(i),ans.pb(x);
			ans.pb(i),ans.pb(1),ans.pb(ar[i]/i);
			ar[1]+=ar[i],ar[i]-=ar[i];
		}
		for (int i=2;i<=n;i++) if (ar[i]<sum) {
			int x=sum-ar[i];
			ans.pb(1),ans.pb(i),ans.pb(x);
		}
		cout<<ans.size()/3<<endl;
		for (int i=0;i<ans.size();i++) {
			cout<<ans[i]<<' ';
			if (i%3==2) cout<<endl;
		}
		continue;
gg:		cout<<-1<<endl;
	}
	
	return 0;
}
