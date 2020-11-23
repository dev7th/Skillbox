/// Задача 2. Компьютерное зрение
/// Вы участвуете в разработке искусственного интеллекта, который играет в шахматы
/// на доске размером 0,8 х 0,8 метра. Робот смотрит камерой на доску и видит
/// расположение фигур в вещественных числах с высокой точностью. Напишите программу:
/// после ввода вещественных координат шахматной фигуры программа должна определить,
/// в какой клетке доски находится эта фигура. Каждая клетка доски имеет размер
/// 10х10 сантиметров и целочисленные координаты, состоящие из двух чисел. Например,
/// левая верхняя клетка имеет целые координаты (0, 0), справа от неё клетка (1, 0),
/// а снизу (0, 1). Обеспечьте контроль ввода.
/// Пример
/// Ввод:
/// Введите местоположение фигуры:
/// 0.731;
/// 0.149.
/// Вывод:
/// Фигура находится в клетке (7, 1).

#include <iostream>

class Coordinates {
public:
    float x, y;
};

int main() {
    std::cout << "Ввод:\nВведите местоположение фигуры: ";
    Coordinates coord{};
    std::cin >> coord.x >> coord.y;

    if (coord.x < 0 || coord.y < 0 || coord.x > 0.8 || coord.y > 0.8) {
        std::cout << "Вышли за границы!\n";
        return -1;
    }

    std::cout << "Вывод:\nФигура находится в клетке (" << static_cast<int>(coord.x * 10)
              << ", " << static_cast<int>(coord.y * 10) << ").\n";

    return 0;
}
