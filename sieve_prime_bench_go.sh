#!/bin/bash -e

set="100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000"
for max in $set; do
  time ./sieve_prime_go $max
done
