//lang::CwC

#pragma once

#include "string.h"

/**
 * Helper class that handles serializing primitive types.
 * 
 * @author Spencer LaChance <lachance.s@northeastern.edu>
 * @author David Mberingabo <mberingabo.d@husky.neu.edu>
 */
class Serializer : public Object {
public:
    /** 
     * Converts an int to a char*
     */
    static char* serialize_int(int i) {
        StrBuff buff;
        buff.c("{");
        buff.c(i);
        buff.c("}");
        return buff.c_str();
    }

    /** 
     * Converts a float to a char*
     */
    static char* serialize_float(float f) {
        Sys s;
        StrBuff buff;
        buff.c("{");

        // The size of the buffer that will hold the float
        size_t len = 10;
        char* c_float = new char[len]; 
        int bytes = snprintf(c_float, len, "%.7f", f);
        s.exit_if_not(bytes >= 0, "snprintf failed");
        while (bytes >= len) {
            // The float was too large for the buffer, so increase its size and try again
            delete[] c_float;
            len += 10;
            c_float = new char[len]; 
            bytes = snprintf(c_float, len, "%.7f", f);
            s.exit_if_not(bytes >= 0, "snprintf failed");
        }
        buff.c(c_float);
        buff.c("}");
        
        delete[] c_float;
        return buff.c_str();
    }

    /** 
     * Converts a bool to a char*
     */
    static char* serialize_bool(bool b) {
        StrBuff buff;
        buff.c("{");
        buff.c(b);
        buff.c("}");
        return buff.c_str();
    }
};