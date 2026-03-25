#include <iostream>
#include <cstring>
#include <stdexcept>

class String {
private:
    char* data;
    size_t length;
    size_t capacity;

    void allocate(size_t cap) {
        capacity = cap;
        data = new char[capacity + 1];
        data[0] = '\0';
    }

public:
    // Default constructor
    String() : length(0) {
        allocate(15);
    }

    // Constructor from C-string
    String(const char* str) {
        length = std::strlen(str);
        allocate(length);
        std::strcpy(data, str);
    }

    // Copy constructor
    String(const String& other) : length(other.length) {
        allocate(other.capacity);
        std::strcpy(data, other.data);
    }

    // Move constructor
    String(String&& other) noexcept
        : data(other.data), length(other.length), capacity(other.capacity) {
        other.data = nullptr;
        other.length = 0;
        other.capacity = 0;
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Copy assignment
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            allocate(other.capacity);
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            capacity = other.capacity;
            other.data = nullptr;
            other.length = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Element access
    char& operator[](size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const char& operator[](size_t index) const {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Concatenation
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.allocate(result.length);
        std::strcpy(result.data, data);
        std::strcat(result.data, other.data);
        return result;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    // Comparison operators
    bool operator==(const String& other) const { return std::strcmp(data, other.data) == 0; }
    bool operator!=(const String& other) const { return !(*this == other); }
    bool operator< (const String& other) const { return std::strcmp(data, other.data) <  0; }
    bool operator> (const String& other) const { return other < *this; }
    bool operator<=(const String& other) const { return !(other < *this); }
    bool operator>=(const String& other) const { return !(*this < other); }

    // Accessors
    size_t size()    const { return length; }
    bool   empty()   const { return length == 0; }
    const char* c_str() const { return data; }

    // Substring
    String substr(size_t pos, size_t len) const {
        if (pos > length) throw std::out_of_range("Position out of range");
        len = std::min(len, length - pos);
        char* buf = new char[len + 1];
        std::strncpy(buf, data + pos, len);
        buf[len] = '\0';
        String result(buf);
        delete[] buf;
        return result;
    }

    // Find
    size_t find(const String& substr) const {
        const char* pos = std::strstr(data, substr.data);
        return pos ? static_cast<size_t>(pos - data) : npos;
    }

    // Clear
    void clear() {
        length = 0;
        data[0] = '\0';
    }

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        return os << s.data;
    }

    friend std::istream& operator>>(std::istream& is, String& s) {
        char buf[1024];
        is >> buf;
        s = String(buf);
        return is;
    }

    static const size_t npos = static_cast<size_t>(-1);
};