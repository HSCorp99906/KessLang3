#include "../include/IO.h"


void handleIO(struct IO* __IO) {
    if (__IO -> _using == 'O') {
        printf("%s\n", __IO -> value);
    } else if (__IO -> _using == 'I') {
        printf("%s", __IO -> value);
        scanf("%s", __IO -> input_storage);
    }
}
