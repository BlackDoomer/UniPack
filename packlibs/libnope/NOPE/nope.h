#ifndef ____NOPE__
    #define ____NOPE__

    #include <stdio.h>

    /* initialization dll property */

    #define DLL_VERSION 1
    #define DLL_NAME 'NOPE'

    /* end initialization */

    #ifndef DLL_EXPORT

        #ifdef WINDOWS

            #define DLL_EXPORT __cdecl __declspec( dllexport )

        #endif /* defined(export for windows) */

        #ifdef __APPLE__

            #define DLL_EXPORT __cdecl __attribute__(( visibility( "default" )))

        #endif /* defined(export for mac os) */

    #endif /* defined(DLL_EXPORT) */

    /* give information about dll */

    int get_name();
    int get_version();

    /* initialization compress functions */

    void* compress(void* data, int size_data);
    void* decompress(void* data, int size_data, int out_size);

    /* initialization errors defines and functions */

    /* error defines */

    #define E_OK 0
    #define E_BAD_INPUT 1
    #define E_LOST_SIZE 2

    /* error functions */

    int get_err();
    char* err_str(int a_error);

#endif /* defined(____huff__) */