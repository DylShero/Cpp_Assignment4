/**
 * @file String.cc
 * @brief 
 * @author R. Morrin
 * @version 1.0
 * @date 2026-03-22
 */
#include <print>
#include "String.h"


void f1(HPC::String X){
    std::println("In f1 {}", X.c_str());
}

//Constructor 1 implementation
HPC::String::String(std::size_t in){
    std::print("Constructing String object of size {} \n", in);
}

//Constructor 2 implementation
explicit HPC::String::String(const char *str){
    len = std::strlen(str) + 1; //+1 to account for null character
    capacity = len;

    data = new char[len];

    std::strcpy(data, str);

    std::print("Constructing {} String object of size {}\n", data, len);
}

//Copy Constructor
HPC::String::String(const String& in){
    std::print("Calling copy constructor\n");
    String copy = new String(in.data);
}

//Move constructor
HPC::String::String(String&& in) noexcept{
    std::print("Calling move contructor\n");
}

//Copy assign
HPC::String::String& operator=(const String& rhs){
    std::print("Calling copy assignment operator\n");
}

//Move assign
HPC::String::String& operator=(String&& rhs) noexcept{
    std::print("Calling move assignment operator\n");
}

//Destructor
HPC::String::~String() noexcept{
    delete[] data;
    std::print("Deconstructor called on String object");
}


int main()
{
    HPC::String A{10}; 
    HPC::String B{"HPC"}; 
    HPC::String C{"WORLD"}; 
    const HPC::String D{std::move(B)};
    A = D;

    /// TODO: Q3: Uncomment the below after completing the code for Q2
    //            The purpose of these lines are to allow you to answer the 
    //            written question. When you have answered that question, 
    //            you can comment them out again.

    /*
       f1(12);
       f1(std::size_t{13});
       f1("HELLO");   
       f1(HPC::String{"WORLD"});
       */

    // TODO: Q3  Uncomment these two lines after completing Q2.
    // std::cout << "\n\n---\n" << A.c_str() << "\n---\n\n";
    // std::cout << "\n\n---\n" << C.c_str() << "\n---\n\n";


    /// TODO: Q4 Uncomment this after overloading operator<<
    // std::cout << "cout:\t" << A << std::endl;	
    //  TODO: Q4 Uncomment after overloading operator+
    // std::cout << "A+C: " << A+C << '\n';
    /// TODO: Q4 Uncomment this after specialising formatter
    // std::println("print:\t{}", A);


    return 0;
}
