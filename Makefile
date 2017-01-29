all:

sieve_primes2:
	gcc -O3 sieve_primes2.c -o 'out/sieve_primes2'

sieve_primes3:
	gcc -O3 sieve_primes3.c -o 'out/sieve_primes3'

sieve_primes3_asm:
	gcc -S -O3 sieve_primes3.c -o 'out/sieve_primes3.s'
