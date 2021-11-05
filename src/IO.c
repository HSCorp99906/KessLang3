#include "../include/IO.h"


void handleIO(struct IO __IO) {
    if (__IO._using == 'O') {
        printf("%s\n", __IO.value);
    }
}
