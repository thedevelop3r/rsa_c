#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// define rsa key pair
typedef struct
{
  long p;
  long q;
  long n;
  long phi;
  long e;
  long d;
} Keypair;

// prime number test
bool isPrime(long n)
{
  if(n < 2) return false;
  else if(n == 2) return true;
  else
  {
    int i;
    for(i = 2; i <= sqrt(n); i++);
    {
      if(n % i == 0) return false;
    }
    return true;
  }
}

// greatest common divisor (Euclid's algorithm with modulus)
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

  // get primes from user
  scanf("%ld", &rsa_key.p);
  while(!isPrime(rsa_key.p))
  {
    printf("ERROR: value must be prime\n");
    scanf("%ld", &rsa_key.p);
  }

  scanf("%ld", &rsa_key.q);
  while(!isPrime(rsa_key.q))
  {
    printf("ERROR: value must be prime\n");
    scanf("%ld", &rsa_key.q);
  }

  // calc n and totient(n)
  rsa_key.n = rsa_key.p * rsa_key.q;
  rsa_key.phi = (rsa_key.p - 1) * (rsa_key.q - 1);
  
  // generate public exponent
  rsa_key.e = 2;
  while(gcd(rsa_key.e, rsa_key.phi) != 1)
  {
    rsa_key.e++;
  }

  // generate private exponent
  rsa_key.d = rsa_key.e + 1;
  while(rsa_key.d * rsa_key.e % rsa_key.phi != 1)
  {
    rsa_key.d++;
  }
  
  printf("p: %ld\nq: %ld\nn: %ld\nphi: %ld\ne: %ld\nd: %ld\n", rsa_key.p, rsa_key.q, rsa_key.n, rsa_key.phi, rsa_key.e, rsa_key.d);
}

