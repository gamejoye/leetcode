//pratice ovo
//pratic 1 uou
//pratice 2 qaq

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

//735. 小行星(中等)(不懂力扣所以做了比较久吧)
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
int i,j,k,flag=-1;
*returnSize = 0;
int *stack = (int *)malloc(sizeof(int) * asteroidsSize);
for(i=0;i<asteroidsSize;i++)
{
    if(asteroids[i]>0)
    flag=i;
    if(asteroids[i]<0)
    {
        if(flag>-1&&asteroids[flag]!=0)
        {
            if(asteroids[flag]==-asteroids[i])
            {
                asteroids[i]=asteroids[flag]=0;
                for(k=flag;k>=0;k--)
                {
                    if(asteroids[k]>0)
                    {
                        flag=k;
                        break;
                    }
                }
            }
            else if(asteroids[flag]<-asteroids[i])
            {
                asteroids[flag]=0;
                for(k=flag;k>=0;k--)
                {
                    if(asteroids[k]>0)
                    {
                        flag=k;
                        break;
                    }
                }
                i--;
            }
            else
            asteroids[i]=0;
        }
    }
}
for(i=0,j=0;i<asteroidsSize;i++)
if(asteroids[i]!=0)
stack[j++]=asteroids[i];
*returnSize=j;
return stack;
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


//289.移动零(简单)（我个人挺喜欢这个做法）
void moveZeroes(int* nums, int numsSize){
int i,j;
for(i=0,j=numsSize-1;i<j;)
{
    if(nums[i]==0)
    {
        for(k=i;k<j;k++)
        nums[k]=nums[k+1];
        nums[j]=0;
        j--;
    }
    if(nums[i]!=0)
    i++;
}
return nums;
}


