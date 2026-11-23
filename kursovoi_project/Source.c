
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define UCL 63.83
#define N   40

double calc_q(double x);
int    proverca_Q(double Q);
void   print_result(double x, double Q, int state);

int main(void)
{
    setlocale(LC_CTYPE, "RUS");

    int i;
    double x, Q;
    int state;

    printf("------------------- МОНИТОРИНГ ДАВЛЕНИЯ РУБАШКИ -------------------\n");
    printf("Программа рассчитывает индикатор Q по показаниям датчика давления\n");
    printf("и определяет состояние процесса (норма / превышение UCL = %.2f).\n\n", UCL);

    for (i = 1; i <= N; i++)
    {
        printf("Введите X (значение %d из %d): ", i, N);
        if (scanf("%lf", &x) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("НЕИЗВЕСТНЫЙ СИМВОЛ\n\n");
            i--;
            continue;
        }

        if (x < 1.0 || x > 8.0)
        {
            printf("Ошибка: показание вне диапазона [1...8] бар.\n\n");
            continue;
        }

        Q = calc_q(x);
        state = proverca_Q(Q);
        print_result(x, Q, state);
    }

    printf("ОБРАБОТКА ЗАВЕРШЕНА\n");
    return 0;
}

double calc_q(double x)
{
    if (x < 2.0)
        return 3.0 * (x - 2.0) + 10.0;
    else if (x <= 5.0)
        return 2.0 * sqrt(x - 1.5) + 45.0;
    else
        return (x - 5.0) * (x - 5.0) + 55.0;
}

int proverca_Q(double Q)
{
    return (Q > UCL) ? 1 : 0;
}

void print_result(double x, double Q, int state)
{
    printf("X = %.2f   |   Q = %.2f   |   Состояние: ", x, Q);
    if (state == 0)
        printf("НОРМАЛЬНЫЙ Q\n\n");
    else
        printf("ПРЕВЫШЕНО ЗНАЧЕНИЕ Q\n\n");
}