//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//


#ifndef PRODUCTMANAGER_PRODUCTMANAGER_H
#define PRODUCTMANAGER_PRODUCTMANAGER_H

#include "PhysicalProduct.h"
#include "DigitalProduct.h"
#include <string>
#include <sstream>
#include <vector>

class ProductManager {
private:
    std::vector<DigitalProduct> listOfDigitalProducts;
    std::vector<PhysicalProduct> listOfPhysicalProducts;
public:
    ProductManager();

    ~ProductManager();

    void addPhysicalProduct(PhysicalProduct product_);

    void addDigitalProduct(DigitalProduct product_);

    std::string toString();

    const std::vector<DigitalProduct> &getListOfDigitalProducts() const;

    void setListOfDigitalProducts(const std::vector<DigitalProduct> &listOfDigitalProducts);

    const std::vector<PhysicalProduct> &getListOfPhysicalProducts() const;

    void setListOfPhysicalProducts(const std::vector<PhysicalProduct> &listOfPhysicalProducts);
};


#endif //PRODUCTMANAGER_PRODUCTMANAGER_H