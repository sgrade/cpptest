/**
 * @file
 * @brief 
 * 
 * Coding exercise:
 * 
 * For the given set of IPv4 addresses find a minimal spanning subnet. 
 * Implementation must be efficient from CPU and memory perspective. 
 * Reasonable test coverage is a plus. 
 * 
 * My assumptions:
 * - A minimal spanning subnet is a supernet, which: 
 *     - includes all the IP addresses from the set
 *     - has the longest prefix among the alternative subnets
 * - No subnet mask is given for the IP addresses in the input
 * - The exercise does not define format for the the input and output
 * - namespace std and simple data types are used for readability
 * 
 * Tested in: 
 * g++ (Debian 10.2.1-6) 10.2.1 20210110
 * c++20
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief This function prints the minimal spanning subnet
 * 
 * @param ips Set of IPv4 addresses
 */
void get_minimal_spanning_subnet (const set<vector<int>>& ips) {
    
    // Helper structure with possible IP subnet masks for each octet
    vector<int> masks = {0, 128, 192, 224, 240, 248, 252, 254, 255};
    
    // Initial output candidate
    vector<int> subnet = *ips.begin();

    // Helper vars
    int right = 4, x, pos, mask;

    // Initial masks for each of the four octets of the IPv4 address
    vector<int> mask_for_octet(4, 255);

    // Processing the input
    for (const vector<int>& ip: ips) {
        
        // Processing each octet separately
        for (int i = 0; i < right; ++i) {
        
            // Checking if the octet is different 
            x = subnet[i] ^ ip[i];

            // All bits are equal
            if (x == 0) continue;
            
            // Position of the leftmost bit, which is different
            pos = floor(log2(x));

            // The mask to use for the octet
            mask = min(mask_for_octet[i], masks[8 - (pos + 1)]);
            mask_for_octet[i] = mask;
            
            // Updating the output
            subnet[i] = subnet[i] & (ip[i] & mask);
            
            // We don't need to check the right octets, as we don't care 
            //  about the smaller subnetworks. We care only about supernets
            right = i + 1;
        }
    }

    // Updating the output for the octets we skipped
    for (int i = right; i < 4; ++i) subnet[i] = 0;

    // Calculating the subnet prefix
    int prefix = 0;
    for (int i = 0; i < right - 1; ++i) prefix += 8;
    prefix += bitset<8>(mask_for_octet[right - 1]).count();

    // Printing the output
    cout << "Minimal spanning subnet: \n";
    cout << subnet[0] << '.' << subnet[1] << '.' << subnet[2] << '.' << subnet[3] << '/' << prefix << endl;
}

static void test() {

    // Input: set of IPv4 addresses
    set<vector<int>> ips;
    
    ips.insert(vector<int>({10, 20, 0, 40}));
    ips.insert(vector<int>({10, 20, 1, 40}));
    
    ips.insert(vector<int>({10, 20, 3, 40}));
    
    ips.insert(vector<int>({10, 20, 4, 40}));

    ips.insert(vector<int>({10, 20, 16, 40}));
    ips.insert(vector<int>({10, 20, 17, 40}));
    
    ips.insert(vector<int>({10, 20, 31, 40}));
    
    ips.insert(vector<int>({10, 20, 32, 40}));
    ips.insert(vector<int>({10, 20, 32, 41}));
    ips.insert(vector<int>({10, 20, 32, 42}));

    ips.insert(vector<int>({10, 21, 32, 42}));
    // End of the input

    get_minimal_spanning_subnet(ips);
}


int main() {

    test(); // running self-test implementations

    return 0;
}
