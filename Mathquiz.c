#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(void)
{
    int correct=0,incorrect=0;
    int ans,t;  ///t is for response

    printf("\nMath Quiz\n\n");
    printf("Enter your response:");
    scanf("%d",&t);

    if(t==0){
        printf("\nThanks for playing the Game :)");
        return 0;
    }

    int a,b;

    for(int i=0;i<t;i++){
        a=rand()%12;
        b=rand()%12;

        printf("%d * %d = ",a,b);

        scanf("%d",&ans);

        if(ans==a*b){
            printf("Congratulations!You are correct!\n\n");
            correct++;
        }
        else if(ans!=a*b){
            printf("You are Incorrect. Please try again!!!\n\n");
            incorrect++;
        }
        else
            printf("Try again later!\n");
    }

    printf("Correct Answer:%d\n",correct);
    printf("Incorrect Answer:%d\n",incorrect);
}
