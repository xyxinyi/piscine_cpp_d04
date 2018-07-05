#include <iostream>
#include "droid.hh"

Droid::Droid(std::string const& id) : _id(id), _energy(50), _attack(25),
    _thoughness(15), _status(NULL)
{
    _status = new std::string("Standing by");
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const& other) : _id(other._id), _energy(other._energy),
    _attack(other._attack), _thoughness(other._thoughness), _status(NULL)
{
    if (other._status)
    {
        if (_status)
            delete _status;
        _status = new std::string(*other._status);
    }
    else if (_status)
    {
        delete _status;
        _status = NULL;
    }
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

Droid& Droid::operator=(Droid const& other)
{
    if (this == &other)
        return *this;
    
    _id = other._id;
    _energy = other._energy;
    if (other._status)
    {
        if (_status)
            *_status = *other._status;
        else
            _status = new std::string(*other._status);
    }
    else if (_status)
    {
        delete _status;
        _status = NULL;
    }
    return *this;
}

std::string const& Droid::getId() const
{
    return _id;
}

void Droid::setId(std::string const& id)
{
    _id = id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

void Droid::setEnergy(size_t const val)
{
    _energy = val;
    if (_energy> 100)
        _energy = 100;
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getToughness() const
{
    return _thoughness;
}

size_t Droid::getThoughness() const
{
    return _thoughness;
}

std::string const* Droid::getStatus() const
{
    return _status;
}

void Droid::setStatus(std::string* val)
{
    if (_status)
        delete _status;
    _status = val;
}

void Droid::setStatus(std::string const& val)
{
    if (_status)
        *_status = val;
    else
        _status = new std::string(val);
}

bool Droid::operator==(Droid const& other) const
{
    return getAttack() == other.getAttack() && getToughness() == other.getToughness() && getId() == other.getId() && getStatus() && other.getStatus() && *(getStatus()) == *(other.getStatus());
}

bool Droid::operator!=(Droid const& other) const
{
    return !(getAttack() == other.getAttack() && getToughness() == other.getToughness() && getId() == other.getId() && getStatus() && other.getStatus() && *(getStatus()) == *(other.getStatus()));
}

Droid& operator<<(Droid& droid, size_t& value)
{
    if (droid.getEnergy() + value > 100)
    {
        value -= 100 - droid.getEnergy();
        droid.setEnergy(100);
    }
    else
    {
        droid.setEnergy(droid.getEnergy() + value);
        value = 0;
    }
    return droid;
}

std::ostream& operator<<(std::ostream& stream, Droid const& droid)
{
    stream << "Droid '" << droid.getId() << "', " << (droid.getStatus() ? *droid.getStatus() : "") << ", " << droid.getEnergy();
    return stream;
}
