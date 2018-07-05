#ifndef DROIDMEMORY_H_
#define DROIDMEMORY_H_

#include <iostream>

class DroidMemory
{
	public:
	DroidMemory();
	~DroidMemory();
	size_t getFingerPrint() const;
	void setFingerPrint(size_t);
	size_t getExp() const;
	void setExp(size_t);

	static void addXor(DroidMemory &dest, DroidMemory const &memory1,
		DroidMemory const &memory2);

	DroidMemory &operator<<(DroidMemory const &memory);
	DroidMemory const  &operator>>(DroidMemory &memory) const;

	DroidMemory &operator+=(DroidMemory const &memory);
	DroidMemory &operator+=(size_t);

	DroidMemory &operator+(DroidMemory const &memory);
	DroidMemory &operator+(size_t) const;

	bool operator==(DroidMemory const &memory) const;
	bool operator!=(DroidMemory const &memory) const;

	bool operator>(DroidMemory const &memory) const;
	bool operator<(DroidMemory const &memory) const;

	bool operator>=(DroidMemory const &memory) const;
	bool operator<=(DroidMemory const &memory) const;

	bool operator>(const size_t) const;
	bool operator<(const size_t) const;

	bool operator>=(const size_t) const;
	bool operator<=(const size_t) const;

	private:
	size_t _FingerPrint;
	size_t _Exp;
};

std::ostream &operator<<(std::ostream &s, const DroidMemory &droid);


#endif
