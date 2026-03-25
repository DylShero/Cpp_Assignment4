/**
 * @file String.h
 * @brief Skeleton code for Assignment 4 for 5614
 * @author R. Morrin
 * @version 1.0
 * @date 2026-03-22
 */
#ifndef STRING_H_XGOYUU6M
#define STRING_H_XGOYUU6M
#include <cstring>
#include <iostream>
#include <print>

namespace HPC
{
    class String
    {
        public:
            // First constructor
            String(std::size_t in);

            // Second Constructor
            explicit String(const char *str);

            // Copy Ctor
            String(const String& in);

            // Move Ctor
            String(String&& in) noexcept;

            // Copy assign
            String& operator=(const String& rhs);

            // Move assign
            String& operator=(String&& rhs) noexcept;

            // Destructor
            ~String() noexcept;

            // TODO. Write these inline
            const char* c_str() noexcept;
            std::size_t length() const noexcept;

            /// TODO This is for Q4
            // String& operator+(const String& rhs);


        private:
            std::size_t len;
            std::size_t capacity;
            char *data;

    };

    /// TODO: Write specified member function definitions here

    // Q4:
    // std::ostream& operator<<(std::ostream& os, const String& str);

    //Constructor 1 implementation
String::String(std::size_t in){
    std::print("Constructing String object of size {} \n", in);
}

//Constructor 2 implementation
explicit String::String(const char *str){
    len = std::strlen(str) + 1; //+1 to account for null character
    capacity = len;

    data = new char[len];

    std::strcpy(data, str);

    std::print("Constructing {} String object of size {}\n", data, len);
}

//Copy Constructor
String::String(const String& in){
    std::print("Calling copy constructor\n");
    String copy = new String(in.data);
}

//Move constructor
String::String(String&& in) noexcept{
    std::print("Calling move contructor\n");
}

//Copy assign
String::String& operator=(const String& rhs){
    std::print("Calling copy assignment operator\n");
}

//Move assign
String::String& operator=(String&& rhs) noexcept{
    std::print("Calling move assignment operator\n");
}

//Destructor
String::~String() noexcept{
    delete[] data;
    std::print("Deconstructor called on String object");
}


} // END of HPC Namespace

////////////////////////////////////////////////////////////////


// TODO: Q4 Write formatter for std::print here


#endif /* end of include guard: MYSTRING_H_XGOYUU6M */

