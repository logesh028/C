#include <stdio.h>
char myfun(int,float);
int main() 
{
    int a=168;
    float b=100;
    printf("%c",myfun(a,b));

    return 0;
}
char myfun(int a,float b){
   int  d=(int)b;
    char c =a%d;
    return c;
}
