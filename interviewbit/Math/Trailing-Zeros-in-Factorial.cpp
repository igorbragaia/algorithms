int Solution::trailingZeroes(int A) {
    int count = 0, pot = 5;
    while(pot <= A){
        count += A/pot;
        pot *= 5;
    }
    return count;
}
