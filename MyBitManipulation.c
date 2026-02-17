/* Name: Lisul Elvitigala
 * ID: 116152790
 */
// HW3 Starter Code

#include "MyBitManipulation.h"
#include <stdio.h>

/*
 * Toggle the bit at position pos in num
 */
int ToggleBit(int num, int pos) {
  if (pos < 0 || pos > 31) {
    return num; // Invalid position, so we don't need to modify anything.
  }
  unsigned int mask = 1u << pos; // We put 1u to signify 1 is unsigned (so no sign bit).
  return num ^ mask; 
}

/*
 * Return the position of the most significant set bit
 * Return -1 if num == 0
 */
int GetMSB(int num) {
  for (int i = 31; i >= 0; i--) {
    unsigned int mask = 1u << i;
    if ((num & mask) != 0) {
      return i;
    }
  }
  return -1;
}

/*
 * Clear bits from start to end (inclusive)
 */
int ClearBitRange(int num, int start, int end) {
  if (start == 0 && end == 31) {
    return 0; // Clearing all bits.
  }
  if (start < 0 || end > 31 || start > end) {
    return num; // Invalid range.
  }

  unsigned int length = end - start + 1;
  unsigned int mask = (1u << length) - 1; // -1 will turn all ending 0s to 1s.
  return (num & (~(mask << start)));
}

/*
 * Rotate num to the left by d bits
 */
uint32_t RotateLeft(uint32_t num, int d) {
  /* TODO: implement */
  return num;
}

/*
 * Swap odd and even bits
 */
int SwapOddEvenBits(int num) {
  /* TODO: implement */
  return num;
}
