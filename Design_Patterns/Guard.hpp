// Guard.hpp
#ifndef GUARD_HPP
#define GUARD_HPP

#include <pthread.h>

class Guard {
private:
    pthread_mutex_t& m_mutex;

public:
    Guard(pthread_mutex_t& mutex); // Constructor
    ~Guard(); // Destructor
};

#endif
