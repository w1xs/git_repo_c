#include <stdio.h>
#include <malloc.h>

int main(){

    int* din_arr;
    int input, flag;

    scanf("%d", &input);
    din_arr = (int*)malloc(input * sizeof(int));

    for(int i = 0; i < input; i++){
        scanf("%d", &din_arr[i]);
    }

    flag = 1;
    for(int i = 0; i < (input-1); i++){
        if(din_arr[i] != din_arr[i+1]){
            flag = 0;
            break;
        }
    }

    if(flag){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}