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

//289.移动零(简单)（我个人挺喜欢这个做法）
void moveZeroes(int* nums, int numsSize){
int i,j,k,count=0;
for(i=0;i<numsSize;i++)
{
    if(nums[i]==0)
    count++;
    if(nums[i]!=0)
    nums[i-count]=nums[i];
}
for(j=numsSize-1;j>numsSize-1-count;j--)
nums[j]=0;
return nums;
}
