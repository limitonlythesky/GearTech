//
// Created by Danel Baikadamova on 30.03.2023.
//

#ifndef GEARTECH_TESTGENERATOR_H
#define GEARTECH_TESTGENERATOR_H
#include <vector>

class TestGenerator {
private:
    int n;
    int size;
    std::vector <int> arr;
public:
    TestGenerator();
    void generateN();
    void generateSize();
    void generateArray();
    void scanToFile();

    int getN() const;

    int getSize() const;

    const std::vector<int> &getArr() const;
};


#endif //GEARTECH_TESTGENERATOR_H
