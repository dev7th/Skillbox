/// Задача 10. Яйца
/* В рамках программы колонизации Марса, компания «Спейс Инжиниринг» вывела
 * особую породу черепах, которые должны размножаться, откладывая яйца в
 * марсианском грунте. Откладывать яйца слишком близко к поверхности опасно
 * из-за радиации, а слишком глубоко — опасно из-за давления грунта и недостатка
 * кислорода. Вообще факторов много, но специалисты проделали большую работу и
 * предположили, что уровень опасности для черепашьих яиц рассчитывается по
 * формуле D = x^3 - 3x^2 - 12x + 10, где x — глубина кладки в метрах,
 * а D — уровень опасности в условных единицах. Для тестирования гипотезы нужно
 * взять пробу грунта на безопасной, согласно формуле, глубине.
 * Напишите программу, находящую такое значение глубины х, при котором уровень
 * опасности наиболее близок к нулю, учитывая допустимое отклонение. На вход
 * программе подаётся максимально допустимое отклонение уровня опасности от нуля,
 * а программа должна рассчитать приблизительное значение х, удовлетворяющее
 * этому отклонению. Известно, что глубина точно больше нуля и меньше 4 метров.
 * Обеспечьте контроль ввода.
 * Пример
 * Ввод:
 * Введите максимально допустимый уровень опасности: 0,01.
 * Вывод:
 * Приблизительная глубина безопасной кладки: 0,732422 метра */

#include <iostream>
#include <cmath>

/// Функция расчета глубины кладки.
/// С помощью тригонометрической формулы Виета:
/// x^3 + ax^2 + bx + c = 0
/// \param danger -- максимально допустимый уровень опасности.
/// \return x -- глубина кладки
float computeCubicEquation(float &danger) {
    // x^3 - 3x^2 - 12x + 10 - D = 0
    float const a{-3}, b{-12};
    float c = 10 - danger;

    // (a^2 - 3b) / 9
    float q = (a * a - 3 * b) / 9;

    // (2a^3 - 9ab + 27)/ 54
    float r = (2 * powf(a, 3) - 9 * a * b + 27 * c) / 54;

    // q^3 - r^2
    float s = powf(q, 3) - r * r;

    // 1/3 * arccos(r / sqrt(q^3))
    float fi = 1.f / 3.f * acosf(r / sqrtf(powf(q, 3)));

    float x1 = -2 * sqrtf(q) * cosf(fi) - a / 3;

    float x2 = -2 * sqrtf(q) * cosf(fi + 2.f / 3.f * static_cast<float>(M_PI))
               - a / 3;

    float x3 = -2 * sqrtf(q) * cosf(fi - 2.f / 3.f * static_cast<float>(M_PI))
               - a / 3;

    if (x1 > 0 && x1 < 4)
        return x1;
    else if (x2 > 0 && x2 < 4)
        return x2;
    else
        return x3;
}

int main() {
    std::cout << "Ввод:\nВведите максимально допустимый уровень опасности: ";
    float danger;
    std::cin >> danger;

    std::cout << "Вывод:\nПриблизительная глубина безопасной кладки: "
              << computeCubicEquation(danger) << " метра";

    return 0;
}