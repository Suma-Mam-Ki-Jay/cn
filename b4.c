#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char msg[100];
long int p, q, n, t, e, d;
long int pt[100], ct[100];
long int i, j;
void calce();
void calcd();
void encrypt();
void decrypt();
long int gcd(long int a, long int b);
long int prime(long int pr);
void main() {
printf("\nEnter first prime number:\n");scanf("%ld", &p);
if (!prime(p)) {
printf("\nWrong Input\n");
exit(0);
}
printf("\nEnter another prime number:\n");
scanf("%ld", &q);
if (!prime(q) || p == q) {
printf("\nWrong Input\n");
exit(0);
}
printf("Enter Message:\n");
scanf("%s", msg);
for (i = 0; msg[i] != '\0'; i++)
pt[i] = msg[i];
pt[i] = '\0';
n = p * q;
t = (p - 1) * (q - 1);
calce();
calcd();
printf("\nValue of p = %ld\n", p);
printf("Value of q = %ld\n", q);
printf("Value of n = %ld\n", n);
printf("Value of t = %ld\n", t);
printf("Value of e = %ld\n", e);
printf("Value of d = %ld\n", d);
encrypt();
decrypt();
}
void calce() {
for (i = 2; i < t; i++) {
if (gcd(i, t) == 1)
e = i;
}
}
void calcd() {
e = e % t;
for (i = 1; i < t; i++) {
if ((e * i) % t == 1)
d = i;
}
}
void encrypt() {
long int k;
for (i = 0; i < strlen(msg); i++) {k = 1;
for (j = 1; j <= e; j++) {
k = (k * pt[i]) % n;
}
ct[i] = k;
}
ct[i] = '\0';
printf("\nThe encrypted message is:\n");
for (i = 0; ct[i] != '\0'; i++)
printf("%c", ct[i]);
}
void decrypt() {
long int k;
for (i = 0; i < strlen(msg); i++) {
k = 1;
for (j = 1; j <= d; j++) {
k = (k * ct[i]) % n;
}
pt[i] = k;
}
pt[i] = '\0';
printf("\nThe decrypted message is:");
for (i = 0; pt[i] != '\0'; i++)
printf("%c", pt[i]);
}
long int gcd(long int a, long int b) {
long int c;
while (a != 0) {
c = a;
a = b % a;
b = c;
}
return b;
}
long int prime(long int pr) {
int i;
j = sqrt(pr);
for (i = 2; i <= j; i++) {
if (pr % i == 0)
return 0;
}
return 1;
}
