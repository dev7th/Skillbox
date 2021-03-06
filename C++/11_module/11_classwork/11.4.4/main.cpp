/// Задача 4. Убийца Photoshop
/// Вы разрабатываете новый крутой графический редактор. Один из инструментов
/// редактора позволяет делать градиент — плавный переход между двумя точками
/// разной яркости. Яркость точки определяется целым числом от 0 до 255, где
/// 0 — чёрный, 255 — белый, а всё, что между ними — оттенки серого.
/// Напишите код для расчёта яркости точки градиента между двумя заданными
/// точками. Пользователь вводит яркость левой границы градиента, потом яркость
/// правой границы и параметр: число от 0 до 1, которое означает интересующую
/// нас точку. Например, если параметр равен 0.5, то искомая точка находится
/// ровно посередине между левой и правой границами, если параметр равен 0, то
/// искомая точка совпадает с левой границей, и, наконец, если параметр равен 1,
/// то искомая точка совпадает с правой границей. Программа должна вывести число
/// — яркость искомой точки. Обеспечьте контроль ввода.
/// Пример
/*
Ввод:
Введите яркость левую границу градиента: 10.
Введите правую границу градиента: 255.
Введите положение точки между границами: 0.7.
Вывод:
Яркость точки: 181.5.
*/
#include <iostream>
#include <cmath>

struct Gradient {
    int left;
    int right;
    float dot;
};

int main() {
    Gradient gradient{10, 255, 0.7f};
    std::cout << "Ввод:\nВведите яркость левую границу градиента: ";
    std::cin >> gradient.left;

    std::cout << "Введите правую границу градиента: ";
    std::cin >> gradient.right;

    std::cout << "Введите положение точки между границами: ";
    std::cin >> gradient.dot;

    if (gradient.left < 0 || gradient.right > 255 || gradient.dot < 0 ||
        gradient.dot > 1) {
        return -1;
    }

    float brightness;

    if (gradient.dot == 0)
        brightness = static_cast<float>(gradient.left);
    else if (gradient.dot == 1)
        brightness = static_cast<float>(gradient.right);
    else
        brightness = std::fabs(static_cast<float>(gradient.right - gradient.left)) *
                     gradient.dot;

    std::cout << "Вывод:\nЯркость точки: " << brightness << "\n";

    return 0;
}
