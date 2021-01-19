// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 17.11.2020                                              ** //
// **   Module: Main - code                                              ** //
// ************************************************************************ //

#include "api.h"

int main() {
    // Global libcurl initialisation 
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Creating API class
    auto api = API("https://bf27a80b-c291-46b2-8c4c-fe616fa3a822.mock.pstmn.io/");
    
    // Testing API call
    map<string, string> xd;
    auto res = api.auth_key_post("asd", &xd);
    cout << res;
    //---------------------//
    
    // Global libcurl cleanup 
    curl_global_cleanup();

    return 0;
}
