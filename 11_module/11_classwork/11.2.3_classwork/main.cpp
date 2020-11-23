/// Задача 3. Постоянный покупатель
/// Иногда к Араику Вачагановичу приходят постоянные покупатели, для которых он
/// делает скидку. Для каждого такого клиента скидка своя. Модифицируйте программу
/// из задачи «Орехи»: Араик будет вводить цену товара за 100 грамм, вес покупки
/// и размер скидки в процентах, а программа должна выводить итоговую стоимость.

#include <iostream>

int main() {
    std::cout << "Введите цену товара за 100 грамм, общий вес и скидку (%): ";
    float weightTotal{0.0f}, price100{0.0f}, discount{0.0f};
    std::cin >> price100 >> weightTotal >> discount;

    float priceTotal = price100 * weightTotal / 100 * (100 - discount) / 100;

    std::cout << "Стоимость покупки " << weightTotal << " грамм равна "
              << priceTotal << " с учетом скидки в "
              << discount << " процентов.\n";

    return 0;
}
