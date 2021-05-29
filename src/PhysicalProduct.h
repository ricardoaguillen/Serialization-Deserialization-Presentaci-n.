//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//

#ifndef PROGRA2_PROJECT_1_ECHO_PHYSICALPRODUCT_H
#define PROGRA2_PROJECT_1_ECHO_PHYSICALPRODUCT_H

#include "Product.h"

class PhysicalProduct : public Product, public std::error_code {
private:
    std::string materialComposition;
public:
    PhysicalProduct();

    PhysicalProduct(const std::string &typeofProduct, const std::string &name, double price, int quantity,
                    const std::string &materialComposition);

    ~PhysicalProduct();

    std::string toString();

    const std::string &getMaterialComposition() const;

    void setMaterialComposition(const std::string &materialComposition);

};


#endif //PROGRA2_PROJECT_1_ECHO_PHYSICALPRODUCT_H
