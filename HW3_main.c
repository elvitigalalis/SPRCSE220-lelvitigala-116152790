/* Name: Lisul Elvitigala
 * ID: 116152790
 */
#include "MyBitManipulation.h"
#include "MyIntegers.h"
#include "Myfloat.h"
#include <stdio.h>

int main(void) {

  /* PART 1: Bit Manipulation Tests */
  printf("ToggleBit(9, 0) = %d\n", ToggleBit(9, 0));
  printf("ToggleBit(9, 3) = %d\n", ToggleBit(9,3));
  printf("GetMSB(18) = %d\n", GetMSB(18));
  printf("GetMSB(0) = %d\n", GetMSB(0));
  printf("ClearBitRange(73, 1, 3) = %d\n", ClearBitRange(73, 1, 3));
  printf("ClearBitRange(73, 0, 31) = %d\n", ClearBitRange(73, 0, 31));
  printf("RotateLeft(5, 1) = %d\n", RotateLeft(5, 1));
  printf("RotateLeft(5, 2) = %d\n", RotateLeft(5, 2));
  printf("SwapOddEvenBits(23) = %d\n", SwapOddEvenBits(23));
  
  /* PART 2: Float Construction */
  float f = construct_float_sf(0x00, 0x7F, 0x200000);
  printf("Float value = %g\n", f);
  printf("f = %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));

  /* PART 3: Integer Representation Conversion */
  repr_convert('2', '2', 0x59f2ca50);

  return 0;
}
