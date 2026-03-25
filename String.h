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
            const char* c_str() const noexcept{
                if(this->data == nullptr){ //Check these isnt no data and if so return black char array
                    return "";
                }
                return this->data; 
            }
            std::size_t length() const noexcept{
                return this->len;
            }

            /// TODO This is for Q4
            // String& operator+(const String& rhs);


        private:
            std::size_t len;
            std::size_t capacity;
            char *data;

    };

    /// TODO: Write specified member function definitions here

    // Q4:
    std::ostream& operator<<(std::ostream& os, const String& str){
        os << str.c_str();

        return os;
    }

    String operator+(const String& a, const String& b){
        std::size_t aSize = std::strlen(a.c_str()); //Get size of a and b
        std::size_t bSize = std::strlen(b.c_str());
        char* temp = new char[aSize + bSize + 1]; //Plus one to deal with terminating character

        std::strcpy(temp, a.c_str()); //Copy a into temp
        std::strcat(temp, b.c_str()); //Concatenate b onto temp

        String combined(temp); //Create new combined object

        delete[] temp; //Free memory

        return combined;
    }

    //Constructor 1 implementation
String::String(std::size_t in){
    len = in;
    capacity = in;
    data = new char[capacity];

    if (capacity > 0) { //To deal with random data showing up on objects of size 0
        data[0] = '\0'; 
    }
    std::print("Constructing String object of size {} \n", in);
}

//Constructor 2 implementation
String::String(const char *str){
    len = std::strlen(str) + 1; //+1 to account for null character
    capacity = len;

    data = new char[len];

    std::memcpy(data, str, len);

    std::print("Constructing {} String object of size {}\n", data, len);
}

//Copy Constructor
String::String(const String& in){
    std::print("Calling copy constructor\n");
    
    this->len = in.len; //This is a pointer to the new object being contructed
    this->capacity = in.capacity;
    this->data = new char[this->len];
    std::memcpy(this->data, in.data, this->len);
    
}

//Move constructor
String::String(String&& in) noexcept{
    std::print("Calling move contructor\n");

    this->data = in.data;
    this->len = in.len;
    this->capacity = in.capacity;

    in.data = nullptr;
    in.len = 0;
    in.capacity = 0;
    
}

//Copy assign
String& String::operator=(const String& rhs){
    std::print("Calling copy assignment operator\n");
    if(this == &rhs){
        std::print("Trying to copy itself\n");
        return *this;
    }

    if(this->capacity < rhs.len){ //Check if enough data memory if not allocate new data memory for input size.
        delete[] data;
        this->data = new char[rhs.capacity];
    }

    this->len = rhs.len;
    this->capacity = rhs.capacity;
    std::memcpy(this->data, rhs.data, this->len);

    return *this;

}

//Move assign
String& String::operator=(String&& rhs) noexcept{
    std::print("Calling move assignment operator\n");

    if (this == &rhs) {//Check for moving to itself
        return *this; 
    }

    delete[] this->data; //Delete existing data in object we want to move data into

    this->capacity = rhs.capacity; //Change to new len and capacity
    this->len = rhs.len;

    this->data = rhs.data;

    rhs.data = nullptr; //Set to nullptr/0 the old no longer need object.
    rhs.len = 0;
    rhs.capacity = 0;

    return *this;
}

//Destructor
String::~String() noexcept{
    delete[] data;
    std::print("Deconstructor called on String object\n");
}


} // END of HPC Namespace

////////////////////////////////////////////////////////////////


// TODO: Q4 Write formatter for std::print here
template <class CharT>
struct std::formatter<HPC::String, CharT>{

    const auto parse(std::basic_format_parse_context<CharT>& ctx){
        return ctx.begin();
    }

    template <class FormatContext>
        auto format(const HPC::String& str, FormatContext& ctx) const {
            return std::format_to(ctx.out(), "{}", str.c_str());
        }

}


#endif /* end of include guard: MYSTRING_H_XGOYUU6M */

