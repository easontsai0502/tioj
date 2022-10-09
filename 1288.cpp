/*
[Q]
[]
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
	INT dp[101][101];

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	INT n;
	cin>>n;
	vector<INT> tri[n+1];
	for(INT i=1;i<=n;i++){
		tri[i].push_back(0);
		for(INT j=0;j<i;j++){
			INT inin;
			cin>>inin;
			tri[i].push_back(inin);
		}
	}
	/*solve*/
	for(INT i=1;i<=n;i++){
		for(INT j=1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+tri[i][j];
		}
	}
	INT ans=0;
	for(INT i=1;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<"\n";
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
