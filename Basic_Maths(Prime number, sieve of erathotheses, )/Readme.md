# Chapter 6

## Features

- Sieve of Eratosthenes
- Segmented Sieve
- Euclid's Algo
- Modular Airthmetic
- fast Exponentiation
- Modular Exponentiation
- Pigeon - hole principle
- Catalan number
- Inclusion - Exclusion principle

### 1. Sieve of Eratosthenes

Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1:N]
The algorithm is very simple:
**To Understand it let's use an example**

> Let N = 25
> find all the numbers which are less than 25 and are primes.

1. Firstly initialize a boolean array, sieve of size 26 with all values as true.

![blocks](https://user-images.githubusercontent.com/95477259/229144100-cb4a7ea5-7094-46df-b64b-0c89b922376a.png)


2. Then start traversing the iterator i from 2. If sieve[i] is found to be true, then mark all the multiples of i as false in the sieve array, it means that the numbers which are marked as false can't be prime since they've i as their factor.
