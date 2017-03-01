// reverse bits(32 bits)
#include <bitset>
#include <iostream>

using namespace std;

void printBit(uint32_t a) { cout << std::bitset<32>(a) << endl; }

// shift bit
uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  for (int i = 0; i < 32; i++) {
    if (n & 1 == 1) {       //检查n最后一位是否为1
      res = (res << 1) + 1; //为1，res左移后,末位置1
    } else {
      res <<= 1; //不为1，res左移
    }
    n >>= 1; // 不断右移
  }
  return res;
}

// concise above
uint32_t reverseBits2(uint32_t n) {
  uint32_t res = 0;
  for (int i = 0; i < 32; i++, n >>= 1) {
    res = (res << 1) | (n & 1);
  }
  return res;
}

// swap bit
uint32_t swapBits(uint32_t x, int i, int j) {
  int lo = ((x >> i) & 1);
  int hi = ((x >> j) & 1);
  if (lo ^ hi) {
    x ^= ((1 << i) | (1 << j));
  }
  return x;
}
uint32_t reverseBits3(uint32_t n) {
  uint32_t res = n;
  for (int i = 0; i < 32 / 2; i++) {
    res = swapBits(res, i, 32 - i - 1);
  }
  return res;
}

// magic
// for 8 bit binary number abcdefgh, the process is as follow:
// abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
uint32_t reverseBits(uint32_t n) {
  n = (n >> 16) | (n << 16);
  n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
  n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
  n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
  n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
  return n;
}

// follow up
/* How to optimize if this function is called multiple times? We can divide an
 * int into 4 bytes, and reverse each byte then combine into an int. For each
 * byte, we can use cache to improve performance.*/

class Solution {
  // cache
private
  final Map<Byte, Integer> cache = new HashMap<Byte, Integer>();
public
  int reverseBits(int n) {
    byte[] bytes = new byte[4];
    for (int i = 0; i < 4; i++) // convert int into 4 bytes
      bytes[i] = (byte)((n >>> 8 * i) & 0xFF);
    int result = 0;
    for (int i = 0; i < 4; i++) {
      result += reverseByte(bytes[i]); // reverse per byte
      if (i < 3)
        result <<= 8;
    }
    return result;
  }

private
  int reverseByte(byte b) {
    Integer value = cache.get(b); // first look up from cache
    if (value != null)
      return value;
    value = 0;
    // reverse by bit
    for (int i = 0; i < 8; i++) {
      value += ((b >>> i) & 1);
      if (i < 7)
        value <<= 1;
    }
    cache.put(b, value);
    return value;
  }
};

int main() {
  uint32_t a = 15;
  printBit(reverseBits3(12));
}