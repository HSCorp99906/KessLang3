#ifndef KESS_IO_H_
#define KESS_IO_H_

#include <stdio.h>


struct IO {
    char _using;
    char* value;
    char* input_storage;
};


void handleIO(struct IO* __IO);


#endif  // KESS_IO_H_
