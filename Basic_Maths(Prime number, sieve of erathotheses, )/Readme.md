# Description

### Sieve of Eratosthenes

Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1:N]
The algorithm is very simple:
**To Understand it let's use an example**

> Let N = 25
> find all the numbers which are less than 25 and are primes.

1. Firstly initialize a boolean array, sieve of size 26 with all values as true.

![blocks](images/blocks.png)

2. Then start traversing the iterator i from 2. If sieve[i] is found to be true, then mark all the multiples of i as false in the sieve array, it means that the numbers which are marked as false can't be prime since they've i as their factor.
