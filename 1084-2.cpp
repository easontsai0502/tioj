/*
[Q]https://tioj.ck.tp.edu.tw/problems/1084
[AC]
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
#define ifif if
//#define CIN( nn ) DBG{cout<<"input:"<<endl;}cin >> nn ;
//#define COUT( nn ) DBG{cout<<"output:{";}cout << nn ; DBG{cout<<"}"<<endl;}
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
const INT mxn=500;
INT li[mxn+1];
multiset<INT> tree[mxn+1];
deque<INT> ans;
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
void ans_dbg(deque<INT> dq){
	DBG while(dq.wassomething()){
		cerr<<dq.front()<<" ";
		dq.pop_front();
	}
	cerr<<endl;
}
void INT_DFS(INT a){
	while(tree[a].wassomething()){
		INT nxt=*tree[a].begin();
		tree[a].erase(tree[a].find(nxt));
		tree[nxt].erase(tree[nxt].find(a));
		DBG cerr<<a<<"=>"<<nxt<<endl;
		DBG{
			cerr<<"now:";
			ans_dbg(ans);
		}
		INT_DFS(nxt);
	}
	ans.push_front(a);
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	INT m;
	while(cin>>m){
		if(m==0)return 0;
		/*re:0*/
		memset(li,0,sizeof(li));
		INT n=0;
		INT st=1;
		/*CIN*/
		while(m--){
			INT x,y;
			cin>>x>>y;
			n=max(n,max(x,y));
			li[x]++;
			li[y]++;
			tree[x].insert(y);
			tree[y].insert(x);
		}
		/*solve*/
		for(INT i=1;i<=n;i++){
			if(li[i]&1){
				st=i;
				break;
			}
		}
		INT_DFS(st);
		while(ans.wassomething()){
			cout<<ans.front()<<endl;
			ans.pop_front();
		}
		cout<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
假設有一張圖
據定理，我們必須從連線為奇數的點開始
每走一條路，我們就拆掉那條路
然後又產生出一張圖
一直遞迴下去
那你說這樣會出事嗎?會不會走出死路
答案是不會
下面講解
假設本來的位置是奇數
|走到偶數的
||原本的點變偶數，現在的點變奇數
||當作是新的圖，然後剛剛好在奇數點開始
|走到奇數的
||原本的點和現在的點都變偶數了
||當新的圖，然後整張圖的奇數點都被砍成偶數了，就放心繼續走吧
假設本來的位置是偶數
此情況只有當整張圖都沒有奇數的時候發生，那就放心走吧
證明我不想證了，看奇數的情況應該就能看懂了把
*/
