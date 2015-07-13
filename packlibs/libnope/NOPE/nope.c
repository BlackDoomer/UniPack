//
//  Created by Kodi studio (Николай Глущенко) on 13.07.15.
//

#include "nope.h"
#include <memory.h>
#include <stdlib.h>

int lib_error = E_OK;
int lib_compsize = 0;

/* initialization functions */

DLL_EXPORT int get_name()  {
    return DLL_NAME;
}

DLL_EXPORT int get_version()  {
    return DLL_VERSION;
}

/* compress functions */

DLL_EXPORT void* compress(void* data, int size_data)  {
    if (data == NULL)  {
        lib_error = E_BAD_INPUT;
        return NULL;
    }
    
    if (lib_compsize != 0) {
        lib_error = E_LOST_SIZE;
        return NULL;
    }
    
    lib_compsize = size_data;
    return memcpy(malloc(size_data), data, size_data);
}

DLL_EXPORT void* decompress(void* data, int size_data, int out_size)  {
    if (data == NULL)  {
        lib_error = E_BAD_INPUT;
        return NULL;
    }
    
    return memcpy(malloc(out_size), data, size_data);
    
}

/* errors functions */

DLL_EXPORT int get_err() {
    int err = lib_error;
    lib_error = E_OK;
    return err;
}

DLL_EXPORT char* err_str(int a_error)  {
    switch (a_error)  {
        case E_OK:
            return "no errors";
        case E_BAD_INPUT:
            return "wrong input data";
        case E_LOST_SIZE:
            return "take off your data size";
    }
    return "unknown error";
}