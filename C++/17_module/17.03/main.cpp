/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 3. Проход змейкой.
 * Довольно абстрактная, но интересная задача. У нас есть двумерный массив целых
 * чисел размером 5 на 5 элементов. Его надо инициализировать и отобразить на
 * экране. Особенность именно в способе этой инициализации. Элементы должны быть
 * инициализированы не последовательно, а змейкой. Т.е. в конце каждой строки мы
 * не должны переходить к первому элементу следующей строки, но начнём наоборот
 * — с последнего элемента и так далее. В итоге, в конечном отображении нашего
 * массива числа должны быть упорядочены по возрастанию но змеевидно от строки к
 * строке. Сама же последовательность чисел — это простое линейное возрастание
 * от 0 до 24, для её учёта можно завести отдельную переменную. Попытайтесь
 * решить эту задачу, используя минимальное количество временных переменных и
 * без условных переходов if. Если вы найдёте эту самую формулу индексации —
 * будет замечательно! Предупреждаю, она может быть весьма витиеватая.
 * Итоговый результат:
 * 0 1 2 3 4
 * 9 8 7 6 5
 * 10 11 12 13 14
 * 19 18 17 16 15
 * 20 21 22 23 24
 * @version   0.1
 * @date      12-02-2021
 * @copyright Copyright (c) 2021
 */

#include <cmath>
#include <iostream>

int main() {
  std::cout << "\x1b[2J";
  int16_t array[5][5]{};
  size_t arrayLength{sizeof(array) / sizeof(array[0])};

  int16_t temp{};
  for (size_t i{}; i < arrayLength; ++i) {
    if (i != 0) temp = array[i - 1][4] + arrayLength;
    for (size_t j{}; j < arrayLength; ++j)
      array[i][j] = temp + std::pow(-1, i) * j;
  }

  std::cout << "\x1b[32mOutput:\x1b[37m\n";
  for (size_t i{}; i < 5; ++i) {
    for (size_t j{}; j < 5; ++j) std::cout << array[i][j] << "\t";
    std::cout << "\n";
  }

  return 0;
}