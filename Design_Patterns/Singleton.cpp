// Singleton.cpp
#include "Singleton.hpp"
#include <iostream>

// Static members initialization
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
MySingleton* MySingleton::instance = nullptr;

// Singleton lock method
void Singleton::lock() {
    pthread_mutex_lock(&mutex);
}

// Singleton unlock method
void Singleton::unlock() {
    pthread_mutex_unlock(&mutex);
}

// Implementation of getInstance() for MySingleton
MySingleton* MySingleton::getInstance() {
    if (instance == nullptr) {
        lock();  // Lock the mutex
        if (instance == nullptr) {
            instance = new MySingleton();  // Create the instance
        }
        unlock();  // Unlock the mutex
    }
    return instance;
}

// Implementation of the doSomething method
void MySingleton::doSomething() {
    std::cout << "MySingleton is doing something!" << std::endl;
}
