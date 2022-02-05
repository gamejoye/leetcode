//1014.最佳观光组合(中等)(动态规划)
int maxScoreSightseeingPair(int* values, int valuesSize){
int i,max=values[0],dp;
dp=max;
for(i=1;i<valuesSize;i++)
{
    dp=fmax(dp,max+values[i]-i);
    max=fmax(max,values[i]+i);
}
return dp;
}

//122.股票
(动态规划)
int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    //dp[i][0]代表手里没有股票
    //dp[i][1]代表手里有股票
    for (int i = 1; i < pricesSize; ++i) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);//手里没有股票可能因为前一天没有股票或者在今天卖出
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);//手里有股票可能因为前一天又股票或者在今天买入
    }
    return dp[pricesSize - 1][0];
}
(贪心)
int maxProfit(int* prices, int pricesSize){
int i,j,sum=0,min=prices[0],dp;
for(i=1;i<pricesSize;i++)
{
    if(prices[i]<=min)
    {
        min=prices[i];
        continue;
    }
    if(prices[i]>min&&(i+1==pricesSize||prices[i+1]<prices[i]))
    {
        sum=sum+prices[i]-min;
        if(i+1<pricesSize)
        min=prices[i+1];
        continue;
    }
    if(prices[i]>min&&(i+1<pricesSize&&prices[i+1]>prices[i]))
    {
        continue;
    }
}
return sum;
}

//714.股票含手续费
int maxProfit(int* prices, int pricesSize, int fee){
int dp[pricesSize][2];
dp[0][0] = 0, dp[0][1] = -prices[0];
//dp[i][0]代表手里没有股票
//dp[i][1]代表手里有股票
for (int i = 1; i < pricesSize; ++i)
{
dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]-fee);
dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
}
return dp[pricesSize - 1][0];
}

//309.股票含冷冻期(中等)
int maxProfit(int* prices, int pricesSize){
int i,j,dp[pricesSize][3];
dp[0][0]=-prices[0];//手里有股票
dp[0][1]=0;//手里没有股票且不处于冷冻期
dp[0][2]=0;//手里没有股票且处于冷冻期
for(i=1;i<pricesSize;i++)
{
    dp[i][0]=fmax(dp[i-1][0],dp[i-1][1]-prices[i]);
    dp[i][1]=fmax(dp[i-1][2],dp[i-1][1]);
    dp[i][2]=dp[i-1][0]+prices[i];
}
return fmax(dp[i-1][1],dp[i-1][2]);
}

//1220.统计原因字序列数目(困难)（动态规划）
int countVowelPermutation(int n){
    long long mod = 1e9 + 7;
long dp[5][20000]={{1},{1},{1},{1},{1}};
long i;
for(i=1;i<n;i++)
{
dp[0][i]=(dp[1][i-1]+dp[2][i-1]+dp[4][i-1])%mod;
dp[1][i]=(dp[2][i-1]+dp[0][i-1])%mod;
dp[2][i]=(dp[1][i-1]+dp[3][i-1])%mod;
dp[3][i]=(dp[2][i-1])%mod;
dp[4][i]=(dp[2][i-1]+dp[3][i-1])%mod;
}
return (dp[4][n-1]+dp[3][n-1]+dp[2][n-1]+dp[1][n-1]+dp[0][n-1])%mod;
}


//198.打家劫舍I(中等)（动态规划）
#define Max(a,b) (a>b)?a:b
int rob(int* nums, int numsSize){
int *dp= (int*)malloc(sizeof(int)*numsSize);
if(numsSize==1)
return nums[0];
if(numsSize==2)
return Max(nums[0],nums[1]);
dp[0]=nums[0];
dp[1]=Max(nums[1],nums[0]);
int i;
for(i=2;i<numsSize;i++)
dp[i]=Max(dp[i-2]+nums[i],dp[i-1]);
return dp[i-1];
}

//213.打家劫舍II(中等)（动态规划）(围成一个环，注意分类)
#define Max(a,b) (a>b)?a:b
int rob(int* nums, int numsSize){
int *dp= (int*)malloc(sizeof(int)*numsSize);
int *dp1= (int*)malloc(sizeof(int)*numsSize);
if(numsSize==1)
return nums[0];
if(numsSize==2)
return Max(nums[0],nums[1]);
if(numsSize==3)
return Max(Max(nums[0],nums[1]),nums[2]);
dp[0]=nums[0];
dp[1]=Max(nums[1],nums[0]);
dp1[1]=nums[1];
dp1[2]=Max(nums[1],nums[2]);
int i;
for(i=2;i<numsSize-1;i++)
dp[i]=Max(dp[i-2]+nums[i],dp[i-1]);
for(i=3;i<numsSize;i++)
dp1[i]=Max(dp1[i-2]+nums[i],dp1[i-1]);
return Max(dp[i-2],dp1[i-1]);
}


