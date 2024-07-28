/* Program name: burger.cpp
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Implementation file for the Burger class, which includes methods for enum to string and string to enum conversion.
 */

#include "burger.h"
#include <algorithm>

// Static maps initialization
std::unordered_map<BunType, std::string> Burger::bunTypeToString;
std::unordered_map<std::string, BunType> Burger::stringToBunType;
std::unordered_map<PattyType, std::string> Burger::pattyTypeToString;
std::unordered_map<std::string, PattyType> Burger::stringToPattyType;
std::unordered_map<Topping, std::string> Burger::toppingToString;
std::unordered_map<std::string, Topping> Burger::stringToTopping;
std::unordered_map<Condiment, std::string> Burger::condimentToString;
std::unordered_map<std::string, Condiment> Burger::stringToCondiment;
std::unordered_map<Cheese, std::string> Burger::cheeseToString;
std::unordered_map<std::string, Cheese> Burger::stringToCheese;

Burger::Burger(PattyType patty, BunType bun, int patties, Cheese cheese, bool vegetarian) 
    : patty(patty), bun(bun), patties(patties), cheese(cheese), vegetarian(vegetarian) {}

BunType Burger::getBunType() const { return bun; }
void Burger::setBunType(BunType bun) { this->bun = bun; }

PattyType Burger::getPattyType() const { return patty; }
void Burger::setPattyType(PattyType patty) { this->patty = patty; }

Cheese Burger::getCheese() const { return cheese; }
void Burger::setCheese(Cheese cheese) { this->cheese = cheese; }

int Burger::getPatties() const { return patties; }
void Burger::setPatties(int patties) { this->patties = patties; }

bool Burger::isVegetarian() const { return vegetarian; }
void Burger::setVegetarian(bool vegetarian) { this->vegetarian = vegetarian; }

std::string Burger::getBunTypeString() const { return bunTypeToString[bun]; }
std::string Burger::getPattyTypeString() const { return pattyTypeToString[patty]; }
std::string Burger::getCheeseString() const { return cheeseToString[cheese]; }
std::string Burger::getToppingsString() const { 
    std::string result;
    for (auto topping : toppings) {
        if (!result.empty()) result += ", ";
        result += toppingToString[topping];
    }
    return result;
}
std::string Burger::getCondimentsString() const { 
    std::string result;
    for (auto condiment : condiments) {
        if (!result.empty()) result += ", ";
        result += condimentToString[condiment];
    }
    return result;
}

void Burger::addTopping(Topping topping) { 
    if (topping != Topping::NONE) {
        toppings.push_back(topping);
    }
}
void Burger::addCondiment(Condiment condiment) { 
    if (condiment != Condiment::NONE) {
        condiments.push_back(condiment);
    }
}
void Burger::clearToppings() { toppings.clear(); }
void Burger::clearCondiments() { condiments.clear(); }

