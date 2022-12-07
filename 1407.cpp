/*
[DP]
此程式表示當有多個同樣物品時的01背包問題
[Q]https://cses.fi/problemset/task/1407/
[WA MLE]
*/

/*include*/
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
#include<stack>
#include<cstring>
#include<unordered_map>

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/

/*fn定義*/
INT TFbackpack(INT n,INT m,bool debug=false){//經典01背包問題(物品數,承受重量)
	INT h[n+1],s[n+1],k[n+1];
	//h為物品重
	//s為價值
	//k為此物品的數量(可以都拿，也可以只拿部分，也可以都不拿)
	/*cin*/
	for(INT i=1;i<=n;i++){
		cin>>h[i];
		cin>>s[i];
		cin>>k[i];
	}
	cin>>m;
	/*solve*/
	/*濃縮物品*/
	/*原本n個a，現在要濃縮成log2(n)個物品*/
	vector<PII> item;//{重,價值}
	item.push_back({0,0});
	for(INT i=1;i<=n;i++){
		INT nowall=0;			//計算現在數量total
		for(INT j=1;nowall+j<=k[i];j*=2){//注意，j是以2的羃次去跑(j=1,2,4,8,16...)
			//為何是比較nowall+j
			//因為接下來要增加[j]
			//增加完[j]之後，我們的總數量就會是[j+nowall]
			//我們要在總數量>k[i]之前停掉
			//希望你看得懂
			if(h[i]*j>m)break;//超重就滾
			nowall+=j;//將準備要入伍的各數計算進去
			item.push_back({h[i]*j,s[i]*j});//入伍
		}
		if(nowall>=k[i])continue;//如果現在的數量已經滿足k[i]就換下一組
		nowall=k[i]-nowall;//計算還沒入伍的
		if(nowall*h[i]<=m)item.push_back({h[i]*nowall,s[i]*nowall});//可以入伍的話就入伍
		{/*
		架構說明
		如果直接用3個for迴圈去跑，只能拿50%
		程式在下面，被註解掉了，自己試試看就知道了
		(dp初始化不小心刪掉了，想嘗試的自己加回去)
		這邊把東西分組
		假設a項目有20個，我們把它拆成下面這樣
		[1個a]
		[2個a]
		[4個a]
		[8個a]
		這邊total會有15個a
		最後再把剩下的20-15=5個a打包
		[5個a]
		把這些group當成一個物品去跑就可以了
		原本要跑20次的東西，現在只需要跑5次
		*/}
	}
	/*dp初始化*/
	INT is=item.size()-1;
	INT dp[is+1][m+1];
	for(INT i=0;i<=is;i++){
		dp[i][0]=0;
	}
	for(INT i=0;i<=m;i++){
		dp[0][i]=0;
	}
	/*開始dp*/
	for(INT i=1;i<=is;i++){//i為物品編號
		INT &hh=item[i].first;
		INT &ss=item[i].second;
		for(INT j=0;j<=m;j++){//j為承受重量
			INT &nowans=dp[i][j];
			nowans=dp[i-1][j];
			if(j-hh>=0) nowans=max(dp[i-1][j],dp[i-1][j-hh]+ss);
			if(debug)cout<<nowans<<",";
		}
		if(debug)cout<<"\n";
	}
	return dp[is][m];
}
INT baddp(INT n,INT m){//不要看、不要學、錯誤示範
	//經典01背包問題(物品數,承受重量)
	INT h[n+1],s[n+1],k[n+1];
	//h為物品重
	//s為價值
	//k為此物品的數量(可以都拿，也可以只拿部分，也可以都不拿)
	/*cin*/
	for(INT i=1;i<=n;i++){
		cin>>h[i];
	}
	for(INT i=1;i<=n;i++){
		cin>>s[i];
	}
	for(INT i=1;i<=n;i++){
		cin>>k[i];
	}
	/*solve*/
	INT dp[n+1][m+1];//dp[i][j] i為物品編號 j為承受重量
	for(INT i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(INT i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(INT i=1;i<=n;i++){//i為物品編號
		for(INT j=h[i];j<=m;j++){//j為承受重量
			INT &nowans=dp[i][j];
			nowans=dp[i-1][j];
			for(INT c=1;c<=k[i] && h[i]*c<=j;c++){//c為物品數
				nowans=max(dp[i-1][j-c*h[i]]+s[i]*c,nowans);
			}
		}
	}
	return dp[n][m];
}



/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	INT a;
	cin>>a;//>>b;
	cout<<TFbackpack(a,0,false)<<"\n";
	return 0;
}

/*
[I1]
3 10
2 6 3
8 5 4
3 5 2
[O1]
28
*/

/*think*/
/*

*/