// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 21.11.2020                                              ** //
// **   Module: API - code                                               ** //
// ************************************************************************ //

#include "api.h"

size_t API::header_parse(char *buffer, size_t size, size_t nitems, void *userdata)
{    
    map<string, string> *header_values = (map<string, string> *)userdata;
    string header_line;
    string header_key;
    string header_value;
    istringstream stream(buffer);
    
    // Load one line from header
    getline(stream, header_line);

    size_t index = header_line.find(':', 0);

    if(index != std::string::npos) {
        // Create substrings
        header_key = header_line.substr(0, index);
        header_value = header_line.substr(index + 1);

        // Trim values  
        trim(header_key);
        trim(header_value);
              
        // Insert trim values to map
        header_values->insert({ header_key, header_value });        
    }  

    return nitems * size;
}

size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata)
{
    cout << buffer << endl;
    return nitems * size;
}

API::API(string url) : base_url(url)
{
    this->curl = curl_easy_init();

    if (this->curl == nullptr)
    {
        throw runtime_error("Creating CURL easy session failed.");
    }
}

API::~API()
{
    curl_easy_cleanup(this->curl);
}

/**
 * To test a connection (to do a ping).
 */
int API::ping()
{
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "ping").c_str());

    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}

/**
 * Authorization token (key) renewal.
 */
int API::auth_key_get(map<string, string> *header_values) {
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "auth/key").c_str());    
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, header_values);    
    curl_easy_setopt(this->curl, CURLOPT_HEADERFUNCTION, header_parse);
    
    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);   

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}

/**
 * Generate a new authorization token (key) for the first time.
 */
int API::auth_key_post(string from, map<string, string> *header_values)
{   
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "auth/key").c_str());    
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, header_values);    
    curl_easy_setopt(this->curl, CURLOPT_HEADERFUNCTION, header_parse);    
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    
    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);   

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}

/**
 * Authorization token (key) invalidation.
 */
int API::auth_key_delete(map<string, string> *header_values) {
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "auth/key").c_str());    
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, header_values);    
    curl_easy_setopt(this->curl, CURLOPT_HEADERFUNCTION, header_parse);    
    curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    
    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);   

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}

/**
 * Get the content of a file available by the given access token.
 */
int API::file_get(map<string, string> *header_values, char *content) {
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "file/" + this->x_api_key).c_str());    
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, header_values);    
    curl_easy_setopt(this->curl, CURLOPT_HEADERFUNCTION, header_parse);        
    
    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);   

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}

/**
 * Post/upload the content of a file available by the given access token.
 */
int API::file_post(map<string, string> *header_values, char *content) { 
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "file/" + this->x_api_key).c_str());    
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, header_values);    
    curl_easy_setopt(this->curl, CURLOPT_HEADERFUNCTION, header_parse);      
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");  
    
    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);   

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}

/**
 * To invalid the given file access token.
 */
int API::file_delete(map<string, string> *header_values) {
    // set parameters
    curl_easy_setopt(this->curl, CURLOPT_URL, (this->base_url + "file/" + this->x_api_key).c_str());    
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, header_values);    
    curl_easy_setopt(this->curl, CURLOPT_HEADERFUNCTION, header_parse);      
    curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    
    // perform request
    CURLcode res = curl_easy_perform(this->curl);

    // get response status code
    long res_code = 0;
    curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &res_code);   

    // check returned response
    if (res != CURLE_OK)
    {
        return -1;
    }
    else
    {
        return res_code;        
    }
}