// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 2.12.2020                                               ** //
// **   Module: Test API - code                                          ** //
// ************************************************************************ //

#include "../api.h"
#include "gtest/gtest.h"
#include <map>

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
    ASSERT_EQ(testAPI.ping(), 204);
}

TEST_F(APITest, auth_key_get) {
    map<string, string> header;
    ASSERT_EQ(testAPI.auth_key_get(&header), 200);
}

TEST_F(APITest, auth_key_post) {
    map<string, string> header;
    ASSERT_EQ(testAPI.auth_key_post("user", &header), 201);
}

TEST_F(APITest, auth_key_delete) {
    map<string, string> header;
    ASSERT_EQ(testAPI.auth_key_delete(&header), 204);
}

TEST_F(APITest, file_get) {
    map<string, string> header;
    ASSERT_EQ(testAPI.file_get(&header, nullptr), 200);
}

TEST_F(APITest, file_post) {
    map<string, string> header;
    ASSERT_EQ(testAPI.file_post(&header, nullptr), 201);
}

TEST_F(APITest, file_delete) {
    map<string, string> header;
    ASSERT_EQ(testAPI.file_delete(&header), 204);
}