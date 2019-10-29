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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	//写出与运算真值表，然后尝试给两个自变量取反变形，得出与运算如何用取反和或运算表示
	return ~(~x | ~y);
}


/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	//先算出要取的是哪几个bit(byte要换算成bit)，然后移位取最低8位即可
	int bitShift = n << 3;
	x >>= bitShift;
	return x & 0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	//把最高位分离出来，先右移低位，然后再把最高位放到新位置
	int MSB = x & (1 << 31);
	int newMSB;
	x &= ~(1 << 31); x >>= n;
	newMSB = (1 << 32 + ~n) & (MSB >> 31); x |= newMSB;
	return x;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int n) {
	//二分思想。先将n写成二进制形式，然后相邻位相加，循环进行直到只剩下一位。
	int BIT4_55 = 0x55 + (0x55 << 8), BIT8_55 = BIT4_55 + (BIT4_55 << 16); //0x55555555。因为禁止使用大于0xff的常数，只能使用这种土办法。
	int BIT4_33 = 0x33 + (0x33 << 8), BIT8_33 = BIT4_33 + (BIT4_33 << 16); //0x33333333
	int BIT4_0F = 0x0f + (0x0f << 8), BIT8_0F = BIT4_0F + (BIT4_0F << 16); //0x0f0f0f0f
	int BIT_00FF = 0xff + (0xff << 16); //0x00ff00ff
	int BIT_FFFF = 0xff + (0xff << 8); //0x0000ffff
	n = (n & BIT8_55) + ((n >> 1) & BIT8_55); //第1位和第2位相加 3和4 5和6 7和8 ...... 31和32
	n = (n & BIT8_33) + ((n >> 2) & BIT8_33); //1+2+3+4 5+6+7+8 ...... 29+30+31+32
	n = (n & BIT8_0F) + ((n >> 4) & BIT8_0F); //1+...+8 ...... 25+...+32
	n = (n & BIT_00FF) + ((n >> 8) & BIT_00FF); //1+...+16 17+...+32
	n = (n & BIT_FFFF) + ((n >> 16) & BIT_FFFF); //1+...+32，即为所求
	return n;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	//主要是判断所有位的或运算结果是否为1。因为操作符数量有限，必须通过二分法的思想来优化。
	int x16, x8, x4, x2, x1;
	x16 = x >> 16; x |= x16; //高16位和低16位相或，结果为16位
	x8 = x >> 8; x |= x8; //将上一步的结果拿来，高8位和低8位相或，后面类似
	x4 = x >> 4; x |= x4;
	x2 = x >> 2; x |= x2;
	x1 = x >> 1; x |= x1;
	return (x & 1) ^ 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	//由补码表示的规则易得答案
	return 1 << 31;
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
	//n位补码的表示范围是[-(1 << n-1), 1 << n-1)
	//我们使x += 1 << n-1，就变为[0, 1 << n)
	//然后只需判断在第n+1位到第32位上是否还有1，若有，则不能表示。
	//n=32的时候，x += 1 << 31会影响到符号位
	//所以在进行上述判断的时候算术移位会出错，需特判。
	int n32 = n >> 5;
	x += (1 << (n + (~0)));
	x >>= n;
	return !x | n32;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	//思路来源于书上的“纠偏”。另外要注意，减1只能用+(~0)表示。
	int b = (x >> 31) & ((1 << n) + (~0));
    return (x + b) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	//由补码表示的规则易得答案
	return (~x) + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	//若x=0，用!x特判；若x!=0，直接取出符号位
	return !((x >> 31 & 1) | (!x));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	//若x和y异号，直接讨论x和y各自的正负
	//若x和y同号，判断y-x的正负性
	int sgnx = x >> 31 & 1;
	int sgny = y >> 31 & 1;
	int r1 = sgnx & 1;
	int dir = sgnx ^ sgny;
	int subyx = y + ((~x) + 1);
	int r2 = !(subyx >> 31);
	return (r1 & dir) | (r2 & !dir);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	//倍增思想
	//记r为需要右移的位数，初始r=0。将x与0xffff比较，如果比0xffff大，说明至少需要右移16位；r += 16（即1<<4 = 10000b）；并将此数右移16位进行更新；如果比0xffff小，什么都不做；r += 0。将更新后的数与0xff比较……依此类推，最后与1比较后得到的r即为最高位所在的位。
	int ffff = (0xff << 8) + 0xff;
	int r, shift;
	r = !!(x & (ffff << 16)) << 4; x >>= r;
	shift = !!(x & (0xff << 8)) << 3; x >>= shift; r |= shift;
	shift = !!(x & (0xf << 4)) << 2; x >>= shift; r |= shift;
	shift = !!(x & (0x3 << 2)) << 1; x >>= shift; r |= shift;
	r |= (x >> 1);
	return r;
}
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
	//NaN只有两种情况，特判即可
	//对于非NaN，翻转符号位
	int abs = uf & ~(1 << 31);
	int jm = abs >> 23;
	if (jm == 0xff && abs != 0xff << 23) return uf;
	else return uf ^ (1u << 31);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	//先定符号，然后定阶码（取决于最高的1所在位数），最后定尾数（是原来数中去掉最高位1以后剩余的部分，但不能弃掉前导0；位数不足则左移补0，位数超出则右移且要考虑舍入，如果进位还可能影响阶码）
	unsigned int res = x > 0 ? 0 : 0x80000000, abs, cabs, qjm = 0x807fffff; //x &= qjm相当于将阶码所在的8个位置0，即“去阶码”
	int hiPos = 0, jm, b26e, b25; //最高位所在位；尾数第26位至尾部; 尾数第25位
	if (x == 0) return 0; //特判
	if (x == -2147483648) abs = x;
	else abs = x < 0 ? -x : x; //定符号位
	cabs = abs; b26e = 0;
	while (cabs >= 0x2000000) {b26e |= cabs & 1; cabs >>= 1;} //如果尾数过长，保留低24位，同时计算尾数第26位以后有没有1，作为舍入依据
	if (cabs >= 0x1000000) {
		b25 = cabs & 1;
		if (b25 && (b26e || (cabs & 2))) cabs++; //25位为1且26位以后还有1，进位；25位为1且24位为1，进位（保留偶数）
		cabs >>= 1; //保留低24位
		if (cabs >= 0x1000000) {hiPos = 1; cabs >>= 1;} //进位可能影响到最高位所在位，此处予以处理
	}
	while (cabs < 0x800000) cabs <<= 1; //如果尾数过短，则在低位补0
	res |= cabs; res &= qjm; //将24位的尾数并入res中，并且通过“去阶码”去掉最高位上的1（因为浮点数整数部分的1是缺省的）
	cabs = abs;
	while (cabs > 0) {hiPos++; cabs >>= 1;}
	jm = 126 + hiPos; jm <<= 23; res |= jm; //计算阶码
	return res;
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
	//分类讨论。无穷大和NaN（阶码全1）直接返回。0和非规格化数（阶码全0）直接左移1位，但要单独处理符号位。规格化数（其它情况）阶码加1。
	int abs = uf & ~(1 << 31);
	int jm = abs >> 23;
	unsigned int qjm = 0x807fffff;
	if (jm == 0xff) return uf; //NaN和无穷大
	if (jm == 0) return (uf << 1) | (uf & 0x80000000); //非规格化数和0
	jm++; jm <<= 23;
	uf &= qjm; uf |= jm; //阶码加1
	return uf;
}
