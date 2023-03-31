//
// Created by Danel Baikadamova on 30.03.2023.
//

#include "TestGenerator.h"
#include <vector>
#include <iostream>
#include <random>

TestGenerator::TestGenerator() {}

void TestGenerator::generateN(){
    std::vector <int> tmp;
    for(int i = 2; i <= size; ++i){
        tmp.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(tmp.begin(), tmp.end(), g);

    n = tmp[0];
}

void TestGenerator::generateSize(){
    std::vector <int> tmp;
    for(int i = 100; i <= 1000; ++i){
        tmp.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(tmp.begin(), tmp.end(), g);

    size = tmp[0];
}

void TestGenerator::generateArray(){
    std::vector <int> tmp;
    std::vector <int> tmparr;
    for(int i = 1; i <= 1000; ++i){
        tmp.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    while(size--) {
        std::shuffle(tmp.begin(), tmp.end(), g);
        tmparr.push_back(tmp[0]);
        //std::cout << tmp[0] << "\n";
    }
    arr = tmparr;
}

void TestGenerator::scanToFile(){
    freopen("input.txt", "w", stdout);
    std::cout << n << "\n";
    for(int i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << " ";
    }
    fclose (stdout);
}

int TestGenerator::getN() const {
    return n;
}

int TestGenerator::getSize() const {
    return size;
}

const std::vector<int> &TestGenerator::getArr() const {
    return arr;
}
