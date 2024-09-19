#include<stdio.h>
int main(){
    int input, go_to_work, count_simple, chislo, is_easy_number;

    go_to_work = scanf("%d", &input);
    if (go_to_work != 0 && input > 0){
        input -= 1;
        if(input == 0){
            printf("1 ");
        }
        else{
            count_simple = 0;
            printf("1 ");
            chislo = 1;
            while(count_simple < input){
                chislo += 1;
                is_easy_number = 1;
                for(int del = 2; del*del <= chislo; del++){
                    if(chislo % del == 0){
                        is_easy_number = 0;
                        break;
                    }
                }
                if(is_easy_number){
                    count_simple += 1;
                    printf("%d ", chislo);
                }
            }
        }
    }
    else{
        printf("ERROR");
    }

    return 0;
}