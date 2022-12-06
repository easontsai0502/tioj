/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
[AC]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

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
#define FIR first
#define SEC second
#define DBG if(debug)
#define ifif if
#define elif else if
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
const INT mxn=500000;
INT n,m;
INT dsu[(mxn+2)*3];
/*fn定義*/
void dsu_clear(INT n){
	for(INT i=0;i<n*3+1;i++){
		dsu[i]=i;
	}
}
INT dsu_find(INT a){
	if(dsu[a]==a)return a;
	else return dsu[a]=dsu_find(dsu[a]);
}
void dsu_push(INT a,INT b){
	dsu[dsu_find(a)]=dsu_find(b);
}
bool tm(INT a,INT b){
	/*ifif(dsu_find(a)==dsu_find(b)){//如果他們本來就在同一個team裡
		return true;
	}*/
	ifif(dsu_find(a+n)==dsu_find(b)){//如果a吃b(或b的同胞)
		return false;
	}
	elif(dsu_find(b+n)==dsu_find(a)){//如果b吃a(或a的同胞)
		return false;
	}
	else{
		dsu_push(a,b);//a和b是同類
		dsu_push(a+n,b+n);//a吃的東西和b是同樣的
		dsu_push(a+n+n,b+n+n);//吃a的東西和吃b的東西是一樣的
		return true;
	}
}
bool emp(INT a,INT b){
	ifif(dsu_find(a)==dsu_find(b)){//如果a和b是同類
		return false;
	}
	/*elif(dsu_find(a+n)==dsu_find(b)){//如果a吃b
		return true;
	}*/
	elif(dsu_find(b+n)==dsu_find(a)){//如果b吃a
		return false;
	}else{
		dsu_push(a+n,b);//a吃的東西和b是同類
		dsu_push(b+n+n,a);//吃b的東西就是a
		dsu_push(b+n,a+n+n);//b吃的東西就是吃a的東西
		return true;
	}
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	cin>>n>>m;
	/*solve*/
	dsu_clear(n);
	INT ans=0;
	while(m--){
		INT d,x,y;
		cin>>d>>x>>y;
		if(x>n||y>n){
			ans++;
			continue;
		}
		if(d==1){
			ans+=tm(x,y)?0:1;
		}
		if(d==2){
			ans+=emp(x,y)?0:1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
dsu中
dsu(1~n)指向同類
dsu(n+1~2n)指向食物
dsu(2n+1~3n)指向天敵
*/