//679.24点(困难)
bool judgePoint24(int* cards, int cardsSize){
    float operate(float a,float b,char ch);
    float expression_5(float a,float b,float c,float d,char ch,char ck,char cl);
    float expression_4(float a,float b,float c,float d,char ch,char ck,char cl);
    float expression_3(float a,float b,float c,float d,char ch,char ck,char cl);
    float expression_2(float a,float b,float c,float d,char ch,char ck,char cl);
    float expression_1(float a,float b,float c,float d,char ch,char ck,char cl);
    char op_[4]={'+','-','*','/'};
    float a,b,c,d;
    float res,core[4];
    int t,flag,i,j,k,l,n,m,o;
    core[0]=cards[0];
    core[1]=cards[1];
    core[2]=cards[2];
    core[3]=cards[3];
        flag=0;
        for(l=0;l<4;l++)
        for(n=0;n<4;n++)
        for(m=0;m<4;m++)
        for(o=0;o<4;o++)
        {
            a=core[l];
            if(n!=l)
            b=core[n];
            else
            continue;
            if(m!=n&&m!=l)
            c=core[m];
            else
            continue;
            if(o!=l&&o!=n&&o!=m)
            d=core[o];
            else
            continue;
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        for(k=0;k<4;k++)
        {
            res=expression_1(a,b,c,d,op_[i],op_[j],op_[k]);
            if(res-24>=-0.01&&res-24<=0.01)
            return true;
            res=expression_2(a,b,c,d,op_[i],op_[j],op_[k]);
            if(res-24>=-0.01&&res-24<=0.01)
            return true;
            res=expression_3(a,b,c,d,op_[i],op_[j],op_[k]);
            if(res-24>=-0.01&&res-24<=0.01)
            return true;
            res=expression_4(a,b,c,d,op_[i],op_[j],op_[k]);
            if(res-24>=-0.01&&res-24<=0.01)
            return true;
            res=expression_5(a,b,c,d,op_[i],op_[j],op_[k]);
            if(res-24>=-0.01&&res-24<=0.01)
            return true;
        }
        }
        return false;
}
float operate(float a,float b,char ch)
{
    if(ch=='+')
    return a+b;
    else if(ch=='-')
    return a-b;
    else if(ch=='*')
    return a*b;
    else if(ch=='/'&&b!=0)
    return a/b;
    else
    return 0;
}
float expression_5(float a,float b,float c,float d,char ch,char ck,char cl)
{
    float res=0;
    res=operate(c,d,cl);
    res=operate(b,res,ck);
    res=operate(a,res,ch);
    return res;
}
float expression_4(float a,float b,float c,float d,char ch,char ck,char cl)
{
    float res=0;
    res=operate(b,c,ck);
    res=operate(res,d,cl);
    res=operate(a,res,ch);
    return res;
}
float expression_3(float a,float b,float c,float d,char ch,char ck,char cl)
{
    float res=0,ret=0;
    res=operate(a,b,ch);
    ret=operate(c,d,cl);
    res=operate(res,ret,ck);
    return res;
}
float expression_2(float a,float b,float c,float d,char ch,char ck,char cl)
{
    float res=0;
    res=operate(a,b,ch);
    res=operate(res,c,ck);
    res=operate(res,d,cl);
    return res;
}
float expression_1(float a,float b,float c,float d,char ch,char ck,char cl)
{
    float res=0;
    res=operate(b,c,ck);
    res=operate(a,res,ch);
    res=operate(res,d,cl);
    return res;
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

//477.汉明(中等)（很巧我很喜欢）
int totalHammingDistance(int* nums, int numsSize){
int count=0,d=0,k,i,j,n=0;
while(1)
{
n=0;
d=0;
for(i=0;i<numsSize;i++)
{
    if(nums[i]&1==1)
    n++;
    if(nums[i]!=0)
    d=1;
    nums[i]>>=1;
}
count=count+n*(numsSize-n);
if(d==0)
break;
}
return count;
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


//15.三数之和(中等)（排序+双重循环过，如果三重循环超时）（一部分指针的声明参考题解）
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,j,k,l=0,min,count,sum;
    int **ans = (int **)malloc(sizeof(int *) * numsSize  *numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize=0;
    if(numsSize<3)
    return returnColumnSizes;
    for(i=0;i<numsSize;i++)
    {
    min=100000;
    for(j=i;j<numsSize;j++)
    {
    if(nums[j]<=min)
    {
        min=nums[j];
        k=j;
    }
    }
    count=nums[i];
    nums[i]=min;
    nums[k]=count;
    }
    for(i=0;i<numsSize-2;i++)
    {
        for(j=i+1,k=numsSize-1;j<k;)
        {
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                ans[*returnSize] = (int*)malloc(sizeof(int)*3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = nums[k];
                ans[*returnSize][1] = nums[i];
                ans[*returnSize][2] = nums[j];
                *returnSize += 1;
                for(;;j++)
                {
                    if(j+2>=numsSize||nums[j]!=nums[j+1])
                    {
                        j++;
                        break;
                    }
                }
                }
                else if(sum<0)
                j++;
                else
                k--;
        }
        for(;;i++)
        {
            if(i+3>=numsSize||nums[i]!=nums[i+1])
            break;
        }
    }
    return ans;
}

//18.四数之和(中等)(排序+三重循环+双指针)
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(sizeof(int*)*numsSize*numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize=0;
    long long sum;
    int i,j,k,l,count,min;
    for(i=0; i<numsSize; i++)
    {
        min=INT_MAX;
        for(j=i; j<numsSize; j++)
        {
            if(nums[j]<=min)
            {
                min=nums[j];
                k=j;
            }
        }
        count=nums[i];
        nums[i]=min;
        nums[k]=count;
    }
    for(i=0; i<numsSize-3; i++)
    {
        for(j=i+1; j<numsSize-2;)
        {
            for(k=j+1,l=numsSize-1; k<l;)
            {
                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                if(sum==target)
                {
                    ans[*returnSize] = (int*)malloc(sizeof(int)*4);
                    (*returnColumnSizes)[*returnSize] = 4;
                    ans[*returnSize][0] = nums[k];
                    ans[*returnSize][1] = nums[i];
                    ans[*returnSize][2] = nums[j];
                    ans[*returnSize][3] = nums[l];
                    *returnSize += 1;
                    for(;; k++)
                    {
                        if(k+2>=numsSize||nums[k]!=nums[k+1])
                        {
                            k++;
                            break;
                        }
                    }
                }
                else if(sum<target)
                    k++;
                else
                    l--;
            }
            for(;; j++)
            {
                if(j+3>=numsSize||nums[j]!=nums[j+1])
                {
                    j++;
                    break;
                }
            }
        }
        for(;; i++)
        {
            if(i+4>=numsSize||nums[i]!=nums[i+1])
                break;
        }
    }
    return ans;
}


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

//695.岛屿的最大面积(搜索深度遍历dfs)
//第一次做这种题
int fun(int** grid, int gridSize, int* gridColSize,int i,int j){
if(i<0||i>=gridSize||j<0||j>=gridColSize[0]||grid[i][j]==0)
return 0;
grid[i][j]=0;
return 1+
fun(grid,gridSize,gridColSize,i+1,j)+
fun(grid,gridSize,gridColSize,i-1,j)+
fun(grid,gridSize,gridColSize,i,j+1)+
fun(grid,gridSize,gridColSize,i,j-1);
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
int max=0,ans,i,j;
for(i=0;i<gridSize;i++)
for(j=0;j<gridColSize[0];j++)
{
    ans=fun(grid,gridSize,gridColSize,i,j);
    if(max<ans)
    max=ans;
}
return max;
}

//611.三角形个数(中等)          !!!!!!!!!!!!!!!!!
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int triangleNumber(int* nums, int numsSize){
int i,j,k,count=0,d=0,core=0,min;
qsort(nums,numsSize,sizeof(nums[0]),comp);
for(i=0;i<numsSize-2;i++)
{
k=i+2;
for(j=i+1;j<numsSize-1&&nums[i]!=0;j++)
{
    while(k<numsSize&&nums[i]+nums[j]>nums[k])
    k++;
    core=core+k-j-1;
}
}
return core;
}
