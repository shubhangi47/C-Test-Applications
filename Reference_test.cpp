/*  Code to test reference value in C++ */
#include <iostream>
void func(int& , int );

int main(){
    int a = 20 ;
    std::cout<< " a =  " << a << " , &a =  " << &a << std::endl;
    func(a,a);
    return 0;
}
void func(int &ref, int value){
    std::cout<< " ref = " << ref << " , &ref =  " << &ref << std::endl;
    std::cout<< " value = " << value << " , &value =  " << &value << std::endl;
}

/*  a =  20 , &a =  0x7ffe10b27ba4  
    ref = 20 , &ref =  0x7ffe10b27ba4  // ref is a called by reference of a, thus same address 
    value = 20 , &value =  0x7ffe10b27b84  //value is called by value of a, creating copy of a, thus diff address  */
