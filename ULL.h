#ifndef ULL_H
#define ULL_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


#define zero Ull("0")
#define one Ull("11")

class Ull{
private:
    Ull subtract(Ull num);
    Ull add(Ull num);
    bool is_greater(Ull num);
    bool is_lesser(Ull num);
    bool is_greater_or_equal(Ull num);
    bool is_lesser_or_equal(Ull num);
    bool is_negative;
    
public:
    Ull();
    Ull(std::string str);
    
    std::string val;

    void print();
    void print(Ull num);

    void operator=(Ull num);
    bool operator==(Ull num);
    bool operator!=(Ull num);
    bool operator>(Ull num);
    bool operator<(Ull num);
    bool operator>=(Ull num);
    bool operator<=(Ull num);
    Ull operator+(Ull num);
    Ull operator-(Ull num);
};

#endif