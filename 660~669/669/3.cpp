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
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int N=1e4+1;
int n,ans[N]; 

int query(int x,int y) {
	cout<<"? "<<x+1<<' '<<y+1<<endl<<flush;
	int res; cin>>res;
	return res;	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	int lo=0,hi=n-1;
	int sum=(1+n)*n/2;
	while (lo<hi) {
		int a=query(lo,hi),b=query(hi,lo);
		if (a>b) ans[lo++]=a;
		else ans[hi--]=b;
		sum-=max(a,b);
	}
	cout<<"! ";
	for (int i=0;i<n;i++) cout<<(ans[i]?ans[i]:sum)<<' ';
	cout<<endl<<flush;
}
