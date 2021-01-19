// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 21.11.2020                                              ** //
// **   Module: API - header                                             ** //
// ************************************************************************ //

#ifndef VDU_API_H
#define VDU_API_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <curl/curl.h>

#include "string.h"

using namespace std;

class API
{
private:
    const string base_url;
    string x_api_key;
    CURL *curl;

    static size_t header_parse(char *buffer, size_t size, size_t nitems, void *userdata); 
    size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata); 

public:    
    API(const string url);
    ~API();
    int ping();
    int auth_key_get(map<string, string> *header_values);
    int auth_key_post(string from, map<string, string> *header_values);
    int auth_key_delete(map<string, string> *header_values); 
    int file_get(map<string, string> *header_values, char *content);
    int file_post(map<string, string> *header_values, char *content);
    int file_delete(map<string, string> *header_values);
};

#endif