
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
