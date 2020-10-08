#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m,k; cin>>n>>m>>k;
	for (int i=0;i<2*k;i++) {
		int x,y;
		cin>>x>>y;
	}
	cout<<2*m*n<<endl;
	int tmp=1;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m-1;j++) cout<<(tmp?'R':'L');
		cout<<'D';
		tmp=1-tmp;
	}
	tmp=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m-1;j++) cout<<(tmp?'R':'L');
		cout<<'U';
		tmp=1-tmp;
	}
	cout<<endl;
}

