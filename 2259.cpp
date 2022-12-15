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
INT mod=1e9+7;
/*struct定義*/
struct mat{
	INT a[6][6];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat re;
		for(INT i=0;i<6;i++){
			for(INT j=0;j<6;j++){
				for(INT k=0;k<6;k++){
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
	/*CIN*/
	INT n;
	cin>>n;
	/*solve*/
	n--;
	mat bs;
	bs.a[0][3]=1;
	mat aa;

	aa.a[0][3]=1;

	aa.a[1][0]=1;
	aa.a[1][4]=1;
	
	aa.a[2][0]=1;
	aa.a[2][5]=1;
	
	aa.a[3][0]=1;
	aa.a[3][1]=1;
	aa.a[3][2]=1;
	aa.a[3][3]=1;

	aa.a[4][0]=1;
	aa.a[4][4]=1;
	
	aa.a[5][0]=1;
	aa.a[5][5]=1;
	while(n){
		if(n&1){
			bs=bs*aa;
		}
		aa=aa*aa;
		n>>=1;
	}
	cout<<bs.a[0][0]<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
dp[i][j]
j:
0 =|
1 =\
2 =/
3 |=
4 \=
5 /=
*/
