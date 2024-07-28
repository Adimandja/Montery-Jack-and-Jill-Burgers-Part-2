/* Program name: burger.h
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Header file for the Burger class, which includes static maps for enum to string and string to enum conversion.
 */

#ifndef BURGER_H
#define BURGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

enum class BunType { SESAME, WHEAT, GLUTEN_FREE, BRIOCHE, ONION, RYE, NONE };
enum class PattyType { BEEF, TURKEY, CHICKEN, PORTABELLA, VEGGIE };
enum class Topping { GRILLED_ONION, RAW_ONION, TOMATO, LETTUCE, BACON, GRILLED_MUSHROOM, PICKLE, NONE };
enum class Condiment { KETCHUP, MUSTARD, MAYONNAISE, SPECIAL_SAUCE, BBQ_SAUCE, STEAK_SAUCE, PEPPERCORN_RANCH, NONE };
enum class Cheese { CHEDDAR, AMERICAN, PEPPER_JACK, SWISS, COLBY_JACK, NONE };

class Burger {
private:
    BunType bun;
    PattyType patty;
    std::vector<Topping> toppings;
    std::vector<Condiment> condiments;
    Cheese cheese;
    int patties;
    bool vegetarian;

    static std::unordered_map<BunType, std::string> bunTypeToString;
    static std::unordered_map<std::string, BunType> stringToBunType;
    static std::unordered_map<PattyType, std::string> pattyTypeToString;
    static std::unordered_map<std::string, PattyType> stringToPattyType;
    static std::unordered_map<Topping, std::string> toppingToString;
    static std::unordered_map<std::string, Topping> stringToTopping;
    static std::unordered_map<Condiment, std::string> condimentToString;
    static std::unordered_map<std::string, Condiment> stringToCondiment;
    static std::unordered_map<Cheese, std::string> cheeseToString;
    static std::unordered_map<std::string, Cheese> stringToCheese;

public:
    Burger(PattyType patty = PattyType::BEEF, BunType bun = BunType::SESAME, int patties = 1, Cheese cheese = Cheese::NONE, bool vegetarian = false);

    BunType getBunType() const;
    void setBunType(BunType bun);
    PattyType getPattyType() const;
    void setPattyType(PattyType patty);
    Cheese getCheese() const;
    void setCheese(Cheese cheese);
    int getPatties() const;
    void setPatties(int patties);
    bool isVegetarian() const;
    void setVegetarian(bool vegetarian);

    std::string getBunTypeString() const;
    std::string getPattyTypeString() const;
    std::string getCheeseString() const;
    std::string getToppingsString() const;
    std::string getCondimentsString() const;

    void addTopping(Topping topping);
    void addCondiment(Condiment condiment);
    void clearToppings();
    void clearCondiments();

    static void initializeMaps();

    friend std::ostream& operator<<(std::ostream& out, const Burger& burger);
};

#endif // BURGER_H
