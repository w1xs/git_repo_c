#include<stdio.h>
int main(){
    int input, hour, minute;
    scanf("%d",&input);
    hour = input / 60;
    minute = input - (hour * 60);
    if (hour < 10 && minute < 10){
        printf("0%d:0%d", hour, minute);
    }
    if (hour > 10 && minute < 10){
        printf("%d:0%d", hour, minute);
    }
    if (hour < 10 && minute > 10){
        printf("0%d:%d", hour, minute);
    }
    if (hour > 10 && minute > 10){
        printf("%d:%d", hour, minute);
    }
    return 0;
}