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
    auto api = API("https://e526bc93-da2e-4001-94a3-d9fa02033458.mock.pstmn.io/");    
    
    map<string, string> header_values;
    char content[10000];
    
    // Testing API call #1
    api.request_header = curl_slist_append(api.request_header, "x-mock-response-code: 200");
    auto res = api.auth_key_get(&header_values);
    
    cout << res << endl;
    for (auto&& [key,val] : header_values) {
        cout << key << ": " << val  << ", ";
    }
    cout << endl << endl;
    header_values.clear();
    //---------------------//

    // Testing API call #2
    api.request_header = curl_slist_append(api.request_header, "x-mock-response-code: 201");
    res = api.auth_key_post("", &header_values);
    
    cout << res << endl;
    for (auto&& [key,val] : header_values) {
        cout << key << ": " << val  << ", ";
    }
    cout << endl << endl;
    header_values.clear();
    //---------------------//
    
    // Testing API call #3
    api.request_header = curl_slist_append(api.request_header, "x-mock-response-code: 204");
    res = api.auth_key_delete(&header_values);
    
    cout << res << endl;
    for (auto&& [key,val] : header_values) {
        cout << key << ": " << val  << ", ";
    }
    cout << endl << endl;
    header_values.clear();
    //---------------------//

    // Testing API call #4    
    api.request_header = curl_slist_append(api.request_header, "x-mock-response-code: 200");
    res = api.file_get(&header_values, content);
    
    cout << res << endl;
    for (auto&& [key,val] : header_values) {
        cout << key << ": " << val  << ", ";
    }
    cout << endl << endl;
    header_values.clear();
    //---------------------//

    // Testing API call #5    
    api.request_header = curl_slist_append(api.request_header, "x-mock-response-code: 201");
    res = api.file_post(&header_values, content);
    
    cout << res << endl;
    for (auto&& [key,val] : header_values) {
        cout << key << ": " << val  << ", ";
    }
    cout << endl << endl;
    header_values.clear();
    //---------------------//

    // Testing API call #6
    api.request_header = curl_slist_append(api.request_header, "x-mock-response-code: 204");
    res = api.file_delete(&header_values);
    
    cout << res << endl;
    for (auto&& [key,val] : header_values) {
        cout << key << ": " << val  << ", ";
    }
    cout << endl << endl;
    header_values.clear();
    //---------------------//

    // Global libcurl cleanup 
    curl_global_cleanup();

    return 0;
}