void Burger::initializeMaps() {
    bunTypeToString[BunType::SESAME] = "Sesame";
    bunTypeToString[BunType::WHEAT] = "Wheat";
    bunTypeToString[BunType::GLUTEN_FREE] = "Gluten Free";
    bunTypeToString[BunType::BRIOCHE] = "Brioche";
    bunTypeToString[BunType::ONION] = "Onion";
    bunTypeToString[BunType::RYE] = "Rye";
    bunTypeToString[BunType::NONE] = "None";

    stringToBunType["sesame"] = BunType::SESAME;
    stringToBunType["wheat"] = BunType::WHEAT;
    stringToBunType["gluten free"] = BunType::GLUTEN_FREE;
    stringToBunType["brioche"] = BunType::BRIOCHE;
    stringToBunType["onion"] = BunType::ONION;
    stringToBunType["rye"] = BunType::RYE;
    stringToBunType["none"] = BunType::NONE;

    pattyTypeToString[PattyType::BEEF] = "Beef";
    pattyTypeToString[PattyType::TURKEY] = "Turkey";
    pattyTypeToString[PattyType::CHICKEN] = "Chicken Breast";
    pattyTypeToString[PattyType::PORTABELLA] = "Portabella Mushroom";
    pattyTypeToString[PattyType::VEGGIE] = "Veggie";

    stringToPattyType["beef"] = PattyType::BEEF;
    stringToPattyType["turkey"] = PattyType::TURKEY;
    stringToPattyType["chicken breast"] = PattyType::CHICKEN;
    stringToPattyType["portabella mushroom"] = PattyType::PORTABELLA;
    stringToPattyType["veggie"] = PattyType::VEGGIE;

    toppingToString[Topping::GRILLED_ONION] = "Grilled Onion";
    toppingToString[Topping::RAW_ONION] = "Raw Onion";
    toppingToString[Topping::TOMATO] = "Tomato";
    toppingToString[Topping::LETTUCE] = "Lettuce";
    toppingToString[Topping::BACON] = "Bacon";
    toppingToString[Topping::GRILLED_MUSHROOM] = "Grilled Mushroom";
    toppingToString[Topping::PICKLE] = "Pickle";
    toppingToString[Topping::NONE] = "None";

    stringToTopping["grilled onion"] = Topping::GRILLED_ONION;
    stringToTopping["raw onion"] = Topping::RAW_ONION;
    stringToTopping["tomato"] = Topping::TOMATO;
    stringToTopping["lettuce"] = Topping::LETTUCE;
    stringToTopping["bacon"] = Topping::BACON;
    stringToTopping["grilled mushroom"] = Topping::GRILLED_MUSHROOM;
    stringToTopping["pickle"] = Topping::PICKLE;
    stringToTopping["none"] = Topping::NONE;

    condimentToString[Condiment::KETCHUP] = "Ketchup";
    condimentToString[Condiment::MUSTARD] = "Mustard";
    condimentToString[Condiment::MAYONNAISE] = "Mayonnaise";
    condimentToString[Condiment::SPECIAL_SAUCE] = "Special Sauce";
    condimentToString[Condiment::BBQ_SAUCE] = "BBQ Sauce";
    condimentToString[Condiment::STEAK_SAUCE] = "Steak Sauce";
    condimentToString[Condiment::PEPPERCORN_RANCH] = "Peppercorn Ranch";
    condimentToString[Condiment::NONE] = "None";

    stringToCondiment["ketchup"] = Condiment::KETCHUP;
    stringToCondiment["mustard"] = Condiment::MUSTARD;
    stringToCondiment["mayonnaise"] = Condiment::MAYONNAISE;
    stringToCondiment["special sauce"] = Condiment::SPECIAL_SAUCE;
    stringToCondiment["bbq sauce"] = Condiment::BBQ_SAUCE;
    stringToCondiment["steak sauce"] = Condiment::STEAK_SAUCE;
    stringToCondiment["peppercorn ranch"] = Condiment::PEPPERCORN_RANCH;
    stringToCondiment["none"] = Condiment::NONE;

    cheeseToString[Cheese::CHEDDAR] = "Cheddar";
    cheeseToString[Cheese::AMERICAN] = "American";
    cheeseToString[Cheese::PEPPER_JACK] = "Pepper Jack";
    cheeseToString[Cheese::SWISS] = "Swiss";
    cheeseToString[Cheese::COLBY_JACK] = "Colby Jack";
    cheeseToString[Cheese::NONE] = "None";

    stringToCheese["cheddar"] = Cheese::CHEDDAR;
    stringToCheese["american"] = Cheese::AMERICAN;
    stringToCheese["pepper jack"] = Cheese::PEPPER_JACK;
    stringToCheese["swiss"] = Cheese::SWISS;
    stringToCheese["colby jack"] = Cheese::COLBY_JACK;
    stringToCheese["none"] = Cheese::NONE;
}

std::ostream& operator<<(std::ostream& out, const Burger& burger) {
    out << "Protein: " << burger.getPattyTypeString() << "\n"
        << "Number of patties: " << burger.getPatties() << "\n"
        << "Bun Type: " << burger.getBunTypeString() << "\n"
        << "Cheese: " << burger.getCheeseString() << "\n"
        << "Condiments: " << burger.getCondimentsString() << "\n"
        << "Toppings: " << burger.getToppingsString() << "\n";

    if (burger.isVegetarian()) {
        out << "This is a vegetarian burger.\n";
    }

    return out;
}
