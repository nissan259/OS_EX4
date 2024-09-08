// Singleton.hpp
#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <pthread.h>

// Abstract Singleton Class
class Singleton {
protected:
    static pthread_mutex_t mutex;

    // Protected constructor to prevent instantiation
    Singleton() {}

public:
    virtual ~Singleton() {}

    // Pure virtual method for subclasses to implement
    virtual void doSomething() = 0;

    // Locking and unlocking methods
    static void lock();
    static void unlock();
};

// Derived Singleton Class
class MySingleton : public Singleton {
private:
    static MySingleton* instance;

    // Private constructor to enforce Singleton pattern
    MySingleton() {}

public:
    static MySingleton* getInstance();
    void doSomething() override;
};

#endif
