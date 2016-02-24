#include <stdio.h>

typedef struct keypair
{
  long p;
  long q;
  long n;
  long phi;
  long e;
  long d;
} Keypair;

long gcd(long m, long n)
{
  int temp;
  while(m != 0)
  {
    temp = m;
    m = n % m;
    n = temp;
  }
  return n;
}

int main()
{
  Keypair rsa_key;

  scanf("%ld", &rsa_key.p);
  scanf("%ld", &rsa_key.q);

  rsa_key.n = rsa_key.p * rsa_key.q;
  rsa_key.phi = (rsa_key.p - 1) * (rsa_key.q - 1);
  
  rsa_key.e = 2;
  while(gcd(rsa_key.e, rsa_key.phi) != 1)
  {
    rsa_key.e++;
  }

  rsa_key.d = rsa_key.e + 1;
  while(rsa_key.d * rsa_key.e % rsa_key.phi != 1)
  {
    rsa_key.d++;
  }
  
  printf("%ld\n%ld\n%ld\n%ld\n%ld\n%ld\n", rsa_key.p, rsa_key.q, rsa_key.n, rsa_key.phi, rsa_key.e, rsa_key.d);
}

