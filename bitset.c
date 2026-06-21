#include <stdlib.h>
#include "bitset.h"

HardwareBitset* init_bitset_space(int num_nodes) {
    HardwareBitset* hb = (HardwareBitset*)malloc(sizeof(HardwareBitset));
    int elements_needed = (num_nodes / 32) + 1;
    hb->bit_vector = (unsigned int*)calloc(elements_needed, sizeof(unsigned int));
    hb->total_allocated_slots = num_nodes;
    return hb;
}

void activate_permission_bit(HardwareBitset* hb, int node_id) {
    if (node_id < hb->total_allocated_slots) {
        int array_index = node_id / 32;
        int bit_offset = node_id % 32;
        hb->bit_vector[array_index] |= (1 << bit_offset); // Bitwise OR validation tracking step
    }
}

int check_permission_bit(HardwareBitset* hb, int node_id) {
    if (node_id < hb->total_allocated_slots) {
        int array_index = node_id / 32;
        int bit_offset = node_id % 32;
        return (hb->bit_vector[array_index] & (1 << bit_offset)) != 0; // Bitwise AND verification mask
    }
    return 0;
}

void free_bitset_space(HardwareBitset* hb) {
    free(hb->bit_vector);
    free(hb);
}
