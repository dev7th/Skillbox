/// Задача 9. Маятник
/* Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4%
 * от амплитуды прошлого колебания. Если качнуть маятник, он, строго говоря,
 * никогда не остановится: его амплитуда будет уменьшаться до тех пор, пока мы
 * не сочтём такой маятник остановившимся. Напишите программу, определяющую,
 * сколько раз качнётся маятник, прежде чем он, по нашему мнению, остановится.
 * Программа получает на вход начальную амплитуду колебания в сантиметрах и
 * конечную амплитуду его колебаний, которая считается остановкой маятника.
 * Обеспечьте контроль ввода.*/

#include <iostream>

int main() {
  std::cout << "Введите начальную и конечную амплитуду маятника: ";
  float firstAmplitude, lastAmplitude;
  std::cin >> firstAmplitude >> lastAmplitude;

  if (0 == firstAmplitude) {
    std::cout << "Маятник не кочнулся ни разу.\n";
    return -1;
  } else if (firstAmplitude < lastAmplitude) {
    std::cout << "Начальная амплитуда должна быть больше конечной!\n";
    return -1;
  }

  int oscillation = 0;
  for (; firstAmplitude >= lastAmplitude; ++oscillation)
    firstAmplitude -= (firstAmplitude * 8.4f / 100.f);

  std::cout << "Маятник кочнулся " << oscillation << " раз\n";

  return 0;
}
