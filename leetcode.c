
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

//037. 小行星(中等)(不懂力扣所以做了比较久吧)
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


