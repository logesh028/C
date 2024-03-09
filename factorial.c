#include <stdio.h>
int factorial(int f){
         
      if(f==0){
          return 1;
      }
      else{
          return f*factorial(f-1);
      }
        
        

}
int main()
{
   int f;
   scanf("%d",&f);
   int res=0;
//   for(int i=1;i<=f;i++){
//       res=f*i;
//   }



// int i=1;
// while(i<=f){
//     res=f*i;
//     i++;
// }
   printf("%d",factorial(f));
    return 0;
}

