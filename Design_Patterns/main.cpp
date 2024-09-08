// main.cpp
#include "Singleton.hpp"
#include "Guard.hpp"
#include <iostream>

int main() {
    // Example usage of the Guard class
    pthread_mutex_t test_mutex = PTHREAD_MUTEX_INITIALIZER;
    {
        Guard guard(test_mutex);
        std::cout << "Mutex is locked in scope" << std::endl;
    }
    std::cout << "Mutex is unlocked after scope" << std::endl;

    // Example usage of the Singleton class
    MySingleton* singleton = MySingleton::getInstance();
    singleton->doSomething();

    return 0;
}
//to run the porgram use the following command
//./main