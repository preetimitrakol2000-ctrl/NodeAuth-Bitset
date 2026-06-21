#ifndef BITSET_H
#define BITSET_H

typedef struct {
    unsigned int* bit_vector;
    int total_allocated_slots;
} HardwareBitset;

HardwareBitset* init_bitset_space(int num_nodes);
void activate_permission_bit(HardwareBitset* hb, int node_id);
int check_permission_bit(HardwareBitset* hb, int node_id);
void free_bitset_space(HardwareBitset* hb);

#endif
