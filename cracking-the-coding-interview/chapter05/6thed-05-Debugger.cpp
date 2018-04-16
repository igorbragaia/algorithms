// A       = 1010101110111000000
// A - 1   = 1010101110110111111
// A&(A-1) = 1010101110110000000

// A     = abcdefghijklmnopqrs000000
// A - 1 = abcdefghijklmnopqr0111111

// We see that A - 1 sets the least significant bit to zero if it is 1 and turn lower bits to 1 if the least is not the first
// So A&(A-1) cleares the least significant bit

// Finally, A&(A-1) == 0 is a way to check is A is power of two