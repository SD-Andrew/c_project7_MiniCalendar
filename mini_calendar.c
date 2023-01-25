#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if (year % 4 != 0) {
      //printf("false not by 4");
      return false;
    }
    else if (year % 100 != 0) {
      //printf("true not div by 100");
       return true;
    }
    else if (year % 400 != 0) {
      //printf("false not / by 400");
       return true;
    }
    else {
      //printf("true - final else");
      return true;
    }
}


int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
  int days_left_in_month = 0;
  while(days_left_to_add > 0){
    days_left_in_month = days_in_month[*mm] - *dd;

    if(*mm == 02 && is_leap_year(*yy) == true){
      days_left_in_month++;
    }

        if (days_left_to_add > days_left_in_month) {
        days_left_to_add -= days_left_in_month + 1;
        *dd = 1;

          if (*mm == 12) {
            *mm = 1;
            *yy = *yy + 1;
          }
          else 
            *mm = *mm + 1;
        } 
        else {
          *dd = *dd + days_left_to_add;
         days_left_to_add = 0; 
        } 
  }



}

int main() {

 int year, mm, dd, yy, days_left_to_add;

 printf("enter year (1800-10000): \n");
 scanf("%i", &year);
 bool x = is_leap_year(year);

 if (x==true){
    printf("Leap Year\n");
 }
  else {
    printf("Not Leap Year\n");
  }
printf("Enter a date between years 1800 and 10000 with the format mm dd yy and provide the numbers of days you want to add to that date: \n");
scanf ("%i%i%i%i", &mm, &dd, &yy, &days_left_to_add);

add_days_to_date (&mm, &dd, &yy, days_left_to_add);

printf("%i %i %i\n", mm, dd, yy);

}



