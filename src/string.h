// ************************************************************************ //
// **   Project: Aplikace pro řízený přístup                             ** //
// **            ke vzdáleným dokumentům pro GNU/Linux                   ** //
// **   University: VUT FIT Brno                                         ** //
// **   Authors: Jan Bernard                                             ** //
// **   Created: 27.12.2020                                              ** //
// **   Module: String - header                                          ** //
// ************************************************************************ //

#ifndef VDU_String_H
#define VDU_String_H

#include <algorithm> 
#include <string>

using namespace std;

/**
 *  https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring 
 */
// trim from start (in place)
static inline void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(string &s) {
    ltrim(s);
    rtrim(s);
}

#endif