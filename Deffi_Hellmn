#include <stdio.h>
#include <math.h>

int modular_exponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    printf("Initial Base: %d \n", base);
    
    while (exp > 0) {
        printf("Current exp: %d, result: %d, base: %d \n", exp, result, base);
        
        // If exponent is odd, update result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
            printf("Odd exp -> result updated to: %d \n", result);
        } else {
            printf("Even exp -> no change in result \n");
        }
        
        // Divide the exponent by 2 for the next iteration
        exp = exp / 2;
        printf("Exp divided by 2 -> exp updated to: %d\n", exp);
        
        // Square the base
        base = (base * base) % mod;
    }
    
    return result;
}

int main() {
    int p, g;
    int private_key_A, private_key_B;
    int public_key_A, public_key_B;
    int shared_secret_A, shared_secret_B;
    
    printf("Enter the prime number (p): ");
    scanf("%d", &p);
    
    printf("Enter a primitive root modulo %d (g): ", p);
    scanf("%d", &g);
    
    printf("Enter Alice's private key: ");
    scanf("%d", &private_key_A);
    
    printf("Enter Bob's private key: ");
    scanf("%d", &private_key_B);
    
    printf("\nCalculating Alice's public key...\n");
    public_key_A = modular_exponentiation(g, private_key_A, p);
    printf("\nAlice's public key: %d \n", public_key_A);
    
    printf("\nCalculating Bob's public key...\n");
    public_key_B = modular_exponentiation(g, private_key_B, p);
    printf("\nBob's public key: %d\n", public_key_B);
    
    // Compute the shared secret using Alice's and Bob's public keys
    shared_secret_A = modular_exponentiation(public_key_B, private_key_A, p);
    shared_secret_B = modular_exponentiation(public_key_A, private_key_B, p);
    
    printf("\nShared secret calculated by Alice: %d\n", shared_secret_A);
    printf("Shared secret calculated by Bob: %d\n", shared_secret_B);
    
    // Check if both computed shared secrets are the same
    if (shared_secret_A == shared_secret_B) {
        printf("\nKey Exchange Successful! Shared Secret: %d\n", shared_secret_A);
    } else {
        printf("\nKey Exchange Failed. Secrets do not match.\n");
    }
    
    return 0;
}
