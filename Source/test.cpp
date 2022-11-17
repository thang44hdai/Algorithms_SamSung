#include<stdio.h>
#include<math.h>
 
int main()
{
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%.0f",ceil((double)(c-b)/(a-b)));
    return 0;
}