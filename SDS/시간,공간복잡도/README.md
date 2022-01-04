# 시간 복잡도와 공간 복잡도

## 자료형
![자료형 사이즈](https://mblogthumb-phinf.pstatic.net/MjAxODA1MjdfODUg/MDAxNTI3MzU3NzMwMTYx.iN8KiR5NxD1EAj5_YwI-do5Bg_oSrDKIfxHTMx3uA3sg.Hdt-65mOu21j5i6afFrFYUGHrrA4LAJI_wg0k1RiJpog.PNG.heartflow89/image.png?type=w800)

## bit연산 예제
[github - cpbook](https://github.com/stevenhalim/cpbook-code/blob/master/ch2/lineards/bit_manipulation.cpp)
```c++
    #define isOn(S, j) (S & (1<<j))
    #define setBit(S, j) (S |= (1<<j))
    #define clearBit(S, j) (S &= ~(1<<j))
    #define toggleBit(S, j) (S ^= (1<<j))
    #define lowBit(S) (S & (-S))
    #define setAll(S, n) (S = (1<<n)-1)

    #define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
    #define isPowerOfTwo(S) (!(S & (S-1)))
    #define nearestPowerOfTwo(S) (1<<lround(log2(S)))
    #define turnOffLastBit(S) ((S) & (S-1))
    #define turnOnLastZero(S) ((S) | (S+1))
    #define turnOffLastConsecutiveBits(S) ((S) & (S+1))
    #define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))
```

