#include<stdio.h>
int main(){
    int a, b;
    scanf("%d %d",&a,&b);
    if (a > 0 && b > 0)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    else
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    printf("a=%d b=%d",a,b);
    return 0;
}