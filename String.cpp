#include "String.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace project {

    String::String() : dynamic_(nullptr), size_(0), capacity_(1) {
        static_[0] = '\0';
        dynamic_ = static_cast<char*>(malloc(sizeof(*dynamic_) * capacity_));
        dynamic_[0] = '\0';
    }

    String::~String() {
         free(dynamic_);
    }

    bool String::Fitted() const {
        return size_ == 0;
    }

    char* String::GetWhole() const {
        char* ret = new char[strlen(static_) + strlen(dynamic_) + 1];
        sprintf(ret, "%s%s", static_, dynamic_);
        return ret;
    }

    void String::Insert(char ch) {
        size_t static_size = strlen(static_);
        if (static_size + 1 <= sizeof(static_) - 1) {
            static_[static_size] = ch;
            static_[static_size + 1] = '\0';
            ++static_size;
        } else {
            if (size_ + 1 == capacity_) {
                capacity_ *= 2;
                dynamic_ = static_cast<char*>(
                        realloc(dynamic_, sizeof(*dynamic_) * capacity_));
            }
            dynamic_[size_] = ch;
            dynamic_[size_ + 1] = '\0';
            ++size_;
        }
    }

    void String::Insert(const char* str) {
        size_t static_size = strlen(static_);
        for (size_t i = 0; str[i] != '\0'; ++i) {
            if (static_size + 1 <= sizeof(static_) - 1) {
                static_[static_size] = str[i];
                static_[static_size + 1] = '\0';
                ++static_size;
            } else {
                if (size_ + 1 == capacity_) {
                    capacity_ *= 2;
                    dynamic_ = static_cast<char*>(
                            realloc(dynamic_, sizeof(*dynamic_) * capacity_));
                }
                dynamic_[size_] = str[i];
                dynamic_[size_ + 1] = '\0';
                ++size_;
            }
        }
    }

    const char *String::GetString() const
    {
        if(Fitted())
            return GetStatic();
        else
            return GetWhole();
    }

    void String::Reset() {
        static_[0] = '\0';
        delete[] dynamic_;
        size_ = 0;
        capacity_ = 1;
        dynamic_ = static_cast<char*>(malloc(sizeof(*dynamic_) * capacity_));
        dynamic_[0] = '\0';
    }

    const char* String::GetStatic() const {
        return static_;
    }

    bool String::operator==(const String &rhs) const
    {
        return !strcmp(GetString(), rhs.GetString());
    }

    bool String::operator!=(const String &rhs) const
    {
        return !(rhs == *this);
    }

    bool String::operator<(const String &rhs) const
    {
        if(strcmp(GetString(), rhs.GetString()) < 0)
            return true;
        else
            return false;
    }

    bool String::operator>(const String &rhs) const
    {
        return rhs < *this;
    }

    bool String::operator<=(const String &rhs) const
    {
        return !(rhs < *this);
    }

    bool String::operator>=(const String &rhs) const
    {
        return !(*this < rhs);
    }

}  // namespace project
