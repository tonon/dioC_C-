#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

void intToStr(int num, char* str, int base) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* decToBin(int n) {
    static char bin[33];
    intToStr(n, bin, 2);
    return bin;
}

char* decToOct(int n) {
    static char oct[12];
    intToStr(n, oct, 8);
    return oct;
}

char* decToHex(int n) {
    static char hex[9];
    intToStr(n, hex, 16);
    return hex;
}

int binToDec(const char* bin) {
    return strtol(bin, NULL, 2);
}

int octToDec(const char* oct) {
    return strtol(oct, NULL, 8);
}

int hexToDec(const char* hex) {
    return strtol(hex, NULL, 16);
}
