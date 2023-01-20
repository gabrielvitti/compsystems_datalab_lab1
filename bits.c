/* 
 * CS:APP Data Lab 
 * 
 * Gabriel Vitti gavi0633
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 
 TEST
 
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /* Since "&" is just the inverse of "|", I used "~" to inverse (x&y),
  but, this would also inverse x and y so I inversed them as well.*/
  return ~(~x&~y);
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  /* Every integer except for zero in C is denoted as being true. 
  Therefore, using the logical NOT operator "!" will return a 1 for 
  zero, and a 0 for all other integers.*/
  return !x;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /* The maximum two's complement number would be positive because positive is
  greater than negative. So this number would be represented by all 1's except 
  for a zero in the left most bit position of 32. So, I bit-shifted 1 to the 
  left by 31 positions to put it into position 32 (the rest of the bits are 0),
  and I used the binary one's complement operator to flip all the bit values.*/
  return (~(1 << 31));
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  /* I first set an integer to equal (0 x AA AA AA AA) because this int
  has all of it's odd numbered bits equal to one and I could then use 
  the & operater to see if there were any odd numbered bits set to 1 in
  the input. After this, I used two negations to change the integer returned
  to a false and then a true. */
  int a,b,c;
  a = 0xAA;
  b = (a << 8) | a;
  c = (b << 16) | b; 
    return !!(c & x);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* I first bit shifted x by (32 - n) positions to the left and then
  back to the right. This will pull the most significant figure to fill
  in the empty bits. I then compared the new number to the original input
  to see if they were the same and used the not operator to turn it binary.*/
  int y;
  y = x << (32 + (~n + 1));
  y = y >> (32 + (~n + 1));
  return !(x ^ y);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /* To get a mask that marks the position of the least significant 1 bit,
  I used & on x with negative x. I found this was a property of binary numbers
  by just messing around with a decimal to binary converter */
  return (x & (~x + 1));
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* I first checked if the input was smaller by comparing the important bits with 3.
  I then checked if the input was bigger by comparing different bits with 3 and
  seeing if certain bits were filled in.*/
  int a, b, c, d, e;
  a = x >> 4;
  b = 57;
  c = x >> 1;
  d = x >> 3;
  e = (d & 7) << 29;
  e = e >> 29;
  return (!(a ^ 3) & ((~e) | !(c & 3)));
}
/* 
 * isLessOrEqual - if x <= y then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* First subtracts x and y (I don't include the two's complement "+1" because
  it is not needed since I am bit shifting by 31 after and I thought it might
  flip the sign of the output on edge cases) it then checks the sign of the output.
  It also checks if the inputs are the same sign or not, and if they're not, it
  just checks if x is negative and y is positive.*/
  return ((!!(((x + (~y) >> 31)) & (!!(x >> 31) | !(y >> 31))) | (!!(x >> 31) & !(y >> 31))));
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /* I reversed the bytes by making 4 variables to hold each byte. I bit shifted
  and masked them with 0xff to accomplish this. I then bit shifted them back to the desired
  positions and or'd them together.*/
  int mask = 0xff;
  int a, b, c, d;
  d = (x >> 24) & mask;
  c = (x >> 16) & mask;
  b = (x >> 8) & mask;
  a = x & mask;
  a = a << 24;
  b = b << 16;
  c = c << 8;
  return a | b | c | d;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* I counted the bytes by first making a mask of 0x01010101. I then applied this mask
  to the input 8 times and shifted the input 1 to the right each time. I then add all
  these new variables together and mask them with 0xFF. I then add all the seperate bytes
  of z together to get the final output.*/
  int bitCMask1 = 1;
  int bitCMask2 = (bitCMask1 << 8) + 1;
  int bitCMask3 = (bitCMask2 << 8) + 1;
  int bitCMask = (bitCMask3 << 8) + 1;
  int s = bitCMask & x;
  int s1 = (bitCMask) & (x >> 1);
  int s2 = (bitCMask) & (x >> 2);
  int s3 = (bitCMask) & (x >> 3);
  int s4 = (bitCMask) & (x >> 4);
  int s5 = (bitCMask) & (x >> 5);
  int s6 = (bitCMask) & (x >> 6);
  int s7 = (bitCMask) & (x >> 7);
  int z = s + s1 + s2 + s3 + s4 + s5 + s6 + s7;
  int a = (z&255) + ((z>>8)&255) + ((z>>16)&255) + ((z>>24)&255);
  return a;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*
  I implemented this by checking if the input is equal to 0 or greater than
  0 by flipping it and adding 1. If the input is zero, this operation will result
  in a zero. If the input is positive, this will result in 0xFFFFFFFF. However, if
  the input is negative it will also result in a 0. So to catch this case I added an
  or that checked if the input was zero by making the variable "b" equal to 
  0xFFFFFFFF if it is negative. Once all this is done it will add one to change
  the 0 to a 1 and to change the 0xFFFFFFFF to a 0.
  */
  int a = ((~x + 1) >> 31);
  int b = x >> 31;
  return (a | b) + 1;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x) {
  /* For this implementation, I first divided by 8 and then multiplied by 5. I then
  grabbed the remainder by &ing x with 7 to get the first 3 bits. I multiplied the
  remainder by 5 and then divided by seven. I also &'d 7 with the signed bit shifted
  by 31 to the right. This will result in a 0x0 for positive numbers and a 0x7 for all
  negative inputs. I then added this to the remainder5 because negative numbers were 
  rounding down instead of towards zero.*/
  int signedBit = (x >> 31);
  int xd8 = x >> 3;
  int x5d8 = (xd8 << 2) + xd8;
  int remainder = (x & 7);
  int remainder5 = (remainder << 2) + remainder;
  int is_neg_remained = signedBit & 7;
  int remainder5d8 = (remainder5 + is_neg_remained >> 3);
    return x5d8 + remainder5d8;
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 /* I implemented this by first checking if the 8 exponent bits were filled up
 to see if the float was NaN and returned the input if that was the case. I then
 flipped the signed bit using the XOR operation and returned that value.*/
int check;
check = uf & ~(1<<31);
  if(check > 0x7F800000) {
    return uf;
    }
    
  uf = uf ^ (1 << 31);
 return uf;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /* This one took forever. I first checked to see if there would be overflow if
  adding 1 to the 8 signed bits and returned a negative or positive NaN value if that
  was the case. I then checked to see if the 8 exponent bits were filled up and if they
  were, I returned the input. I then checked if the input was equal to 0 or -0 and 
  returned the input if that was the case. I then, depending on whether or not there 
  were 1's in the exponent place, either added 1 to the exponent case, or shifted the 
  decimal bits by one if the exponent bits were all 0.*/
  int check;
  int placeThing;
  int placeholder;

  
check = (uf & ~(1<<31)) >> 23;
  if(check == 254) {
    return (0x7F800000) + (uf & (1<<31));
    }
    if(check > 254){
        return uf;
    }
    if(!(uf & ~(1<<31))){
    return uf;
    }
    placeThing = check << 23;
    placeholder = (((placeThing >> 23) + 1) << 23) & 0x7F800000;
    
    if(!(uf & 0x7f800000)){
        return (uf << 1) ^ (uf & (1<<31));
    }

    uf = uf & 0x807FFFFF;

    uf = uf + placeholder;
    
  return uf;
}