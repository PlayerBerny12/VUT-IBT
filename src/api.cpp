#include "api.h"

API::API() {
    std::cout << "Construing API" << std::endl;
}

int API::ping() {
    std::cout << "Pinging..." << std::endl;
    return 1;
}