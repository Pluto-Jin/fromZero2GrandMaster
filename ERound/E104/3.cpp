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

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi a(n+1),b(n+1);
		if (n%2) {
			int w=n-1>>1;
			for (int i=1;i<=n;i++) {
				for (int j=i+1;j<=n;j++) {
					if (a[i]<w) cout<<1<<' ',a[i]++;
					else cout<<-1<<' ',a[j]++;
				}	
			}
		} else {
			int w=n-1>>1;
			for (int i=1;i<=n;i++) {
				int fg=0;
				for (int j=i+1;j<=n;j++) {
					if (a[i]<w) cout<<1<<' ',a[i]++;
					else if (!fg) cout<<0<<' ',fg=1;
					else cout<<-1<<' ',a[j]++;
				}	
			}
		} 
		cout<<endl;
	}
	
	return 0;
}
