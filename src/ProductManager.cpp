//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//


#include "ProductManager.h"

ProductManager::ProductManager() {
}

ProductManager::~ProductManager() {

}

void ProductManager::addDigitalProduct(DigitalProduct product_) {
    listOfDigitalProducts.push_back(product_);
}

void ProductManager::addPhysicalProduct(PhysicalProduct product_) {
    listOfPhysicalProducts.push_back(product_);
}

std::string ProductManager::toString() {
    std::stringstream stringOfProducts;
    int Product = 1;
    if (!(listOfPhysicalProducts.empty())) {
        for (auto listIterator = listOfPhysicalProducts.begin(); listIterator
                                                                 != listOfPhysicalProducts.end(); ++listIterator) {
            stringOfProducts << "Product: #" << Product++ << " " << listIterator->getTypeofProduct() << std::endl;
            stringOfProducts << listIterator->toString() << std::endl;
        }
    }
    if (!(listOfDigitalProducts.empty())) {
        for (auto listIterator = listOfDigitalProducts.begin();
             listIterator != listOfDigitalProducts.end(); ++listIterator) {
            stringOfProducts << "Product: #" << Product++ << std::endl;
            stringOfProducts << listIterator->toString() << std::endl;
        }
    }
    return stringOfProducts.str();
}

const std::vector<DigitalProduct> &ProductManager::getListOfDigitalProducts() const {
    return listOfDigitalProducts;
}

void ProductManager::setListOfDigitalProducts(const std::vector<DigitalProduct> &listOfDigitalProducts) {
    ProductManager::listOfDigitalProducts = listOfDigitalProducts;
}

const std::vector<PhysicalProduct> &ProductManager::getListOfPhysicalProducts() const {
    return listOfPhysicalProducts;
}

void ProductManager::setListOfPhysicalProducts(const std::vector<PhysicalProduct> &listOfPhysicalProducts) {
    ProductManager::listOfPhysicalProducts = listOfPhysicalProducts;
}
