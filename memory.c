#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exchange (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void *memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

void *memset(void *s, int c, size_t n) {
    char *p = s;
    while (n--) {
        *p++ = c;
    }
    return s;
}

void *memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    }
    return dest;
}

void *memchr(const void *s, int c, size_t n) {
    const char *p = s;
    while (n--) {
        if (*p == c) {
            return (void *)p;
        }
        p++;
    }
    return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = s1, *p2 = s2;
    while (n--) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    return 0;
}

float atof(const char *s) {
    float n = 0;
    int sign = 1;
    int i = 0;
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        n = n * 10 + s[i] - '0';
        i++;
    }
    if (s[i] == '.') {
        float m = 1;
        i++;
        while (s[i] >= '0' && s[i] <= '9') {
            m /= 10;
            n += (s[i] - '0') * m;
            i++;
        }
    }
    return sign * n;

}

void remove_from_Array(int *array, int size, int value) {
    int i = 0;
    while (i < size) {
        if (array[i] == value) {
            int j = i;
            while (j < size - 1) {
                array[j] = array[j + 1];
                j++;
            }
            size--;
        } else {
            i++;
        }
    }
}





int main(int argv, char *argc[]){
    int x = 5, y = 10;

    printf("x = %d, y = %d\n", x, y);
    exchange(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    


    return 0;

}


