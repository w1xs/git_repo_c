#include <stdio.h>
#include <malloc.h>

int main(){
    int* din_arr;
    int arr_len, max, flag;

    scanf("%d", &arr_len);

    if(arr_len >= 0){ 
        din_arr = (int*)malloc(arr_len * sizeof(int));

        for(int i = 0; i < arr_len; i++){
            scanf("%d", &din_arr[i]);
        }

        max = 1;
        flag = 0;
        for(int i = 0; i < arr_len; i++){
            if(din_arr[i] < 0 && din_arr[i] % 2 == 0){
                max = din_arr[i];
                flag = 1;
                break;
            }
        }
        
        if(flag){
            for(int i = 0; i < arr_len; i++){
                if(din_arr[i] < 0 && din_arr[i] % 2 == 0){
                    if(din_arr[i] > max){
                        max = din_arr[i];
                    }
                }
            }
        }

        if(max == 1){
            printf("not found");
        }
        else{
            printf("%d", max);            
        }

    }
    else{
        printf("not found");
    }
    return 0;
}