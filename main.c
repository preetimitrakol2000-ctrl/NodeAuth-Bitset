#include <stdio.h>
#include "bitset.h"

extern int process_handshake_compliance(HardwareBitset* hb, int node);

int main() {
    printf("🔒 Instantiating NodeAuth-Bitset Hardware Verification Ring...\n\n");

    int mesh_network_limit = 64;
    HardwareBitset* trust_registry = init_bitset_space(mesh_network_limit);

    // Whitelist specific device IDs inside the compact bitwise vector array
    activate_permission_bit(trust_registry, 14);
    activate_permission_bit(trust_registry, 42);

    int test_node_a = 42;
    int test_node_b = 19;

    printf("📡 Testing Handshake Request from Device ID: %d\n", test_node_a);
    if (process_handshake_compliance(trust_registry, test_node_a)) {
        printf("   ✅ ACCESS GRANTED: Device signature whitelisted in system bit-vector.\n");
    } else {
        printf("   🚨 SYSTEM REJECTION: Unknown identity signature verified.\n");
    }

    printf("\n📡 Testing Handshake Request from Device ID: %d\n", test_node_b);
    if (process_handshake_compliance(trust_registry, test_node_b)) {
        printf("   ✅ ACCESS GRANTED\n");
    } else {
        printf("   🚨 SYSTEM REJECTION: Signature mismatch. Dropping communications.\n");
    }

    free_bitset_space(trust_registry);
    return 0;
}
