#include <stdio.h>
#include <stdint.h> 

typedef union {
    double value;
    unsigned char bytes[8];
} Number;

int get_bit(Number num, int i) {
    int byte_index = i / 8;
    int bit_index = i % 8;
    return (num.bytes[byte_index] >> bit_index) & 1;
}

void to_normal(double num) {
    Number number;
    number.value = num;

    int sign_bit = get_bit(number, 63);
    char sign_char = sign_bit ? '-' : '+';

    int exponent_bits = 0;
    for (int i = 52; i <= 62; i++) {
        exponent_bits = (exponent_bits << 1) | get_bit(number, i);
    }

    uint64_t mantissa_bits = 0;
    for (int i = 0; i < 52; i++) {
        mantissa_bits = (mantissa_bits << 1) | get_bit(number, i);
    }

    int bias = 1023; 
    int p = exponentBits - bias;
    double m;

    m = 1.0 + mantissa_bits / (double)(1ULL << 52);

    printf("Result: %c%.20f*2^%d\n", sign_char, m, p);
}

int main() {
    double x;
    printf("Enter a number: ");
    scanf("%lf", &x);
    to_normal(x);
    return 0;
}
