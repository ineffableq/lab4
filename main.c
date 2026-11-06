#include <stdio.h>
#include <math.h>

// Прототипи функцій для кожного завдання
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();

int main() {
    int choice;

    do {
        printf("\n=====================================\n");
        printf("       ЛАБОРАТОРНА РОБОТА №4         \n");
        printf("=====================================\n");
        printf("1. Завдання №123 (Сума ASCII кодів)\n");
        printf("2. Завдання №130 (Перевірка цілості виразу)\n");
        printf("3. Завдання №149 (Задача Ейлера)\n");
        printf("4. Завдання №186 (Перше число, менше a)\n");
        printf("5. Завдання №247 (Таблиця F(x) = tg(2x) - 3)\n");
        printf("6. Завдання №58  (Сума ряду S)\n");
        printf("7. Завдання №185 (Елементи >= a)\n");
        printf("8. Завдання №74  (Сума ряду S з факторіалом)\n");
        printf("9. Завдання №11  (Таблиця дюймів у см)\n");
        printf("10. Завдання №2  (Дільники числа)\n");
        printf("0. Вихід\n");
        printf("-------------------------------------\n");
        printf("Виберіть номер завдання (0-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            case 0: printf("Вихід з програми...\n"); break;
            default: printf("Некоректний вибір! Спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}

// Реалізація функцій завдань
void task1() {
    printf("\n--- Завдання №123 ---\n");
    char ch;
    int sum = 0;
    printf("Вводьте символи (Esc для завершення):\n");
    while (1) {
        ch = getchar();
        if (ch == 27) break;
        if (ch != '\n' && ch != '\r') {
            sum += (int)ch;
            printf("Символ: '%c' | ASCII: %d | Сума: %d\n", ch, (int)ch, sum);
        }
    }
    printf("Загальна сума кодів: %d\n", sum);
}

void task2() {
    printf("\n--- Завдання №130 ---\n");
    int limit;
    printf("Введіть верхню межу n (парне): ");
    scanf("%d", &limit);
    int is_all_integer = 1;
    for (int n = 2; n <= limit; n += 2) {
        long long numerator = 2LL * n + 3LL * n * n + 1LL * n * n * n;
        if (numerator % 24 != 0) {
            is_all_integer = 0;
            printf("Для n = %d вираз НЕ є цілим!\n", n);
            break;
        } else {
            printf("n = %2d | Результат: %lld\n", n, numerator / 24);
        }
    }
    if (is_all_integer) printf("Твердження підтверджено!\n");
}

void task3() {
    printf("\n--- Завдання №149 ---\n");
    int total = 1770, horse_price = 31, bull_price = 21, solutions = 0;
    for (int x = 0; x <= total / horse_price; x++) {
        int remainder = total - horse_price * x;
        if (remainder % bull_price == 0) {
            int y = remainder / bull_price;
            solutions++;
            printf("Розв'язок %d: Коні = %2d, Бугаї = %2d\n", solutions, x, y);
        }
    }
}

void task4() {
    printf("\n--- Завдання №186 ---\n");
    double a;
    printf("Введіть a (1 < a <= 1.5): ");
    scanf("%lf", &a);
    int n = 2;
    double current = 1.0 + 1.0 / n;
    while (current >= a) {
        n++;
        current = 1.0 + 1.0 / n;
    }
    printf("n = %d | Значення: %.6f\n", n, current);
}

void task5() {
    printf("\n--- Завдання №247 ---\n");
    double a, b, h;
    printf("Введіть a, b, h: ");
    scanf("%lf %lf %lf", &a, &b, &h);
    for (double x = a; x <= b + h / 2.0; x += h) {
        printf("x = %7.3f | F(x) = %9.4f\n", x, tan(2.0 * x) - 3.0);
    }
}

void task6() {
    printf("\n--- Завдання №58 ---\n");
    double x = 2.0, x_sq = x * x, power = x, sum = 0.0;
    for (int k = 1; k <= 11; k += 2) {
        sum += power / k;
        power *= x_sq;
    }
    printf("S = %.6f\n", sum);
}

void task7() {
    printf("\n--- Завдання №185 ---\n");
    double a;
    printf("Введіть a (1 < a <= 1.5): ");
    scanf("%lf", &a);
    int n = 2;
    double val = 1.0 + 1.0 / n;
    while (val >= a) {
        printf("n = %2d | Значення: %.6f\n", n, val);
        n++;
        val = 1.0 + 1.0 / n;
    }
}

void task8() {
    printf("\n--- Завдання №74 ---\n");
    double x; int n;
    printf("Введіть x та n (1 < n <= 10): ");
    scanf("%lf %d", &x, &n);
    double sum = 1.0, term = 1.0;
    for (int k = 1; k <= n; k++) {
        term = term * x / k;
        sum += term;
    }
    printf("S = %.6f\n", sum);
}

void task9() {
    printf("\n--- Завдання №11 ---\n");
    for (int inches = 10; inches <= 22; inches++) {
        printf("%2d in = %6.2f cm\n", inches, inches * 2.54);
    }
}

void task10() {
    printf("\n--- Завдання №2 ---\n");
    int num;
    printf("Введіть число: ");
    scanf("%d", &num);
    printf("Дільники: ");
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) printf("%d ", i);
    }
    printf("\n");
}