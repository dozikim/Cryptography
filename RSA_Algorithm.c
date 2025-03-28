#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp /2 ;
        base = (base * base) % mod;
    }
    return result;
}

// Main function
int main() {
    // Step 1: Choose two prime numbers p and q
    int p = 61;  // Example prime number
    int q = 53;  // Example prime number
    printf("Chosen primes p=%d and q=%d\n", p, q);

    // Step 2: Calculate n = p * q
    int n = p * q;
    printf("Calculated n=p*q=%d\n", n);

    // Step 3: Calculate phi(n) = (p-1)*(q-1)
    int phi = (p - 1) * (q - 1);
    printf("Calculated phi(n)=(p-1)*(q-1)=%d\n", phi);

    // Step 4: Choose an encryption key e such that 1 < e < phi and gcd(e, phi) = 1
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    printf("Chosen encryption key e=%d\n", e);

    // Step 5: Calculate the decryption key d such that (d * e) % phi = 1
    int d;
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            break;
    }
    printf("Calculated decryption key d=%d\n", d);

    // Display public and private keys
    printf("Public key: (e=%d, n=%d)\n", e, n);
    printf("Private key: (d=%d, n=%d)\n", d, n);

    // Step 6: Encryption
    int message;
    printf("Enter a message (as an integer) to encrypt: ");
    scanf("%d", &message);

    if (message < 0 || message >= n) {
        printf("Message must be in the range [0, %d).\n", n);
        return 1;
    }

    long long encrypted_message = mod_exp(message, e, n);
    printf("Encrypted message: %lld\n", encrypted_message);

    // Step 7: Decryption
    long long decrypted_message = mod_exp(encrypted_message, d, n);
    printf("Decrypted message: %lld\n", decrypted_message);

    return 0;
}
