/* Name: Lisul Elvitigala
 * ID: 116152790
 */
#include "MyIntegers.h"
#include <stdbool.h>
#include <stdio.h>

void repr_convert(char source_repr, char target_repr, unsigned int repr) {
  // This checks if both representations are valid options.
  if ((source_repr != '2' && source_repr != 'S') || (target_repr != '2' && target_repr != 'S')) {
    printf("error\n");
    return;
  }

  unsigned int final_result = 0;
  if (source_repr == target_repr) {
    printf("%08x\n", repr);
    return;
  }
  
  // I decided to use goto method whenever we have to print a hexademical output to avoid code repetition.
  // 'S' (sign/mag) --> '2' (two's complement)
  if (source_repr == 'S' && target_repr == '2') {
    unsigned int sign_bit = (repr >> 31) & 1u;
    unsigned int magnitude = repr & (~0u >> 1u);
    if (sign_bit == 0u) {
      final_result = magnitude;
      goto print_final_hex;
    } else if (sign_bit == 1u) {
      final_result = (~magnitude) + 1u;
      goto print_final_hex;
    }
  }

  // '2' (two's complement) --> 'S' (sign/mag)
  if (source_repr == '2' && target_repr == 'S') {
    if (repr == 0x80000000) { // This is -2^31, a number two's complement can represent but not sign/mag
      printf("undefined\n");
      return;
    }
    
    unsigned int sign_bit = (repr >> 31) & 1u;
    if (sign_bit == 0u) {
      final_result = repr;
      goto print_final_hex;
    } else if (sign_bit == 1u) {
      final_result = (1u << 31) | ~(repr - 1u); // Gets positive value (magnitude), then I set MSB to 1 to indicate negative number
      goto print_final_hex;
    }
  }

  print_final_hex:
    if (final_result == 0x80000000 && target_repr == 'S') {
      final_result = 0x00000000; // Eliminates the +0 and -0 issue.
    }
    printf("%08x\n", final_result); // %08x to add leading zeroes whenever length is less than 8 digits
    return;
}
