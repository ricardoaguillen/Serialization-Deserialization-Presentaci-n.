//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//


#ifndef PRODUCTMANAGER_PRODUCT_H
#define PRODUCTMANAGER_PRODUCT_H

#include <string>
#include <sstream>

class Product {
private:
    std::string typeofProduct;
    std::string name;
    double price;
    int quantity;
public:
    Product();

    Product(const std::string &, const std::string &, double, int);

    ~Product();

    virtual std::string toString();

    const std::string &getName() const;

    void setName(const std::string &name);

    double getPrice() const;

    void setPrice(double price);

    int getQuantity() const;

    void setQuantity(int quantity);

    const std::string &getTypeofProduct() const;

    void setTypeofProduct(const std::string &typeofProduct);

};


#endif //PRODUCTMANAGER_PRODUCT_H
