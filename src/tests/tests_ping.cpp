// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                    ** //
// **   University: VUT FIT Brno                                          ** //
// **   Authors: Jan Bernard                                              ** //
// **   Created: 2.12.2020                                                ** //
// **   Module: Tests API Ping - code                                     ** //
// ************************************************************************* //

#include "tests.h"

/*
 * Testing ping function. If this test fails, other API tests 
 * will probably fails too.
 */
TEST_F(APITest, ping) {
    ASSERT_EQ(testAPI.ping(), 204);
}
