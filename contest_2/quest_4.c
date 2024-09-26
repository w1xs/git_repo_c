#include <stdio.h>
#include <malloc.h>

int main(){
    int* din_arr;
    int arr_len, min, flag;

    scanf("%d", &arr_len);

    if(arr_len >= 0){ 
        din_arr = (int*)malloc(arr_len * sizeof(int));

        for(int i = 0; i < arr_len; i++){
            scanf("%d", &din_arr[i]);
        }

        min = din_arr[0];
        flag = 0;
        for(int i = 0; i < arr_len; i++){
            if(i % 2 == 1){
                if(flag == 0){
                    flag = 1;
                    min = din_arr[i];                
                }
                else{
                    if(din_arr[i] < min){
                        min = din_arr[i];
                    }
                }
            }
        }
        if(min == din_arr[0] && flag == 0){
            printf("not found");
        }
        else{
            printf("%d", min);        
        }
    }
    else{
        printf("not found");
    }
    return 0;
}