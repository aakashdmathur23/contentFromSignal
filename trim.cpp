#include "unlimited.hpp"
#include "decimate.hpp"
#include "moments.hpp"
#include "binfilewrite.hpp"


string trim(const std::string &s) // trim function
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
 
    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
 
    return std::string(start, end + 1);
}