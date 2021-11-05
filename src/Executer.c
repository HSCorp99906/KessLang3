#include "../include/Executer.h"


void execute(struct Instruction* instructionList) {
    for (int i = 0; instructionList[i].type != _EOF; ++i) {
        switch (instructionList[i].type) {
            case BUILT_IN_CALL:
                switch (instructionList[i].type1) {
                    case OUTPUT:
                        struct IO curIOData;
                        curIOData._using = 'O';
                        curIOData.value = instructionList[i].value;
                        handleIO(&curIOData);
                        break;
                }

                break;
        }
    }
}
