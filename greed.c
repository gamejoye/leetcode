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

//1405.最长快乐字符串(大概理解了吧)(看起来简单，做起来难)
typedef struct {
    int freq;
    char ch;
} Pair;

int cmp(const void * pa, const void * pb) {
    return ((Pair *)pb)->freq - ((Pair *)pa)->freq;
}

char * longestDiverseString(int a, int b, int c){
    Pair arr[3]={{a,'a'},{b,'b'},{c,'c'}};
    char * res = (char *) malloc ( (sizeof ( char ) ) * ( a+b+c+1 ) );
    int post = 0;
    while(1)
    {
        qsort(arr, 3, sizeof(Pair), cmp);
        bool hasNext = false;
        for(int i=0;i<3;i++)
        {
            int freq = arr[i].freq;
            int ch = arr[i].ch;
            if(freq<=0)
            break;
            if(post>=2&&res[post-2]==ch&&res[post-1]==ch)
            continue;
            hasNext=true;
            res[post++] = ch;
            arr[i].freq--;
            break;
        }
        if(hasNext==false)
        break;
    }
    res[post]='\0';
    return res;
}

