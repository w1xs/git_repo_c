#include <stdio.h>
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
    int i, x_is_number, eps_is_number;

    setlocale(0,"");
    printf("Введите вещественное число x для функции cos(x): ");
    x_is_number = scanf("%f",&x);
    printf("Введите положительное вещественное число эпсилон: ");
    eps_is_number = scanf("%f",&eps);

    if(x_is_number && eps_is_number){
        if(eps > 0){
            i = 2;
            func = 1;        
            element = -(power(x,2) / factorial(2));
            func += element;
            summ = 0;

            while(absolute(element) >= eps){
                i += 2;
                element = -(element/(i * (i-1)) * power(x,2));
                summ += absolute(element);
                func += element;
            }

            printf("Значение x: %f\n", x);
            printf("Значение эпсилон: %f\n", eps);
            printf("Значение суммы ряда: %f\n", summ);
            printf("Значение cos(x): %f\n", func);
            printf("Абсолютное значение последнего члена ряда: %f\n", absolute(element));
            printf("Разность суммы ряда и cos(x): %f\n", summ - func);

        }
        else{
            printf("ERROR: Число эпсилон не может быть отрицательным");
        }
    }
    else{
        printf("ERROR: Введенные значения не могут быть переданы x и эпсилон");
    }
    return 0;
}