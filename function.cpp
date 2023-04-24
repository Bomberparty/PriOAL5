#include <iostream>
#include <cmath>

bool check_bit_sequence(int num, int sequence) {
    int sequence_length = log2(sequence) + 1; 
    for (int i = 0; i <= sizeof(num)*8 - sequence_length; i++) { 
        int mask = (1 << sequence_length) - 1; 
        if ((num & (mask << i)) == (sequence << i)) { 
            return true;
        }
    }
    return false;
}