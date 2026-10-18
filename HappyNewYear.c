#include<stdio.h>
#include<stdlib.h>

int get_1st_weekday(int year){

    ///Zeller Algorithm
    int day;
    day=(((year-1)* 365)+((year-1)/4)-((year-1)/100)+(year/400)+1)%7;

    return day;
}

int main(void)
{
    system("Color A");
    int year,month,day,dayInMonth,startingDay;
    printf("\nEnter your Desired Year:");
    scanf("%d",&year);

    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

    int DatesOfMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

    ///Checking Leap Year
    if((year%4==0&&year%100!=0)||year%400==0){
          DatesOfMonth[1]=29;
    }

    startingDay=get_1st_weekday(year);

    for(month=0;month<12;month++){

            dayInMonth=DatesOfMonth[month];
        printf("\n\n-------------%s------------\n",months[month]);
        printf("  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        int weekDay=0;

        for(weekDay=0;weekDay<startingDay;weekDay++){
            printf("     ");
        }

          for(day=1;day<=dayInMonth;day++){
              printf("%5d",day);

              if((++weekDay)>6){
                   printf("\n");
                   weekDay=0;
              }
          }
              startingDay=weekDay;
    }
    printf("\n\n");
}
