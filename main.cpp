#include<iostream>
#include "ULL.h"

int main(){
    Ull ull;
    Ull a("95");
    Ull b("6");

    Ull sum = a + b;
    Ull dif = a - b;

    std::cout << "a : ";
    a.print();
    std::cout << std::endl;
    
    std::cout << "b : ";
    b.print();
    std::cout << std::endl;

    std::cout << "sum : ";
    ull.print(sum);
    std::cout << std::endl;

    std::cout << "diffrence : ";
    ull.print(dif);
    std::cout << std::endl;

    if(a == b) std::cout << "a is equals to b" << std::endl;
    else if(a < b) std::cout << "a is less than b" << std::endl;
    else std::cout << "a is greater than b" << std::endl;



    return 0;
}