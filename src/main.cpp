#include <stdio.h>
#include "api.h"

int main(int argc, char **argv) {
    auto api = API();
    api.ping();

    return 0;
}