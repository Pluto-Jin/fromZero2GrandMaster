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
		int n,k; cin>>n>>k;
		string s; cin>>s;
		int ed=0,fg=0,bg=0,ans=0;
		vi a;
		for (auto i:s) {
			if (i=='W') {
				ans+=2-!!ed;
				if (!fg) bg=ed,fg=1;
				else if (ed) a.pb(ed);
				ed=0;
			} else ed++;
		}
		ans-=s[0]=='W';
		sort(a.begin(),a.end());
		for (auto i:a) {
			if (k<i) ed+=i;
			else ans+=2*i+1,k-=i;
		}
		if (!fg) ans=2*min(k,n)-1;
		else if (k>0) {
			if (ed) ans+=2*min(k,ed),k-=min(k,ed);
			if (bg) ans+=2*min(k,bg);
		} 
		cout<<max(0,ans)<<endl;
	}
	
	return 0;
}
