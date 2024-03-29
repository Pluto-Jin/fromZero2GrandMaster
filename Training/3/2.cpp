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

const int N=300;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	string s; cin>>s;
	int cnt=0;
	for (int i=0;i<n;i++) {
		if (s[i]=='B') a[i+1]=1,cnt++;
	}
	if (cnt==n or !cnt) cout<<0<<endl;
	else if (cnt%2 and n%2==0) cout<<-1<<endl;
	else {
		if (cnt%2==0) for (int i=1;i<=n;i++) a[i]^=1;
		vi ans;
		for (int i=1;i<n;i++) {
			if (!a[i]) ans.pb(i),a[i+1]^=1;
		}
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i<<' '; cout<<endl;
	}
	
	return 0;
}
