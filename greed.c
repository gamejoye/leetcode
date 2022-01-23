//334.递增的三元子序列(贪心)
bool increasingTriplet(int* nums, int numsSize){
int i,min=INT_MAX-1,mid=INT_MAX;
for(i=0;i<numsSize;i++)
{
    if(nums[i]<=min)
    min=nums[i];
    else if(nums[i]<=mid)
    mid=nums[i];
    else
    return true;
}
return false;
}
