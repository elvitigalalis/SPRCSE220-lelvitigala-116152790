/* Name: Lisul Elvitigala
 * ID: 116152790
 */
#include "MyBitManipulation.h"
#include "MyIntegers.h"
#include "Myfloat.h"
#include <criterion/criterion.h>

/* =========================
 * PART 1: Bit Manipulation
 * ========================= */

Test(ToggleBit, examples) {
  cr_assert_eq(ToggleBit(9, 0), 8);
  cr_assert_eq(ToggleBit(9, 3), 1);
  cr_assert_eq(ToggleBit(0, 0), 1);
  cr_assert_eq(ToggleBit(1, 0), 0);
  cr_assert_eq(ToggleBit(9, -1), 9);
  cr_assert_eq(ToggleBit(9, 32), 9);
  cr_assert_eq(ToggleBit(9, 64), 9);
  cr_assert_eq(ToggleBit(0, 31), 2147483648u);
}

Test(GetMSB, examples) {
  cr_assert_eq(GetMSB(18), 4);
  cr_assert_eq(GetMSB(0), -1);
  cr_assert_eq(GetMSB(1), 0);
  cr_assert_eq(GetMSB(2), 1);
  cr_assert_eq(GetMSB(2147483647), 30);
  cr_assert_eq(GetMSB(-1), 31);
  cr_assert_eq(GetMSB(0x80000000), 31);
}

Test(ClearBitRange, examples) {
  cr_assert_eq(ClearBitRange(73, 1, 3), 65);
  cr_assert_eq(ClearBitRange(73, 0, 31), 0);
  cr_assert_eq(ClearBitRange(255, 0, 7), 0);
  cr_assert_eq(ClearBitRange(255, 8, 15), 255);
  cr_assert_eq(ClearBitRange(73, 3, 3), 65);
  cr_assert_eq(ClearBitRange(73, -1, 3), 73);
  cr_assert_eq(ClearBitRange(73, 1, 32), 73);
  cr_assert_eq(ClearBitRange(73, 5, 2), 73); 
  cr_assert_eq(ClearBitRange(0xFFFFFFFF, 0, 31), 0);
}

Test(RotateLeft, examples) {
  cr_assert_eq(RotateLeft(5, 1), 10);
  cr_assert_eq(RotateLeft(5, 2), 20);
  cr_assert_eq(RotateLeft(0, 5), 0);
  cr_assert_eq(RotateLeft(1, 31), 2147483648u);
  cr_assert_eq(RotateLeft(2147483648u, 1), 1u);
  cr_assert_eq(RotateLeft(305419896u, 4), 591751041u);
  cr_assert_eq(RotateLeft(3735928559u, 0), 3735928559u);
  cr_assert_eq(RotateLeft(3735928559u, 32), 3735928559u);
  cr_assert_eq(RotateLeft(5, 33), 10);
}

Test(SwapOddEvenBits, examples) {
  cr_assert_eq(SwapOddEvenBits(23), 43);
  cr_assert_eq(SwapOddEvenBits(0), 0);
  cr_assert_eq(SwapOddEvenBits(1), 2);
  cr_assert_eq(SwapOddEvenBits(2), 1);
  cr_assert_eq(SwapOddEvenBits(10), 5);
  cr_assert_eq(SwapOddEvenBits(-1), -1);
  cr_assert_eq(SwapOddEvenBits(0xAAAAAAAA), 0x55555555);
  cr_assert_eq(SwapOddEvenBits(0x55555555), 0xAAAAAAAA);
}

/* =========================
 * PART 2: IEEE 754 Float
 * ========================= */

Test(ConstructFloat, positive_examples) {
  float f;
  f = construct_float_sf(0x00, 0x7F, 0x200000);
  cr_assert_float_eq(f, 1.25, 0.00001);
  f = construct_float_sf(0x00, 0x81, 0x300000);
  cr_assert_float_eq(f, 5.5, 0.00001);
  f = construct_float_sf(0x00, 0x76, 0x299B6F);
  cr_assert_float_eq(f, 0.002588, 0.000001);
  f = construct_float_sf(0x00, 0x89, 0xABCDEF);
  cr_assert_float_eq(f, 1374.44, 0.01);
  f = construct_float_sf(0x00, 0x90, 0x7973C0);
  cr_assert_float_eq(f, 255439.0, 0.1);
  f = construct_float_sf(0x00, 0x00, 0x000000);
  cr_assert_float_eq(f, 0.0, 0.00001);
  f = construct_float_sf(0x03, 0x7F, 0x200000);
  cr_assert_float_eq(f, 0.0f, 0.0f);
  f = construct_float_sf(0x00, 0xFF, 0x000000);
  cr_assert_float_eq(f, 0.0f, 0.0f);
}

Test(ConstructFloat, negative_examples) {
  float f;
  f = construct_float_sf(0x01, 0x7F, 0x200000);
  cr_assert_float_eq(f, -1.25, 0.00001);
  f = construct_float_sf(0x01, 0x81, 0x300000);
  cr_assert_float_eq(f, -5.5, 0.00001);
  f = construct_float_sf(0x01, 0x76, 0x299B6F);
  cr_assert_float_eq(f, -0.002588, 0.000001);
  f = construct_float_sf(0x01, 0x89, 0xABCDEF);
  cr_assert_float_eq(f, -1374.44, 0.01);
  f = construct_float_sf(0x01, 0x90, 0x7973C0);
  cr_assert_float_eq(f, -255439.0, 0.1);
  f = construct_float_sf(0x03, 0x7F, 0x200000); 
  cr_assert_float_eq(f, 0.0f, 0.00001);
  f = construct_float_sf(0x01, 0xFF, 0x000000);
  cr_assert_float_eq(f, 0.0f, 0.0f);
  f = construct_float_sf(0x00, 0xFF, 0x000001);
  cr_assert_float_eq(f, 0.0f, 0.0f);
}

/* =========================
 * PART 3: Integer Conversion
 * ========================= */
/* NOTE:
 * We do NOT test output matching here.
 * Students are encouraged to visually inspect output.
 * TAs will use stronger hidden tests.
 */

Test(ReprConvert, basic_run) {
  repr_convert('2', '2', 0x59f2ca50);
  repr_convert('S', '2', 0x80000000);
  repr_convert('S', '2', 0x80000001);
  repr_convert('X', '2', 0x00676767);
  repr_convert('2', 'S', 0x80000000);
  repr_convert('S', 'S', 0x80000000);
}