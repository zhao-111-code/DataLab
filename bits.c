/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1 << 31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return ~(~x & ~y) & ~(x & y);
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (x >> 31) & (~x + 1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  return (x & ~(0xFF << (dst << 3))) | (((x >> (src << 3)) & 0xFF) << (dst << 3));
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  return (x >> n) & ~(((1 << 31) >> n) << 1);
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x){
int nibMask = 0x0F;
    nibMask |= nibMask << 8;
    nibMask |= nibMask << 16;

    int lowNibbles = x & nibMask;
    int highNibbles = x & (nibMask << 4);

    int partA = lowNibbles << 4;
    int partB = (highNibbles >> 4) & nibMask;
    return partA | partB;
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
   int y = ~x;
	int first = y & (~y + 1);
	int y2 = y ^ first;
	return y2 & (~y2 + 1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
     x = x ^ (x >> 1);
	 x = x ^ (x >> 2);
	 x = x ^ (x >> 4);
	 x = x ^ (x >> 8);
	 x = x ^ (x >> 16);
	 return !(x & 1);
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  int mask = ~(((1 << 31) >> n) << 1);
  int low = x & ((1 << n) + ~0);
  int high = (x >> n) & mask;
  return high | (low << (32 + (~n + 1)));
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
    int m = 1 << n;
    int half = m >> 1;
    int q = x >> n;
    int r = x & (m + ~0);
    int diff = r + ~half + 1;       
    int sign = diff >> 31;        
    int eq = !diff;
    int greater = (sign + 1) + ~eq + 1;  
    int qOdd = q & 1;
    int up = greater | (eq & qOdd);
    return (q + up) << n;

}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
    int base = (x & y) + ((x ^ y) >> 1);
    int tie = (x ^ y) & 1;
    int diff = x + ~y + 1;
    int signsDiff = (x ^ y) >> 31;
    int addSign = (signsDiff & (x >> 31)) | ((~signsDiff) & (diff >> 31));
    int xGTy = addSign + 1;
    return base + (tie & xGTy);

}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
     int subAB = a + ~b + 1;
    int signXorAB = (a ^ b) >> 31;
    int aGreatEqualB = (signXorAB & ~(a >> 31)) | (~signXorAB & ~(subAB >> 31));
    int swapFlag = ~aGreatEqualB;
    int xorAB = a ^ b;
    int lower = b ^ (xorAB & swapFlag);
    int upper = a ^ (xorAB & swapFlag);

    int xorXL = (x ^ lower);
    int signXL = xorXL >> 31;
    int subXL = x + ~lower + 1;
    int geLower = ~((signXL & (x >> 31)) | (~signXL & (subXL >> 31))) & 1;

    int xorUX = (upper ^ x);
    int signUX = xorUX >> 31;
    int subUX = upper + ~x + 1;
    int upperGreatEqX = ~((signUX & (upper >> 31)) | (~signUX & (subUX >> 31))) & 1;

    return geLower & upperGreatEqX;

}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
    int fourX = x << 2;
    int five = fourX + x;
    int sign = x >> 31;

    int overflow4 = (x >> 29) ^ sign;
    int overflowAdd = ((fourX ^ five) & (x ^ five)) >> 31;
    int overflow = !!(overflow4 | overflowAdd);

    int max = ~(1 << 31);
    int min = 1 << 31;
    int saturated = (sign & min) | (~sign & max);

    int mask = (~overflow) + 1;

    return (mask & saturated) | (~mask & five);

}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int sumXY = x + y;
    int total = sumXY + z;

    int ovf1Neg = ((x & y & ~sumXY)) >> 31;
    int ovf1Pos = ((~x & ~y & sumXY)) >> 31;
    int ovf2Neg = ((sumXY & z & ~total)) >> 31;
    int ovf2Pos = ((~sumXY & ~z & total)) >> 31;

    int posOverflow = (ovf1Pos & ~ovf2Neg) | (~ovf1Neg & ovf2Pos);
    int negOverflow = (ovf1Neg & ~ovf2Pos) | (~ovf1Pos & ovf2Neg);

    return (posOverflow & 1) | (negOverflow + (~0) + 1);

}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
unsigned s = uf & 0x80000000u, exp = (uf>>23)&0xFFu, frac = uf&0x7FFFFFu;
    if(exp==0xFFu||(exp==0u&&!frac)) return uf;
    unsigned mant = frac; int e = exp?((int)exp-127):-126;
    if(!exp) while(!(mant&0x800000u)) { mant<<=1; e--; }
    unsigned prod = ((1u<<23)|mant)*3u, rnd=0u; e--;
    for(;prod>=(1u<<24);prod>>=1,e++) rnd=(rnd<<1)|(prod&1u);
    unsigned newFrac = prod&0x7FFFFFu;
    if((rnd&1u)&&((newFrac&1u)||(rnd>>1)))
        { newFrac++; if(newFrac>=(1u<<23)) {newFrac=0;e++;} }
    int eB = e+127;
    if(eB<=0){
        if(eB<-23) return s;
        int sh=1-eB; unsigned dm=prod>>sh, lost=prod&((1u<<sh)-1);
        if(lost>(1u<<(sh-1))||(lost==(1u<<(sh-1))&&(dm&1u))) dm++;
        return dm>=(1u<<23)?(s|(1u<<23)|(dm&0x7FFFFFu)):(s|dm);
    }
    return eB>=0xFF?(s|(0xFFu<<23)):(s|(((unsigned)eB)<<23)|newFrac);
}


// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
unsigned sign_bit = uf & 0x80000000u;
    unsigned exponent = (uf >> 23) & 0xFFu;
    unsigned fraction = uf & 0x7FFFFFu;

    if (exponent == 0xFFu)
        return uf;
    if (exponent == 0u)
        return sign_bit;

    int e_real = (int)exponent - 127;
    if (e_real < 0) {
        if (e_real == -1 && fraction > 0u)
            return sign_bit | (127u << 23);
        return sign_bit;
    }
    if (e_real >= 23)
        return uf;

    int shift_amt = 23 - e_real;
    unsigned mask_trunc = (1u << shift_amt) - 1;
    unsigned half_point = 1u << (shift_amt - 1);
    unsigned leftover = fraction & mask_trunc;
    unsigned truncated_frac = fraction & (~mask_trunc);

    unsigned lsb_val = (e_real == 0) ? 1u : ((fraction >> (23 - e_real)) & 1u);
    if ((leftover > half_point) || (leftover == half_point && lsb_val)) {
        truncated_frac += (1u << shift_amt);
    }
    if (truncated_frac >= (1u << 23)) {
        truncated_frac = 0u;
        exponent += 1u;
    }
    return sign_bit | (exponent << 23) | truncated_frac;
}


// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
   if (x == 0) return 0u;
    if (x == 0x80000000) return 0xCF000000u;
    unsigned sign = x & 0x80000000u;
    unsigned v;
    if (x < 0) v = -x; else v = x;
    int e = 0;
    while ((v & 0x80000000u) == 0) { v <<= 1; e--; }
    e += 31;
    unsigned frac = (v >> 8) & 0x7FFFFFu;
    unsigned rest = v & 0xFFu;
    if ((rest > 0x80u) || (rest == 0x80u && (frac & 1u))) {
        frac++;
        if (frac >= 0x800000u) { frac = 0; e++; }
    }
    return sign | ((e + 127) << 23) | frac;
}




// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
int m_0x55 = 0x55;
    int m_0x33 = 0x33;
    int m_0x0F = 0x0F;

    m_0x55 = m_0x55 | (m_0x55 << 8);
    m_0x55 = m_0x55 | (m_0x55 << 16);

    m_0x33 = m_0x33 | (m_0x33 << 8);
    m_0x33 = m_0x33 | (m_0x33 << 16);

    m_0x0F = m_0x0F | (m_0x0F << 8);
    m_0x0F = m_0x0F | (m_0x0F << 16);

    x = (x & m_0x55) + ((x >> 1) & m_0x55);
    x = (x & m_0x33) + ((x >> 2) & m_0x33);
    x = (x & m_0x0F) + ((x >> 4) & m_0x0F);

    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x3F;
}


// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
int mask1 = 0x55 | (0x55 << 8);
    mask1 = mask1 | (mask1 << 16);

    int mask2 = 0x33 | (0x33 << 8);
    mask2 = mask2 | (mask2 << 16);

    int mask4 = 0x0F | (0x0F << 8);
    mask4 = mask4 | (mask4 << 16);

    int mask8lo = 0xFF | (0xFF << 16);
    int mask8hi = mask8lo << 8;

    int mask16lo = 0xFF | (0xFF << 8);
    int mask16hi = mask16lo << 16;

    x = ((x >> 1) & mask1) | ((x & mask1) << 1);
    x = ((x >> 2) & mask2) | ((x & mask2) << 2);
    x = ((x >> 4) & mask4) | ((x & mask4) << 4);
    x = ((x >> 8) & mask8lo) | ((x << 8) & mask8hi);
    x = ((x >> 16) & mask16lo) | ((x << 16) & mask16hi);
    return x;
}

