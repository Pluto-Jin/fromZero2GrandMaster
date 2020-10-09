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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int id,n; cin>>id>>n;
		cout<<id<<' '<<(n+1)/2<<endl;
		priority_queue<int,vi,less<>> pq1;
		priority_queue<int,vi,greater<>> pq2;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (i%2) {
				if (pq1.size() and pq1.top()>x) pq1.push(x),x=pq1.top(),pq1.pop();
				pq2.push(x);
			} else {
				if (pq2.size() and pq2.top()<x) pq2.push(x),x=pq2.top(),pq2.pop();
				pq1.push(x);
				if (i and i%20==0) cout<<endl;
				cout<<pq1.top()<<' ';
			}
		}
		cout<<endl;
	}
}