//730.删除并获得点数(中等)（动态规划）（跟打家劫舍差不多，不过我很难以理解）
#define Max(a,b) (a>b)?a:b
int deleteAndEarn(int* nums, int numsSize){
int i,j,k,count=0,max_=0;
int sum[20001]={0},dp[20001];
for(i=0;i<numsSize;i++)
{
    if(nums[i]!=0)
    {
    if(max_<=nums[i])
    max_=nums[i];
    count=1;
    for(j=0;j<numsSize;j++)
    if(nums[i]==nums[j]&&i!=j)
    {
        count++;
        nums[j]=0;
    }
    sum[nums[i]]=nums[i]*count;
    }
}
dp[1]=sum[1];
dp[2]=Max(sum[1],sum[2]);
for(i=3;i<=max_;i++)
dp[i]=Max(dp[i-1],dp[i-2]+sum[i]);
return dp[max_];
}

//746.(最小花费爬楼梯)（动态规划）
int minCostClimbingStairs(int* cost, int costSize){
int dp[1001]={0},i,j,k;
for(i=2;i<=costSize;i++)
dp[i]=fmin(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
return dp[i-1];
}

//55.跳棋(中等)
bool canJump(int* nums, int numsSize){
int i,j,k,d,step=1,max;
if(nums[0]==0)
{
    if(numsSize>1)
return false;
else
return true;
}
for(i=0;i<numsSize-1;)
{
    if(nums[i]+i>=numsSize-1)
    break;
    max=-1;
    for(j=i+1;j<=i+nums[i]&&j<numsSize;j++)
    {
        if(nums[j]+j>=max)
        {
            max=nums[j]+j;
            d=j;
        }
    }
    i=d;
    step++;
    if(step>=100001)
    return false;
}
    return true;
}

//45.跳棋(中等)
int jump(int* nums, int numsSize){
int i,j,k,d,step=1,max;
if(numsSize==1||0)
return 0;
for(i=0;i<numsSize-1;)
{
    if(nums[i]+i>=numsSize-1)
    break;
    max=-1;
    for(j=i+1;j<=i+nums[i]&&j<numsSize;j++)
    {
        if(nums[j]+j>=max)
        {
            max=nums[j]+j;
            d=j;
        }
    }
    i=d;
    step++;
}
return step;
}

//53.最大子数组和(简单)(实际很难)
int maxSubArray(int* nums, int numsSize){
int max,dp,i;
max=dp=nums[0];
for(i=1;i<numsSize;i++){
dp=fmax(dp+nums[i],nums[i]);
max=fmax(dp,max);
}
return max;
}

//918.环形数组的最大子数组和(中等)(很巧妙)
/*
 注:如果最大子数组出现在中间，则做法和53题一样；
    如果最大子数组出现在两侧，则用total-最小子数组和(巧妙且骚);
 */
int maxSubarraySumCircular(int* nums, int numsSize){
int max=INT_MIN,min=INT_MAX,count=0,i,j;
int dp,dk,total=0;
if(numsSize==1)
return nums[0];
max=min=total=dp=dk=nums[0];
for(i=1;i<numsSize;i++)
{
    dp=fmax(dp+nums[i],nums[i]);
    max=fmax(dp,max);
    dk=fmin(dk+nums[i],nums[i]);
    min=fmin(dk,min);
    total=total+nums[i];
}
if(max<0)
return max;
else
return fmax(max,total-min);
}


//42.接雨水(困难)  （实际上也就是求左右两边柱子的最小值）!!!!!!(力扣一整个爱住了)
int trap(int* height, int heightSize){
int i,j,leftmax[heightSize],rightmax[heightSize],sum=0,h;
leftmax[0]=height[0];
rightmax[heightSize-1]=height[heightSize-1];
for(i=1;i<heightSize;i++)
leftmax[i]=fmax(height[i-1],leftmax[i-1]);
for(i=heightSize-2;i>=0;i--)
rightmax[i]=fmax(height[i+1],rightmax[i+1]);
for(i=1;i<heightSize-1;i++)
{
    h=fmin(rightmax[i],leftmax[i]);
    if(h>height[i])
    sum=sum+h-height[i];
}
return sum;
}

//91.解码方法(中等)（开头是一些特殊用例，重点在中间）
int numDecodings(char * s){
if(s[0]=='0')
return 0;
if(strlen(s)==1)
return 1;
if(s[0]>'2'&&s[1]=='0')
return 0;
int dp[101]={0},i;
dp[0]=1;
if((s[0]-48)*10+s[1]-48<=26&&s[1]!='0')
dp[1]=2;
else
dp[1]=1;
if(s[2]=='0'&&s[1]<='2')
dp[1]=dp[0]=dp[2]=1;
for(i=2;i<strlen(s);i++)
{
    if(s[i-1]=='0'&&s[i]=='0')
    return 0;
    if(s[i]!='0')
    {
    if(i==strlen(s)-1||s[i+1]!='0')
    {
        if((s[i-1]-48)*10+s[i]-48<=26&&s[i-1]!='0')
        dp[i]=dp[i-1]+dp[i-2];
        else
        dp[i]=dp[i-1];
    }
    else
    {
        if(s[i]=='0'||s[i]-48>2)
        return 0;
        else
        {
            dp[i+1]=dp[i]=dp[i-1];
            i++;
        }
    }
    }
}
return dp[strlen(s)-1];
}

