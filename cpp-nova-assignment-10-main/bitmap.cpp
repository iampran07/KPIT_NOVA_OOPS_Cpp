#include "bitmap.h"
#include <iostream>
#include <cstring> // For strcpy, strncpy
#include <vector>
#include <algorithm> // For std::sort, std::min_element, std::max_element

// Laptop class implementation
Laptop::Laptop() : lid(0), cost(0.0) {
    strcpy(make, "");
}

Laptop::Laptop(int id, const char* m, double c) : lid(id), cost(c) {
    strncpy(make, m, sizeof(make) - 1);
    make[sizeof(make) - 1] = '\0'; // Ensure null-termination
}

int Laptop::GetLid() {
    return lid;
}

char* Laptop::GetMake() {
    return make;
}

double Laptop::GetCost() {
    return cost;
}

void Laptop::Display() {
    std::cout << "Laptop ID: " << lid << std::endl;
    std::cout << "Make: " << make << std::endl;
    std::cout << "Cost: " << cost << std::endl;
}

// LaptopStore class implementation
void LaptopStore::InsertLaptop(Laptop laptop) {
    vect_laptop.push_back(laptop);
}

void LaptopStore::SortLaptops() {
    std::sort(vect_laptop.begin(), vect_laptop.end(), [](const Laptop& a, const Laptop& b) {
        return a.GetCost() < b.GetCost();
    });
}

std::vector<Laptop> LaptopStore::GetVect_Laptop() {
    return vect_laptop;
}

Laptop LaptopStore::GetMinCostLaptop() {
    if (vect_laptop.empty()) {
        throw std::runtime_error("No laptops in the store.");
    }
    auto min_it = std::min_element(vect_laptop.begin(), vect_laptop.end(), [](const Laptop& a, const Laptop& b) {
        return a.GetCost() < b.GetCost();
    });
    return *min_it;
}

Laptop LaptopStore::GetMaxCostLaptop() {
    if (vect_laptop.empty()) {
        throw std::runtime_error("No laptops in the store.");
    }
    auto max_it = std::max_element(vect_laptop.begin(), vect_laptop.end(), [](const Laptop& a, const Laptop& b) {
        return a.GetCost() < b.GetCost();
    });
    return *max_it;
}

void LaptopStore::ShowLaptops() {
    for (const auto& laptop : vect_laptop) {
        laptop.Display();
        std::cout << "---------------------------" << std::endl;
    }
}
