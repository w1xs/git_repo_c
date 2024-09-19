#include<stdio.h>
int main(){
    int input, go_to_work, easy_number;
    go_to_work = scanf("%d", &input);
    if (go_to_work != 0 && input > 1){
        easy_number = 1;
        for(int i = 2; i*i <= input; i++){
            if(input % i == 0){
                easy_number = 0;
                break; 
            }
        }    
        if(easy_number){
            printf("YES");
        }
        else{
            printf("NO");
        }    
    }
    else{
        printf("ERROR");
    }
    return 0;
}