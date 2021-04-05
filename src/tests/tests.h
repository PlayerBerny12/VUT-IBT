// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 4.4.2021                                                ** //
// **   Module: Test Main - header                                       ** //
// ************************************************************************ //

#include "gtest/gtest.h"
#include "../api.h"

class APITest : public ::testing::Test {
protected:
    APITest() : testAPI("https://e526bc93-da2e-4001-94a3-d9fa02033458.mock.pstmn.io/")
    {
        // You can do set-up work for each test here.                        
    }

    ~APITest() override
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    API testAPI;
};