//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//


#ifndef PROGRA2_PROJECT_1_ECHO_DIGITALPRODUCT_H
#define PROGRA2_PROJECT_1_ECHO_DIGITALPRODUCT_H

#include "Product.h"

class DigitalProduct : public Product {
private:
    std::string productSize;
public:
    DigitalProduct();

    DigitalProduct(const std::string &typeofProduct, const std::string &name, double price, int quantity,
                   const std::string &productSize);


    ~DigitalProduct();

    std::string toString();

    const std::string &getProductSize() const;

    void setProductSize(const std::string &productSize);
};


#endif //PROGRA2_PROJECT_1_ECHO_DIGITALPRODUCT_H
