#ifndef STRING_H_
#define STRING_H_

#include <cstddef>

namespace project {

    class String {
    public:
        String();
        ~String();

        bool Fitted() const;
        char* GetWhole() const;
        void Insert(char ch);
        void Insert(const char* str);
        void Reset();

        const char* GetStatic() const;
        const char* GetString() const;

        bool operator<(const String &rhs) const;

        bool operator>(const String &rhs) const;

        bool operator<=(const String &rhs) const;

        bool operator>=(const String &rhs) const;

        bool operator==(const String &rhs) const;

        bool operator!=(const String &rhs) const;

    private:
        char static_[16];

        char* dynamic_;
        size_t size_;
        size_t capacity_;
    };

}  // namespace project

#endif  // STRING_H_
