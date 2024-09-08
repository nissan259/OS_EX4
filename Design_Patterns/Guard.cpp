// Guard.cpp
#include "Guard.hpp"

// Constructor: locks the mutex
Guard::Guard(pthread_mutex_t& mutex) : m_mutex(mutex) {
    pthread_mutex_lock(&m_mutex);
}

// Destructor: unlocks the mutex
Guard::~Guard() {
    pthread_mutex_unlock(&m_mutex);
}
