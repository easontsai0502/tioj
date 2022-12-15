/*
[Q]
[]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
/*struct宣告*/
struct mat;
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;

const INT mxn=1e5;
INT n,m;
vector<PII> tree[mxn+1];
INT inin[mxn+1];
INT dang[mxn+1];
deque<INT> dq;
/*struct定義*/
struct mat{
	INT a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat re;
		for(INT i=0;i<2;i++){
			for(INT j=0;j<2;j++){
				for(INT k=0;k<2;k++){
					re.a[i][j]=(re.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return re;
	}
};
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	//memset(dang,1e9,sizeof(dang));
	dang[1]=0;
	/*CIN*/
	cin>>n>>m;
	while(m--){
		INT u,v,w;
		cin>>u>>v>>w;
		tree[u].push_back({v,w});
		inin[v]++;
	}
	/*solve*/
	for(INT i=0;i<=n;i++){
		dang[i]=1e11;
	}
	dang[1]=0;
	DBG{
		for(INT i=0;i<=n;i++){
			cerr<<dang[i]<<" ";
		}
		cerr<<endl;
	}
	dq.push_back(1);
	INT ans=0;
	while(dq.wassomething()){
		INT nw=dq.front();
		dq.pop_front();
		ans+=dang[nw];
		for(PII i:tree[nw]){
			dang[i.FIR]=min(dang[i.FIR],dang[nw]+i.SEC);
			DBG cerr<<i.FIR<<" "<<dang[i.FIR]<<endl;
			inin[i.FIR]--;
			if(inin[i.FIR]<=0)dq.push_back(i.FIR);
		}
	}
	cout<<ans<<endl;
	DBG{
		for(INT i=0;i<=n;i++){
			cerr<<dang[i]<<" ";
		}
		cerr<<endl;
	}
	return 0;
}

/*
[I1]
4 4 1 2 10 2 4 50 1 3 30 3 4 20
[O1]
90
*/

/*think*/
/*

*/