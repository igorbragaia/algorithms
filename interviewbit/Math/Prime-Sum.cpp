vector<int> Solution::primesum(int A) {
    vector<bool>eratosthenes_sieve(A+1, false);
    for(int i=2; i<=A;i++){
        if(!eratosthenes_sieve[i]){
            int j=2*i;
            while(j<=A){
                eratosthenes_sieve[j]=true;
                j+=i;                
            }
        }
    }
    for(int i=2;i<=A;i++){
        if(!eratosthenes_sieve[i] and !eratosthenes_sieve[A-i])
            return {i, A-i};
    }
}
