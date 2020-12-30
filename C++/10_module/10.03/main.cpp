/// Задача 3. Улучшенная кофемашина.
/// Сотрудники “Спейс Инжиниринг” всё ещё не очень довольны. Часто бывает, что
/// они выбирают напиток, и только потом видят, что не хватает какого-то
/// ингредиента. Модифицируйте программу так, чтобы если молока и воды не хватает
/// ни на один из видов напитков, программа выдавала отчёт и завершалась. В отчёте
/// должно быть написано, что ингредиенты подошли к концу, указан остаток воды
/// и молока в машине, а также сколько всего было приготовлено чашек американо
/// и латте за эту смену. Обеспечьте контроль ввода.

#include <iostream>

int main() {
    int16_t milk{}, water{}; // Остаток молока в кофемашине.

    std::string coffee[]{"американо", "латте"};
    std::string userCoffeeChoice;

    while (true) {
        std::cout << "Добавьте молоко и воду в кофемашину: ";
        std::cin >> milk >> water;

        std::cout << "В кофемашине " << milk << " мл молока и " << water << " мл воды\n";

        for (int counter = 0;;) {
            if (water < 300 && milk < 270 || water < 30) {
                std::cout << "Не хватает ингридиентов! Молока осталось " << milk
                          << " мл, воды " << water << " мл.\n"
                          << "Приготовлено " << counter << " чашек " << coffee[0]
                          << " и " << coffee[1] << " за смену.\n";
                return 0;
            }

            std::cout << "Добро пожаловать! Какой напиток вы хотите: ";
            // Перебирает 2 варианта с кофе, может быть больше
            for (const auto &c : coffee)
                std::cout << c << "/";
            // Удаление последнего слеша и пробела.
            std::cout << "\b? ";

            // Чтение названия напитка.
            std::cin >> userCoffeeChoice;

            // пользователь выбрал американо
            if (userCoffeeChoice == coffee[0]) {
                if (water < 300) {
                    std::cout << "Не хватает воды для приготовления "
                              << coffee[0] << "! Воды осталось " << water
                              << " мл. Выберите другой напиток...\n\n";
                } else {
                    std::cout << "Ваш " << coffee[0] << " готов!\n\n";
                    water -= 300;
                    counter++;
                }
                // пользователь выбрал латте
            } else if (userCoffeeChoice == coffee[1]) {
                if (milk < 270) {
                    std::cout << "Не хватает молока для приготовления "
                              << coffee[1] << ". Осталось " << milk
                              << " мл молока! Выберите другой напиток...\n\n";
                } else {
                    std::cout << "Ваш " << coffee[1] << " готов!\n\n";
                    water -= 30;
                    milk -= 270;
                    counter++;
                }
            } else
                std::cout << "К сожалению, пока что кофемашина не умеет готовить "
                             "данный вид напитка!\n\n";
        }
    }
}