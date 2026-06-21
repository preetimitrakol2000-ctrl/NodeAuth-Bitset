#include "bitset.h"
int process_handshake_compliance(HardwareBitset* hb, int node) {
    return check_permission_bit(hb, node);
}
