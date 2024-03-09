
#include <stdio.h>

struct node{
    int a;
    int b;
    
};
int sum(int,int);
int main()
{
    unsigned char a=255;
    printf("%u\n",a);
    printf("%lu",&a);
    printf("\n%d",sum(a,10));
    return 0;
    
}
int sum(int a,int b){
    printf("\n%lu",&a);
    return a+b;
}
