#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int romanToInt(char *s) {
    int sum = 0;
    while (*s) {
        if (*s == 'I' && (*(s + 1) == 'V' || *(s + 1) == 'X')) {
            if (*(s+1) == 'V') {
                sum += (V - I);
                s += 2;
                continue;
            } else if (*(s + 1) == 'X') {
                sum += (X - I);
                s += 2;
                continue;
            }
        } else if (*s == 'X' && (*(s + 1) == 'L' || *(s + 1) == 'C')) {
            if (*(s + 1) == 'L') {
                sum += (L - X);
                s += 2;
                continue;
            } else if (*(s + 1) == 'C') {
                sum += (C - X);
                s += 2;
                continue;
            }
        } else if (*s == 'C' && (*(s + 1) == 'D' || *(s + 1) == 'M')) {
            if (*(s + 1) == 'D') {
                sum += (D- C);
                s += 2;
                continue;
            } else if (*(s + 1) == 'M') {
                sum += (M - C);
                s += 2;
                continue;
            }
        } else {
            if(*s == 'I') {
                sum += I;
                s += 1;
                continue;
            } else if (*s == 'V') {
                sum += V;
                s++;
                continue;
            } else if (*s == 'X') {
                sum += X;
                s++;
                continue;
            } else if (*s == 'L') {
                sum += L;
                s++;
                continue;
            } else if (*s == 'C') {
                sum += C;
                s++;
                continue;
            } else if (*s == 'D') {
                sum += D;
                s++;
                continue;
            } else if (*s == 'M') {
                sum += M;
                s++;
                continue;
            }
        }
    }
    return sum;
}
