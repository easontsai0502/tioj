/*
[tioj]	[Q]https://tioj.ck.tp.edu.tw/problems/2252
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[give up]
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

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
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
struct G_pnt{
	double x=0;
	double y=0;
};
struct G_line{
	double x=0;
	double y=0;
	double tt=0;
	G_line make(G_pnt a,G_pnt b){//獲取過兩點的函數
		G_line re;
		//計算斜率
		re.x=a.y-b.y;
		re.y=a.x-b.x;
		re.y=-re.y;
		//優化斜率
		INT g=__gcd(abs(re.x),abs(re.y));
		re.x/=g;
		re.y/=g;
		//計算tt
		re.tt=re.x*a.x+re.y*a.y;
		*this=re;
		return re;
	}
	G_line vertical(G_line a,G_pnt b){//獲取垂直線
		G_line re;
		//計算斜率
		re.x=a.y;
		re.y=-a.x;
		//優化斜率
		INT g=__gcd(abs(re.x),abs(re.y));
		re.x/=g;
		re.y/=g;
		//計算tt
		re.tt=re.x*b.x+re.y*b.y;
		*this=re;
		return re;
	}
};
G_pnt focus(G_line a,G_line b){//獲取焦點
	INT aa,bb,cc,dd,ee,ff;
	aa=a.x;
	bb=a.y;
	cc=a.tt;
	dd=b.x;
	ee=b.y;
	ff=b.tt;
	G_pnt re;
	re.x=(ee*cc-bb*ff)/(ee*aa-bb*dd);
	re.y=(dd*cc-aa*ff)/(dd*bb-aa*ee);
	return re;
}
double get_len(G_pnt a,G_pnt b){
	INT x=(a.x-b.x);
	INT y=(a.y-b.y);
	return sqrt(x*x+y*y);
}
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
INT INT_IN(){
	INT a;
	cin>>a;
	return a;
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
