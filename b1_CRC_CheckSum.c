#include <stdio.h>
#include <string.h>

#define N strlen(g)

char t[128], cs[128], g[] = "10001000000100010001";
int a, e, c;

void xor_operation() {
    for (c = 1; c < N; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc_calculation() {
    for (e = 0; e < N; e++)
        cs[e] = t[e];
    do {
        if (cs[0] == '1')
            xor_operation();
        for (c = 0; c < N - 1; c++)
            cs[c] = cs[c + 1];
        cs[c] = t[e++];
    } while (e <= a + N - 1);
}

int main() {
    printf("Enter data to be sent: ");
    scanf("%s", t);
    printf("\nGenerating polynomial is: %s", g);
    a = strlen(t);
    for (e = a; e < a + N - 1; e++)
        t[e] = '0';
    printf("\nModified t[u] in: %s", t);
    crc_calculation();
    printf("\nChecksum is: %s", cs);
    for (e = a; e < a + N - 1; e++)
        t[e] = cs[e - a];
    printf("\nFinal codeword is: %s", t);
    printf("\nDo you want to modify the data? (0: Yes, 1: No): ");
    scanf("%d", &e);
    if (e == 0) {
        printf("Enter position where data is to be modified: ");
        scanf("%d", &e);
        t[e] = (t[e] == '0') ? '1' : '0';
        printf("Erroneous data: %s\n", t);
    }
    crc_calculation();
    for (e = 0; (e < N - 1) && (cs[e] != '1'); e++);
    if (e < N - 1)
        printf("Error detected.\n");
    else
        printf("Error not detected.\n");

    return 0;
}
