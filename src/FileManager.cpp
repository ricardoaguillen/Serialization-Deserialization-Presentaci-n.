//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//

#include "FileManager.h"

#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>

void to_json(json &_json, const ProductManager &listOfProducts) {
    json jProduct;
    auto jProductList = json::array();

    for (const DigitalProduct &product : listOfProducts.getListOfDigitalProducts()) {
        jProduct["name"] = product.getName();
        jProduct["price"] = product.getPrice();
        jProduct["quantity"] = product.getQuantity();
        jProduct["productSize"] = product.getProductSize();
        jProduct["typeOfProduct"] = product.getTypeofProduct();
        jProductList.push_back(jProduct);
    }

    for (const PhysicalProduct &product : listOfProducts.getListOfPhysicalProducts()) {

        jProduct["name"] = product.getName();
        jProduct["price"] = product.getPrice();
        jProduct["quantity"] = product.getQuantity();
        jProduct["materialComposition"] = product.getMaterialComposition();
        jProduct["typeOfProduct"] = product.getTypeofProduct();
        jProductList.push_back(jProduct);
    }
    _json["Products"] = jProductList;
}

void from_json(const json &_json, ProductManager &list_) {
    ProductManager listOfProducts;
    json productData = _json["Products"];

    // this method is necessary to deserialize tha information from the vector
    for (auto &data : productData) {
        if (data.at("typeOfProduct").get<std::string>() != "Digital") {
            PhysicalProduct physicalProduct;
            physicalProduct.setName(data.at("name").get<std::string>());
            physicalProduct.setPrice(data.at("price").get<double>());
            physicalProduct.setQuantity(data.at("quantity").get<int>());
            physicalProduct.setMaterialComposition(data.at("materialComposition").get<std::string>());
            physicalProduct.setTypeofProduct(data.at("typeOfProduct").get<std::string>());
            listOfProducts.addPhysicalProduct(physicalProduct);
        }

        if (data.at("typeOfProduct").get<std::string>() != "Physical") {
            DigitalProduct digitalProduct;
            digitalProduct.setName(data.at("name").get<std::string>());
            digitalProduct.setPrice(data.at("price").get<double>());
            digitalProduct.setQuantity(data.at("quantity").get<int>());
            digitalProduct.setProductSize(data.at("productSize").get<std::string>());
            digitalProduct.setTypeofProduct(data.at("typeOfProduct").get<std::string>());
            listOfProducts.addDigitalProduct(digitalProduct);
        }
    }
    list_.setListOfPhysicalProducts(listOfProducts.getListOfPhysicalProducts());
    list_.setListOfDigitalProducts(listOfProducts.getListOfDigitalProducts());

}

string FileManager::serialize(ProductManager &_productList) {
    json jsonData(_productList);
    string jsonArray = jsonData.dump(4);
    return jsonArray;
}

ProductManager FileManager::deserialize(const string &_data) {
    json jsonData = json::parse(_data);
    ProductManager personList = jsonData;
    return personList;
}

void FileManager::save(const string &jsonData, const string &filename) {
    std::ofstream file(filename, std::ofstream::out);
    file << jsonData;
    file.close();
}

string FileManager::read(const string &filename) {
    std::string txtContent;

    try {
        std::ifstream file(filename);
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        stringstream buffer;
        buffer << file.rdbuf();
        std::string fileContent(buffer.str());
        txtContent = fileContent;
    }

    catch (std::ifstream::failure e) {
        throw std::runtime_error("Exception opening/reading/closing file");
    }

    return txtContent;
}