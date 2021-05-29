//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//


#include "Product.h"

Product::Product() {
    name = "";
    price = 0;
    quantity = 0;
}

Product::Product(const std::string &typeOfProduct_, const std::string &name_, double price_, int quantity_) {
    typeofProduct = typeOfProduct_;
    name = name_;
    price = price_;
    quantity = quantity_;
}

Product::~Product() {

}

std::string Product::toString() {
    std::stringstream ss;
    ss << "Name: " << getName() << std::endl;
    ss << "Price: " << getPrice() << std::endl;
    ss << "Quantity: " << getQuantity() << std::endl;
    return ss.str();
}

const std::string &Product::getName() const {
    return name;
}

void Product::setName(const std::string &name) {
    Product::name = name;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    Product::price = price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

const std::string &Product::getTypeofProduct() const {
    return typeofProduct;
}

void Product::setTypeofProduct(const std::string &typeofProduct) {
    Product::typeofProduct = typeofProduct;
}
