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

  /* PART 2: Float Construction */
  float f = construct_float_sf(0x00, 0x7F, 0x200000);
  printf("Float value = %g\n", f);

  /* PART 3: Integer Representation Conversion */
  repr_convert('2', '2', 0x59f2ca50);

  return 0;
}
