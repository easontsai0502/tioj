/*
[Q]https://tioj.ck.tp.edu.tw/problems/1211
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
INT n,m;
INT boss[10001];
/*fn定義*/
INT findboss(INT a){
	if(boss[a]==a)return a;
	else return findboss(boss[a]);
}
void bosspush(INT a,INT b){
	boss[findboss(a)]=findboss(b);
}
bool waslink(INT a,INT b){
	return findboss(a)==findboss(b);
}
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	while(cin>>n>>m){
		if(!n || !m)break;
		/*cin*/
		map<INT,vector<PII>> link;
		INT maxad=0;
		for(INT i=0;i<m;i++){
			INT a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			link[c].push_back({a,b});
			maxad=max(maxad,c);
		}
		/*solve*/
		for(INT i=0;i<=10000;i++){
			boss[i]=i;
		}
		bool wassolve=false;
		INT ad=1;
		INT ans=0;
		while(!wassolve){
			for(auto i:link[ad]){
				INT &a=i.first;
				INT &b=i.second;
				INT aboss=findboss(a);
				INT bboss=findboss(b);
				if(aboss!=bboss){
					bosspush(aboss,bboss);
					ans+=ad;
					if(debug)cout<<a<<","<<b<<","<<ad<<"\n";
				}
			}
			
			
			//檢查我是否需要繼續做
			wassolve=true;
			for(INT i=0;i<n-1&&wassolve;i++){
				wassolve=findboss(i)==findboss(i+1);
				if(!wassolve)break;
			}
			if(wassolve||ad==maxad)break;
			ad++;
		}
		if(wassolve){cout<<ans<<"\n";}
		else{cout<<"-1\n";}
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
