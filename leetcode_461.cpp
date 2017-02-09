// hamming distance

int hammingDistance(int x, int y){
  int z = x^ y;
  int cnt = 0;
  while(z){
    cnt++;
    z &= (z-1);
  }
  return cnt;
}