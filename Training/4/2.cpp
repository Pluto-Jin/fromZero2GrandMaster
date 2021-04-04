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

	int n; cin>>n;
	vi a(n); 
	for (auto &i:a) cin>>i;
	int g=a[0];
	for (auto i:a) g=gcd(g,i);
	if (g!=1) {cout<<-1<<endl;return 0;}
	if (n==1) {cout<<0<<endl;return 0;}

	int cnt=0;
	for (auto i:a) if (i==1) cnt++;
	int ok=0;
	for (int i=0;i<n-1;i++) if (gcd(a[i+1],a[i])==1) ok=1;
	if (ok) cout<<n-cnt<<endl;
	else {
		int ans=10000;
		for (int i=0;i<n;i++) for (int j=i,tmp=0;j<n;j++)
			if ((tmp=gcd(tmp,a[j]))==1) {chkmin(ans,n+j-i-1);break;}
		cout<<ans<<endl;

	}


	
	return 0;
}
