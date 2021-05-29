//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//

#include "DigitalProduct.h"

DigitalProduct::DigitalProduct() {

}

DigitalProduct::DigitalProduct(const std::string &typeofProduct, const std::string &name, double price, int quantity,
                               const std::string &productSize) : Product(typeofProduct, name, price, quantity),
                                                                 productSize(productSize) {}

DigitalProduct::~DigitalProduct() {

}

std::string DigitalProduct::toString() {
    std::stringstream ss;
    ss << "Type of Product: " << getTypeofProduct() << std::endl;
    ss << Product::toString();
    ss << "Product Size: " << getProductSize() << std::endl;
    return ss.str();
}

const std::string &DigitalProduct::getProductSize() const {
    return productSize;
}

void DigitalProduct::setProductSize(const std::string &productSize) {
    DigitalProduct::productSize = productSize;
}

