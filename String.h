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

} // END of HPC Namespace

////////////////////////////////////////////////////////////////


// TODO: Q4 Write formatter for std::print here


#endif /* end of include guard: MYSTRING_H_XGOYUU6M */

