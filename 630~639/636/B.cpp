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

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		if (n%4) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			vi ar(n/2);
			for (int i=0;i<n/2;i++) ar[i]=2*i+2;
			for (int i=0,j=1;i<n;i++) {
				if (i<n/2) cout<<ar[i]<<' ';
				else if (i<n/4*3) cout<<ar[i-n/2]-1<<' ';
				else cout<<ar[i-n/2]+1<<' ';
			}
			cout<<endl;
		}
	}
}

