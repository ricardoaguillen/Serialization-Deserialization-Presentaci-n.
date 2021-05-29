//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//

#include "PhysicalProduct.h"

PhysicalProduct::PhysicalProduct() {

}

PhysicalProduct::PhysicalProduct(const std::string &typeofProduct, const std::string &name, double price, int quantity,
                                 const std::string &materialComposition_) : Product(typeofProduct, name, price,
                                                                                    quantity),
                                                                            materialComposition(materialComposition_) {}

PhysicalProduct::~PhysicalProduct() {

}

std::string PhysicalProduct::toString() {
    std::stringstream ss;
    ss << "Type of Product: " << getTypeofProduct() << std::endl;
    ss << Product::toString();
    ss << "Material Composition: " << getMaterialComposition() << std::endl << std::endl;
    return ss.str();
}

const std::string &PhysicalProduct::getMaterialComposition() const {
    return materialComposition;
}

void PhysicalProduct::setMaterialComposition(const std::string &materialComposition) {
    PhysicalProduct::materialComposition = materialComposition;
}


