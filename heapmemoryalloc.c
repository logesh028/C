//using fnction to allocate memory IN HEAP 
#include <stdio.h>
#include <stdlib.h>
void* myfun(int s){
   int *ptr =malloc(s);
    return ptr;
}

int main()
{
    //pointer  memory allocation explanation.
    int a=10;
    int *pt = &a;
    printf("\n%d",*pt);
    printf("\n%ld",pt);
    *pt=20;
    printf("\n%d",*pt);
    printf("\n%ld",pt);
    
    
    int *ptr = myfun(10);
    *ptr=234;
    printf("\n%d",*ptr);
    *(ptr+1)=432;
    printf("\n%d",*(ptr+1));
    printf("\n%ld",ptr);
};
