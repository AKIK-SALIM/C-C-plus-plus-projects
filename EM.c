#include<stdio.h>
int main()
{
    system("color 02");
    int i,j,space=1;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){  ///E
           if(i==1||i==3||i==5||j==1)
               printf("*");
           else
             printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///I
            if(i==1||j==3||i==5)
              printf("*");
            else
                printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///D
                if(j==1||(i==1&&j==4)||(i==5&&j==4)||(j==5&&(i==2||i==3||i==4)))
                  printf("*");
                else
                    printf(" ");
        }

        printf("\n");
    }
    printf("\n");

    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){  ///M
                if(j==1||j==5||((i==1&&j==1)||(i==2&&j==2)||(i==3&&j==3))||((i==2&&j==4)||(i==1&&j==5)))
                  printf("*");
                else
                    printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///U
                if(j==1||i==5||j==5)
                    printf("*");
                else
                    printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///B
            if(j==1||(i==1&&j==4)||(i==5&&j==4)||i==3||(j==5&&(i==2||i==3||i==4)))
              printf("*");
            else
                printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///A
                if((i==1&&j==3)||(i==2&&(j==2||j==4))||i==3||(i==4&&(j==1||j==5))||(i==5&&(j==1||j==5)))
                  printf("*");
                else
                    printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///R
                if(j==1||i==1||i==3||(j==5&&(i==1||i==2||i==3||i==5))||(i==4&&j==4))
                   printf("*");
                else
                    printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///A
          if((i==1&&j==3)||(i==2&&(j==2||j==4))||i==3||(i==4&&(j==1||j==5))||(i==5&&(j==1||j==5)))
            printf("*");
          else
            printf(" ");
        }
        for(space=1;space<=3;space++)
            printf(" ");
        for(j=1;j<=5;j++){ ///K
                if(j==1||(i==1&&j==4)||(i==2&&j==3)||(i==3&&j==2)||(i==4&&j==3)||(i==5&&j==4))
                  printf("*");
               else
                 printf(" ");
        }

        printf("\n");
    }

    printf("\033[91m");

    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
          if((i==0&&j!=3)||(j==0&&i==1)||(j==0&&i==2)||(j==3&&i==1)||(i==3&&j==1)||(i==4&&j==2)||(i==5&&j==3)||(i==4&&j==4)||(i==3&&j==5)||(i==2&&j==6)||(i==1&&j==6))
              printf("*");
          else
             printf(" ");
        }
        printf("\n");
    }

     printf("\033[0m");


    return 0;
}
