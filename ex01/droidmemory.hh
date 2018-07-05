#ifndef DROIDMEMORY_H_
#define DROIDMEMORY_H_

#include <iostream>

class DroidMemory
{
public:
    DroidMemory();
    virtual ~DroidMemory();

    size_t getFingerPrint() const;
    void setFingerPrint(size_t const value);
    size_t getExp() const;
    void setExp(size_t const value);

    DroidMemory& operator<<(DroidMemory const& other);
    DroidMemory& operator>>(DroidMemory& other) const;
    DroidMemory& operator+=(DroidMemory const& other);
    DroidMemory& operator+=(size_t const& val);
    DroidMemory operator+(DroidMemory const& other) const;
    DroidMemory operator+(size_t const val) const;
private:
    size_t _fingerPrint;
    size_t _exp;
};

std::ostream& operator<<(std::ostream& stream, DroidMemory const& memory);


#endif
