#include <stdio.h>
#include <malloc.h>
#include <locale.h>

long factorial(long number){
    long result = 1;
    for(int i = 1; i <= number; i++){
        result = result * i;
    }
    return result;
}

double power(double x, int pow){
    double result = 1;
    for(int i = 1; i <= pow; i++){
        result = result * x;
    }
    return result;
}

double absolute(double number){
    double result;
    if(number < 0){
        result = -number;
    }
    else{
        result = number;
    }
    return result;

}

int main(){
    float x, eps;
    double element, func, summ;
    int i, minus_or_plus;

    setlocale(0,"");
    printf("Введите вещественное число x для функции cos(x): ");
    scanf("%f",&x);
    printf("Введите положительное вещественное число эпсилон: ");
    scanf("%f",&eps);

    if(eps > 0){
        i = 2;
        func = 1;        
        element = (power(x,2) / factorial(2));
        func -= element;
        minus_or_plus = 0;
        summ = 0;

        while(absolute(element) >= eps){
            i += 2;
            element = (element/(i * (i-1)) * power(x,2));
            summ += element;
            if (minus_or_plus){
                func -= element;
                minus_or_plus = 0;
            }
            else{
                func += element;
                minus_or_plus = 1;
            }
        }

        printf("Значение x: %f\n", x);
        printf("Значение эпсилон: %f\n", eps);
        printf("Значение суммы ряда: %f\n", summ);
        printf("Значение cos(x): %f\n", func);
        printf("Абсолютное значение последнего члена ряда: %f\n", absolute(element));
        printf("Разность суммы ряда и cos(x): %f\n", summ - func);
        printf("%d", i);

    }
    else{
        printf("ERROR: Число эпсилон не может быть отрицательным");
    }    
    return 0;
}