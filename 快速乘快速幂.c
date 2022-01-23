//29.(两数相除)(快速乘)(上面是一些特殊情况，重点是中间的while)
int divide(int dividend, int divisor){
if(dividend==INT_MIN&&divisor==INT_MIN)
return 1;
if(dividend==0||divisor==INT_MIN)
return 0;
if(dividend==INT_MIN&&divisor==-1)
return INT_MAX;
if(dividend==INT_MIN&&divisor==1)
return INT_MIN;
int d=0;
if(dividend<0&&divisor>0)
d=1;
if(dividend>0&&divisor<0)
d=1;
int count=0,n=1;
if(dividend>0)
dividend=-dividend;
if(divisor>0)
divisor=-divisor;
if(divisor<dividend)
return 0;
int res=divisor;
while(1)
{
    if(dividend-res-res<=divisor)
    {
        dividend=dividend-res;
        count=count+n;
        res=res+divisor;
        n++;
    }
    else
    {
        res=divisor;
        if(dividend<=divisor)
        {
        dividend=dividend-res;
        n=1;
        count=count+n;
        }
    }
    if(dividend>divisor)
    break;
}
if(d==1)
return -count;
return count;
}


//50.Pow(x,n)  (快速幂)
double myPow(double x, int n){
    double d=0,res=1;
    long m;
    m=n;
    if(n<0){
    m=n;
    m=-m;
    d=1;
    }
while(m)
{
    if(m&1)res=res*x;
    x=x*x;
    m>>=1;
    if(m==0)
    break;
}
if(d==1)
return 1/res;
return res;
}
