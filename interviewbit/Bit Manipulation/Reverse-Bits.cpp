unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    A = ((A&(0xFFFF0000))>>16) | ((A&(0x0000FFFF))<<16);
    A = ((A&(0xFF00FF00))>>8)  | ((A&(0x00FF00FF))<<8);
    A = ((A&(0xF0F0F0F0))>>4)  | ((A&(0x0F0F0F0F))<<4);
    A = ((A&(0xCCCCCCCC))>>2)  | ((A&(0x33333333))<<2);
    A = ((A&(0xAAAAAAAA))>>1)  | ((A&(0x55555555))<<1);
    return A;
}
