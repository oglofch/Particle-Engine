#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

const int INFINITY = -1;

class Semaphore 
{
private:
	int m_count;
	int m_max;

public:
	Semaphore(const int count, const int max);
	Semaphore(const int count);
	Semaphore();

	bool increment();
	bool decrement();

	void set(const int count, const int max);
	void setCount(const int count);
	void setMax(const int max);

	int getCount();
	int getMax();
};

#endif