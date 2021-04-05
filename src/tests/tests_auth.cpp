// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 2.12.2020                                               ** //
// **   Module: Tests API Auth - code                                    ** //
// ************************************************************************ //

#include "tests.h"
#include <map>

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
