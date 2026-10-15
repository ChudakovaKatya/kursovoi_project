#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define UCL 63.83 //верхняя граница Q(x)

int main(void)
{
    setlocale(LC_CTYPE, "RUS");

    double x;        //показание датчика 
    double Q;       //индикатор процесса 
    int    state;  //состояние датчика
    int    i;     //счётчик цикла 
    


    printf("----------------------------------МОНИТОРНГ ДАВЛЕНИЯ РУБАШКИ----------------------------------\n\n");
  
  

    // обрабатываем значения
    for (i = 1; i <= 40; i = i + 1)
    {
        printf("Введите X  (значение %d из 5): ", i);
        scanf("%lf", &x);

        /* проверка диапазона */
        if (x < 1 || x > 8)
        {
            puts("Ошибка: показание вне диапазона \n");
            continue;
        }

        /* преобразование Q = f(X) по формуле */
        if (x < 2.0)
        {
            Q = 3 * (x - 2) + 10;
        }

        else if (x>=2 || x <= 5.0)
        {
            Q = 2*sqrt(x-3.5+2)+45;
        }

        else if (x>5)
        {
            Q = (pow(x-5,2)/1)+55;
        }



        // контроль верхней границе 
        if (Q > UCL)
        {
            state = 1;   //СИГНАЛ!!!!!!
        }
        else
        {
            state = 0;   //НОРМАЛЬНО
        }
      

            /* вывод результата */
            printf("X = %.2f   Q = %.2f   Состояние: ", x, Q);
            switch (state)
            {
            case 0:
                printf("НОРМА\n\n");
                break;
            case 1:
                printf("ТРЕВОГА\n\n");
                break;
            default:
                printf("НЕИЗВЕСТНО\n\n");
                break;
            }
        
        
    }

    printf("Состояние программы: завершена\n");
    return 0;
}