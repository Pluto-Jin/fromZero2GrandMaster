#include "bits/stdc++.h"
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

int n,k;
vi ar;
queue<int> q;

void query() {
	int x; cin>>x;
	vi tmp;
	for (int i=x;i<x+k;i++) if (ar[(i-1)%n]) tmp.pb((i-1)%n+1);
	if (tmp.size()+q.size()<k) cout<<0<<endl,cout<<flush;
	else {
		cout<<k<<' ';
		for (auto i:tmp) cout<<i<<' ';
		for (int i=0;i<k-tmp.size();i++) ar[q.front()-1]=1,cout<<q.front()<<' ',q.pop();
		cout<<endl; cout<<flush;
		query();
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n; ar.resize(n);
	if (n<4) {cout<<0<<endl;return 0;}
	int ma=-1;
	for (int i=1;i<=n;i++) if (n-ceil(1.0*n/i)-i>ma) ma=n-ceil(1.0*n/i)-i,k=i;
	for (int i=1;i<n;i++) if (i%k) q.push(i);

	cout<<k<<' ';
	for (int i=0;i<k;i++) ar[q.front()-1]=1,cout<<q.front()<<' ',q.pop(); 
	cout<<endl; cout<<flush;
	query();

	return 0;
}

