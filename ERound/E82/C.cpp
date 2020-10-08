#include "bits/stdc++.h"
using namespace std;

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int ar[26]={0};
		deque<char> deq;
		string s;
		cin>>s;
		int pos=-1;
		int flag=0;
		for (auto i:s) {
			if (deq.size()==0 or deq.size()==1) {
				deq.push_back(i);	
				ar[i-'a']=1;
				pos++;
			}
			else {
				if (pos<deq.size()-1 and deq[pos+1]==i) {pos++;continue;}
				if (pos>0 and deq[pos-1]==i) {pos--;continue;}
				if (pos==0) {
					deq.push_front(i);
					if (ar[i-'a']) {flag=1;break;}
					else ar[i-'a']=1;
				}
				else if (pos==deq.size()-1){
					deq.push_back(i);
					pos++;
					if (ar[i-'a']) {flag=1;break;}
					else ar[i-'a']=1;
				}
				else {flag=1;break;}
			}
		}
		if (flag) {cout<<"NO"<<endl;continue;}
		for (int i=0;i<26;i++) if (!ar[i]) deq.push_back('a'+i);
		cout<<"YES"<<endl;
		for (auto i:deq) cout<<i;
		cout<<endl;
	}
}
