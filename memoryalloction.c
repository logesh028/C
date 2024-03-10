#include<stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr=malloc(4);//malloc
    printf("%u\n",ptr);
    ptr=realloc(ptr,8);
    *(ptr)=1;
    *(ptr+1)=2;
    printf("%u",*ptr);
    printf("\n%u",*(ptr+1));
    free(ptr);
    
    int *ptr1 = calloc(4,4);//calloc
    printf("\n%p",ptr1);
    
    int*ptr2  = (int*)malloc(sizeof(int));//after free ptr it value is NULL.
    free(ptr2);
    printf("\n%p",*ptr2);
    ptr2=NULL;
    printf("\n%d",ptr2);
    return 0;
}
