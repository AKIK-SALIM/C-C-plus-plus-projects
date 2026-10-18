#include<stdio.h>
int main()
{
    int h=1,n=1,v=1;
    float x,F;
    printf("Enter Body Temp(C):");
    scanf("%f",&x);
    printf("Headache(1/0):");
    scanf("%d",&h);
    printf("Nausea(1/0):");
    scanf("%d",&n);
    printf("Vomiting(1/0):");
    scanf("%d",&v);
    F=(float)(9.0/5)*x+32;
    if(F>98.6){
    if(h&&n&&v)
        printf("No fever identified");
    else if(h&&n)
        printf("You're diagnosed with Malaria\n");
    else if(n&&v)
         printf("You're diagnosed with Dengue\n");
    else if(h==0&&n==0&&v==0)
        printf("You have only a viral fiver\n");
   }
   else if(F<=98.6){
     if(n&&v)
        printf("You don't have any fever.Go home\n");

   }
    return 0;
}
