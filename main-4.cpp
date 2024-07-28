/* Program name: main.cpp
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Main program to create multiple burgers, allowing the user to specify bun and patty types using strings.
 */

#include "burger.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    Burger::initializeMaps();

    std::vector<Burger> burgers;
    char addMore;

    do {
        int patties;
        std::string pattyType, bunType, cheeseType, topping, condiment;

        std::cout << "How many patties do you want on your burger? ";
        std::cin >> patties;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        std::cout << "Please enter a protein: ";
        std::getline(std::cin, pattyType);
        pattyType = toLowerCase(pattyType);

        Burger burger;
        try {
            burger = Burger(Burger::stringToPattyType.at(pattyType));
            burger.setPatties(patties);
        } catch (const std::out_of_range&) {
            std::cerr << "You have chosen an invalid protein type. Available protein types are: \n";
            for (const auto& pair : Burger::pattyTypeToString) {
                std::cerr << pair.second << "\n";
            }
            continue;
        }

        std::cout << "Please enter a topping. Enter -1 to move to the next step\n";
        while (true) {
            std::getline(std::cin, topping);
            topping = toLowerCase(topping);
            if (topping == "-1") break;

            try {
                burger.addTopping(Burger::stringToTopping.at(topping));
            } catch (const std::out_of_range&) {
                std::cerr << "You did not choose a valid topping. Enter one of the following toppings:\n";
                for (const auto& pair : Burger::toppingToString) {
                    std::cerr << pair.second << "\n";
                }
            }
        }

        std::cout << "Please enter a Condiment. Enter -1 to move to the next step\n";
        while (true) {
            std::getline(std::cin, condiment);
            condiment = toLowerCase(condiment);
            if (condiment == "-1") break;

            try {
                burger.addCondiment(Burger::stringToCondiment.at(condiment));
            } catch (const std::out_of_range&) {
                std::cerr << "You did not choose a valid condiment. Enter one of the following condiments:\n";
                for (const auto& pair : Burger::condimentToString) {
                    std::cerr << pair.second << "\n";
                }
            }
        }

        std::cout << "Please enter a bun: ";
        std::getline(std::cin, bunType);
        bunType = toLowerCase(bunType);
        try {
            burger.setBunType(Burger::stringToBunType.at(bunType));
        } catch (const std::out_of_range&) {
            std::cerr << "You have chosen an invalid bun type. Available bun types are: \n";
            for (const auto& pair : Burger::bunTypeToString) {
                std::cerr << pair.second << "\n";
            }
            continue;
        }

        std::cout << "Please enter a cheese: ";
        std::getline(std::cin, cheeseType);
        cheeseType = toLowerCase(cheeseType);
        try {
            burger.setCheese(Burger::stringToCheese.at(cheeseType));
        } catch (const std::out_of_range&) {
            std::cerr << "You have chosen an invalid cheese type. Available cheese types are: \n";
            for (const auto& pair : Burger::cheeseToString) {
                std::cerr << pair.second << "\n";
            }
            continue;
        }

        burgers.push_back(burger);

        std::cout << "Would you like to change the burger? Please choose from the menu.\n";
        std::cout << "1. Change Protein\n";
        std::cout << "2. Change Number of Patties\n";
        std::cout << "3. Change Toppings\n";
        std::cout << "4. Change Cheese\n";
        std::cout << "5. Change Bun\n";
        std::cout << "6. Change Condiments\n";
        std::cout << "7. No Changes\n";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        while (choice != 7) {
            switch (choice) {
                case 1:
                    std::cout << "Please enter a protein: ";
                    std::getline(std::cin, pattyType);
                    pattyType = toLowerCase(pattyType);
                    try {
                        burger.setPattyType(Burger::stringToPattyType.at(pattyType));
                    } catch (const std::out_of_range&) {
                        std::cerr << "You have chosen an invalid protein type. Available protein types are: \n";
                        for (const auto& pair : Burger::pattyTypeToString) {
                            std::cerr << pair.second << "\n";
                        }
                    }
                    break;
                case 2:
                    std::cout << "How many patties do you want on your burger? ";
                    std::cin >> patties;
                    std::cin.ignore(); // To ignore the newline character left in the buffer
                    burger.setPatties(patties);
                    break;
                case 3:
                    burger.clearToppings();
                    std::cout << "Please enter a topping. Enter -1 to move to the next step\n";
                    while (true) {
                        std::getline(std::cin, topping);
                        topping = toLowerCase(topping);
                        if (topping == "-1") break;

                        try {
                            burger.addTopping(Burger::stringToTopping.at(topping));
                        } catch (const std::out_of_range&) {
                            std::cerr << "You did not choose a valid topping. Enter one of the following toppings:\n";
                            for (const auto& pair : Burger::toppingToString) {
                                std::cerr << pair.second << "\n";
                            }
                        }
                    }
                    break;
                case 4:
                    std::cout << "Please enter a cheese: ";
                    std::getline(std::cin, cheeseType);
                    cheeseType = toLowerCase(cheeseType);
                    try {
                        burger.setCheese(Burger::stringToCheese.at(cheeseType));
                    } catch (const std::out_of_range&) {
                        std::cerr << "You have chosen an invalid cheese type. Available cheese types are: \n";
                        for (const auto& pair : Burger::cheeseToString) {
                            std::cerr << pair.second << "\n";
                        }
                    }
                    break;
                case 5:
                    std::cout << "Please enter a bun: ";
                    std::getline(std::cin, bunType);
                    bunType = toLowerCase(bunType);
                    try {
                        burger.setBunType(Burger::stringToBunType.at(bunType));
                    } catch (const std::out_of_range&) {
                        std::cerr << "You have chosen an invalid bun type. Available bun types are: \n";
                        for (const auto& pair : Burger::bunTypeToString) {
                            std::cerr << pair.second << "\n";
                        }
                    }
                    break;
                case 6:
                    burger.clearCondiments();
                    std::cout << "Please enter a Condiment. Enter -1 to move to the next step\n";
                    while (true) {
                        std::getline(std::cin, condiment);
                        condiment = toLowerCase(condiment);
                        if (condiment == "-1") break;

                        try {
                            burger.addCondiment(Burger::stringToCondiment.at(condiment));
                        } catch (const std::out_of_range&) {
                            std::cerr << "You did not choose a valid condiment. Enter one of the following condiments:\n";
                            for (const auto& pair : Burger::condimentToString) {
                                std::cerr << pair.second << "\n";
                            }
                        }
                    }
                    break;
                default:
                    std::cerr << "You have entered an invalid choice. Please try again.\n";
                    break;
            }

            std::cout << "Would you like to change the burger? Please choose from the menu.\n";
            std::cout << "1. Change Protein\n";
            std::cout << "2. Change Number of Patties\n";
            std::cout << "3. Change Toppings\n";
            std::cout << "4. Change Cheese\n";
            std::cout << "5. Change Bun\n";
            std::cout << "6. Change Condiments\n";
            std::cout << "7. No Changes\n";

            std::cin >> choice;
            std::cin.ignore(); // To ignore the newline character left in the buffer
        }

        burgers.push_back(burger);

        std::cout << "Do you want to enter another burger? (y/n): ";
        std::cin >> addMore;
        std::cin.ignore(); // To ignore the newline character left in the buffer

    } while (addMore == 'y' || addMore == 'Y');

    std::cout << "\nYour order:\n";
    for (const auto& burger : burgers) {
        std::cout << burger << "\n";
    }

    return 0;
}
