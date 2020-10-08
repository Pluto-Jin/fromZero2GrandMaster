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

	int k; cin>>k;
	cout<<3<<' '<<3<<endl;
	cout<<((1<<18)-1)<<' '<<k<<' '<<0<<endl;
	cout<<(1<<17)<<' '<<k<<' '<<0<<endl;
	cout<<(1<<17)<<' '<<(k+(1<<17))<<' '<<k<<endl;
}

