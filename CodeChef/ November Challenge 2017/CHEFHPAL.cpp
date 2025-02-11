//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int T,N,A;
vector<char> alpha(30);
char ch='a';

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	fl(i,0,26)	alpha[i] = ch++;

	string ab = "bbbabaa";
	fl(i,0,26666)	ab+="bbabaa";

	cin>>T;
	while(T--){
		cin>>N>>A;
		if(A==1){
			cout<<N<<" ";
			fl(i,0,N)	cout<<"a";
		}
		else if(A>=3){
			cout<<"1 ";
			fl(i,0,N)	cout<<alpha[i%A];
		}
		else{
			if(N==1)	cout<<"1 a";
			else if(N==2)	cout<<"1 ab";
			else if(N==3)	cout<<"2 aab";
			else if(N==4)	cout<<"2 aabb";
			else if(N==5)	cout<<"3 bbbab";
			else if(N==6)	cout<<"3 bbabaa";
			else if(N==7)	cout<<"3 bbbabaa";
			else if(N==8)	cout<<"3 bbbabaaa";
			else{
				cout<<"4 ";
				fl(i,0,N)	cout<<ab[i];
			}
		}
		cout<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}