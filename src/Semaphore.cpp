#include "Semaphore.h"

Semaphore::Semaphore(const int count, const int max) {
	m_count = count;
	m_max = max;
}

Semaphore::Semaphore(const int count) {
	m_count = count;
	m_max = INFINITY;
}

Semaphore::Semaphore() {
	m_count = 0;
	m_max = INFINITY;
}

bool Semaphore::increment() {
	if ((m_count < m_max || m_max == INFINITY) && m_count != INFINITY) {
		++m_count;
		return true;
	}
	return false;
}

bool Semaphore::decrement() {
	if (m_count > 0 && m_count != INFINITY) {
		--m_count;
		return true;
	}
	return false;
}

void Semaphore::set(const int count, const int max) {
	m_count = count;
	m_max = max;
}

void Semaphore::setCount(const int count) {
	m_count = count;
}

void Semaphore::setMax(const int max) {
	m_max = max;
}

int Semaphore::getCount() {
	return m_count;
}

int Semaphore::getMax() {
	return m_max;
}