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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		vi row(n),col(m);
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				int x; cin>>x;
				if (x) row[i]=1,col[j]=1;
			}
		}
		int cnt=0,cnt1=0;
		for (auto i:row) if (!i) cnt++;
		for (auto i:col) if (!i) cnt1++;
		cnt=min(cnt,cnt1);
		cout<<(cnt%2?"Ashish":"Vivek")<<endl;
	}
}

