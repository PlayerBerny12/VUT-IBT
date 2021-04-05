// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 2.12.2020                                               ** //
// **   Module: Tests API File - code                                    ** //
// ************************************************************************ //

#include "tests.h"
#include <map>

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