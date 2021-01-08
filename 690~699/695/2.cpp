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

const int N=3e5+1;
int n,a[N];

bool shi(int x) {
	if (x>1 and x<n) if (a[x]>a[x-1] and a[x]>a[x+1] or a[x]<a[x-1] and a[x]<a[x+1]) return 1;
	return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for (int i=1;i<=n;i++) ans+=shi(i);
		int mi=ans;
		for (int i=1;i<=n;i++) {
			int cur=ans-shi(i),tmp=a[i];
			if (i>1) {
				if (shi(i-1)) cur--;
				if (i<n and shi(i+1)) cur--;
				a[i]=a[i-1];
				if (shi(i)) cur++;
				if (shi(i-1)) cur++;
				if (i<n and shi(i+1)) cur++;
				chkmin(mi,cur);
				a[i]=tmp;
				cur=ans-shi(i);
			}
			if (i<n) {
				if (i>1 and shi(i-1)) cur--;
				if (shi(i+1)) cur--;
				a[i]=a[i+1];
				if (shi(i)) cur++;
				if (i>1 and shi(i-1)) cur++;
				if (shi(i+1)) cur++;
				chkmin(mi,cur);
				a[i]=tmp;
			}
		}
		cout<<mi<<endl;
	}
	
	return 0;
}
