/*
 * =====================================================================================
 *
 *       Filename:    main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-20 14:14:55
 *       Compiler:    vc6.0
 *       Description: 利用一个字节的存储空间来解决中国象棋中将帅位置问题。
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)

#define RMASK (FULLMASK >> HALF_BITS_LENGTH)

#define RSET(b,n) (b = ((LMASK & b)| (n)))

#define LSET(b,n) (b = ((RMASK & b)| (n)<< HALF_BITS_LENGTH))

#define RGET(b) (RMASK & b)

#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)

#define GRIDW 3

void print_result(){
    unsigned char b = 9;
    for(LSET(b, 1); LGET(b) <= GRIDW; LSET(b,(LGET(b)+1)))
        for(RSET(b,1);RGET(b) <= GRIDW * GRIDW; RSET(b,(RGET(b) + 1)))
            if(LGET(b) % GRIDW != RGET(b) % GRIDW)
                printf("A \ %d, B = %d\n", LGET(b), RGET(b));

}

int main(int argc, char **argv)
{
    print_result();
    return 0;
}
