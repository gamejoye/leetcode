
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
