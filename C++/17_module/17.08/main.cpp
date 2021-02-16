/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 8. Почти-Майнкрафт.
 * Нам всё-таки предстоит сделать некое подобие Майнкрафта. Миллионов не обещаю,
 * но это довольно интересная задача на пространственное мышление. У нас есть
 * небольшой квадратный ландшафт, размером 5х5 секторов. В каждом секторе
 * располагается блок (столбик) ландшафта, максимальная высота которого — это 10
 * блоков. Текущая высота каждого такого блока задаётся пользователем вначале
 * программы. Итоговая задача — используя трёхмерный массив вывести в
 * стандартный вывод горизонтальное сечение (или горизонтальный срез) нашего
 * небольшого мира. Сам мир как раз должен быть представлен в виде трёхмерного
 * массива. Его горизонтальный срез стало быть — это двумерный массив, который
 * надо отобразить в виде единиц и нулей. 0 — это отсутствие элемента на данном
 * уровне в данной точке, 1 — элемент есть. Уровень среза от 0 до 9 включительно
 * — также задаётся в стандартном вводе.
 * @version   0.1
 * @date      16-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\x1b[2J";
  uint16_t array[5][5][10];
  std::cout << "Enter numbers from 0 to 9:\n";
  for (size_t i{}; i < 5; ++i) {
    for (size_t j{}; j < 5; ++j) {
      uint16_t nBlocks{};
      do {
        std::cin >> nBlocks;
        if (nBlocks < 10)
          break;
        else
          std::cout << "\x1b[31mError: number of blocks more than 9."
                    << "\x1b[37m\n";
      } while (true);
      for (size_t k{}; k <= nBlocks; ++k) array[i][j][k] = k;
    }
  }

  uint16_t level;
  do {
    std::cout << "Chart level to view (0 - 9).\x1b[32m\n";
    std::cin >> level;
  } while (level > 9);

  std::cout << "\x1b[37m\n";

  for (size_t i{}; i < 5; ++i) {
    for (size_t j{}; j < 5; ++j)
      std::cout << (array[i][j][level] == level ? "\x1b[32m1 " : "\x1b[33m0 ");
    std::cout << "\n";
  }

  std::cout << "\x1b[37m\n";

  return 0;
}