"Sieve of Eratosthenes" by Joseph Castrejon

This is a simple and ancient algorithm for finding prime numbers for a given range. I created this program after reading on wikipedia
about algorithms for finding prime numbers. This implementation works, but is rather inelegant. The array that holds the 'boolean' values 
for found primes is loaded entirely into RAM and can quickly use up system memory. The removal of known composite numbers currently is
single threaded which is another area where performance can be improved. Feel free to make adjustments =)
