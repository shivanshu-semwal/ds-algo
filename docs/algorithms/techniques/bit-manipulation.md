# Bit Manipulation

We have binary computers, that is they operate on bits.
So if we can utilize this property clearly we can greatly improve the efficiency of our algorithm.

## how to get the total no of bits for a data type

```cpp
// to get the no of bits for a data type
int noBits = sizeof int * 8;
```

## list of bitwise operators

- `&` and - this operators do and of two numbers
- `|` or - this does the or of bits of two numbers
- `~` not - this inverts all the bits in the number
- `^` xor - this does the xor, xor of two bits is true if both bits are different
- `<<n` left shift - this shift the bits to left `n` no of times, the bits are filled with 0.
- `>>n` right shift - this shift the bits to right `n` no of times, the new bits are filled with 0.

### notes

- The result of a right-shift of a signed negative number is implementation-dependent.
  So better not use `-2 >> 3`.
- If the `n` is negative the it is undefined behaviour.

## how to check if i'th bit is set or not - use and

```cpp
int i=3; // bit to get
int n = 132;
int t = n & (1 << i); // check bit set
```

## flip the i'th bit - use xor

```cpp
int i = 5; //  bit to filp
int n = 32432;
int t = n ^ (1 << i); // new no with bit flipped
```

## Compute xor from 1 to n

```cpp
int n = 100;
case(n%4){
    0: return n;
    1: return 1;
    2: return n+1;
    3: return 0;
}
// how this works? - because at intervals of 4 each bit have repeated twice
// this is clearly visible for 2^n - 1
// but even for cases where n % 4 == 0, the bits have repeated twice
// after which the n comes because, 0 ^ n = n
// after this we get 1, and then n + 1, then 0
```

## set bit at position p

```cpp
int n = 123;
int p = 10;
n = n & (~(1 << p));
```

## powers of 2

### check if no is power of two

```cpp
int x = 21312;
if(x==0) return true;
if(!(x & (x-1))) return true;
// ans of x ans x - 1 is 0 if it is power of 2
```

### multiply divide by 2

```cpp
int x = 213;
int y = x >> 1; // divide by 2
int z = x << 1; // multiply by 2
```

## MSB - LSB

- MSB - most significant bit - the leftmost set bit
- LSB - least significant bit - first bit to right

### get the rightmost set bit

```cpp
int x = 1021;
// get a new no with only its right most bit set 
// to that of the no
// 10100 -> 00100
int y = x ^ (~x + 1); 
// or
int y = x ^ -x; // because -x = ~x + 1 two's complement
```

### unset the rightmost set bit

```cpp
int x = 21312;
int y = x & (x-1);
```

### clear all bit from lsb to ith bit

```cpp
// [xxxxxi....0]
int x = 1312;
int i = 4;
int mask = ~((1 << i+1 ) - 1);
x &= mask;
```

### clear all bit from msb to ith bit

```cpp
// [xx1...ixxxx] [1...i] this will be 0
mask = (1 << i) - 1;
x &= mask;
```

### get the msb

```cpp
int n = 123;
// the msb will make it's right adjacent element 1 so now 2 elements are 1
n = n | (n & n >> 1); 
// now make 4 1's with 2 1's
n = n | (n & n >> 2);
// now make 8 1's with 4 1's
n = n | (n & n >> 4);
// now make 16 1's with 8 1's
n = n | (n & n >> 8);
// now make 32 1's with 16 1's
n = n | (n & n >> 16);
// now the number will be all 1's to its msb
// so we now add 1 and right shift 1 to get it
// this would overflow on last bit so check if it is last bit too
return ((n+1) >> 1) | (n & (1<<31));
```

## upper case to lower case

```cpp
char c= 'd';
c ^= 32; // for ascii value character only
```

## Problems solved using bitwise

- all no are repeated even no of time expect one find it
    - do xor of all elements
- swap two numbers without additional variable and arithmetic operators
    - `x = x ^ y;`
    - `y = x ^ y;` - `x ^y ^ y` which is `x` so now `y` have `x` value
    - `x = x ^ y;` - `x ^y ^ x` which is `y`q
- find to non-repeating elements `x` and `y`, all other elements repeat twice
    - do xor of all elements you wil get `x ^ y` as other will cancel out.
    - now if two no are different, which is the first bit they differ on,
      it would be the rightmost set bit of their xor( xor is true only if things differ)
    - so you divide no into group according to the right most bit of xor, and then do xor
      of the two groups separately. and you will get both no.
