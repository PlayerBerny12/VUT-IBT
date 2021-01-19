#include "../api.h"
#include "gtest/gtest.h"

class APITest : public ::testing::Test {
protected:
    APITest() : testAPI("https://bf27a80b-c291-46b2-8c4c-fe616fa3a822.mock.pstmn.io/")
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

TEST_F(APITest, ping) {
    ASSERT_EQ(testAPI.ping(), 0);
}