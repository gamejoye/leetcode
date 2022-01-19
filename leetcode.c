
//704.二分查找（简单）
int search(int* nums, int numsSize, int target){
int i,j;
for(i=0,j=numsSize-1;i<=j;i++,j--)
{
    if(nums[i]==target)
    return i;
    else if(nums[j]==target)
    return j;
    else if(nums[i]!=target&&nums[j]!=target)
    continue;
    else
    return;
}
return -1;
}

//35.搜索插入位置(简单)
int searchInsert(int* nums, int numsSize, int target){
int i,j;
for(i=0,j=numsSize-1;i<=j;i++,j--)
{
    if(nums[0]>target)
    return 0;
    if(nums[numsSize-1]<target)
    return numsSize;
    if(nums[i]>target)
    return i;
    if(nums[j]<target)
    return j+1;
    if(nums[i]==target)
    return i;
    if(nums[j]==target)
    return j;
}
return i;
}
 
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

//167.两数之和II（简单）（双指针）
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
int i,j=numbersSize-1;
int* a = (int*)malloc(sizeof(int) * 2);
*returnSize=2;
for(i=0;i<j;)
{
    if(numbers[i]+numbers[j]==target)
    {
        a[0]=i+1;
        a[1]=j+1;
        break;
    }
    (numbers[i]+numbers[j]>target)?j--:i++;
}
return a;
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

//509.(简单)
int fib(int n){
if(n==0||n==1)
return n;
else
return fib(n-1)+fib(n-2);
}

//1137.（简单）
int tribonacci(int n){
    int i,a[38]={0,1,1},sum=2;
    if(n==0)return 0;
    if(n==1||n==2)return 1;
for(i=3;i<=n;i++)
a[i]=a[i-1]+a[i-2]+a[i-3];
return a[i-1];
}

//70.(简单)
int arrange(int m,int n)
{
    if(m==0)
    return 1;
    long i,j,k=1,ways=1;
    for(i=n;k<=m;i--,k++)
    ways=i*ways/k;
    return ways;
}
int climbStairs(int n){
int i,j,m,sum=0;
m=n/2;
for(i=0;i<=m;i++)
sum=sum+arrange(i,n-i);
return sum;
}

//746.(最小话费爬楼梯)（动态规划）
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
