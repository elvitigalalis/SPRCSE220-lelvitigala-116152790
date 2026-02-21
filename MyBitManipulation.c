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
  uint32_t mask = 1u << pos; // We put 1u to signify 1 is unsigned (so no sign bit).
  return num ^ mask; 
}

/*
 * Return the position of the most significant set bit
 * Return -1 if num == 0
 */
int GetMSB(int num) {
  for (int i = 31; i >= 0; i--) {
    uint32_t mask = 1u << i; // Shifts left by i bits.
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

  uint32_t length = end - start + 1;
  uint32_t mask = (1u << length) - 1; // -1 will turn all ending 0s to 1s.
  return (num & (~(mask << start)));
}

/*
 * Rotate num to the left by d bits
 */
uint32_t RotateLeft(uint32_t num, int d) {
  d &= 31; // This will do the same thing as d % 32 but faster! It basically just prunes everything but the least significant 5 digits.
  if (d == 0) return num;
  uint32_t temp_bits = num >> (32 - d);
  return ((num << d) | temp_bits);
}

/*
 * Swap odd and even bits
 */
int SwapOddEvenBits(int num) {
  uint32_t even_bits_mask = 0xAAAAAAAA;
  uint32_t odd_bit_mask = 0x55555555;

  return (((num & even_bits_mask) >> 1) | ((num & odd_bit_mask) << 1));
}
