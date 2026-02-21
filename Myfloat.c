/* Name: Lisul Elvitigala
 * ID: 116152790
 */
#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
  // If sign bit is anything other than 0 or 1, return 0.0 (signifies discarding)
  if (sign_bit != 0x00 && sign_bit != 0x01) {
      return 0.0f; 
  }
  unsigned int f = 0;

  // Take the char inputs --> we extract the bits necessary (and make a mask).
  uint32_t f_sign_bit = ((uint32_t) sign_bit) & 0x1u; // LSB, I added convert to uint32_t in case of signed char.
  uint32_t f_exponent = ((uint32_t) exponent) & 0xFFu; // 8 bits
  uint32_t f_fraction = ((uint32_t) fraction) & 0x7FFFFFu; // 23 bits (4 digits * 5 + 3 digits)

  if (f_exponent == 0xFFu) { // Inf and NaN protection.
      return 0.0f; // Returns the 0.0f discard value.
  }

  f |= (f_sign_bit << 31);
  f |= (f_exponent << 23);
  f |= f_fraction;
  
  return *(float *)&f;
}
