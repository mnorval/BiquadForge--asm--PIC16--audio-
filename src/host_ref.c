#include <stdio.h>
#include <stdint.h>
typedef struct { int16_t b0,b1,b2,a1,a2,z1,z2; } BQ;
int16_t tick(BQ* f, int16_t x) {
  int32_t y = (int32_t)f->b0*x + (int32_t)f->b1*f->z1 + (int32_t)f->b2*f->z2;
  y -= (int32_t)f->a1*f->z1 + (int32_t)f->a2*f->z2;
  y >>= 8;
  f->z2=f->z1; f->z1=(int16_t)y;
  return (int16_t)y;
}
int main(void){
  BQ f={.b0=40,.b1=80,.b2=40,.a1=20,.a2=10};
  printf("BiquadForge Q8 impulse\n");
  for(int n=0;n<12;++n) printf("  n=%2d y=%d\n", n, tick(&f, n==0?256:0));
}
