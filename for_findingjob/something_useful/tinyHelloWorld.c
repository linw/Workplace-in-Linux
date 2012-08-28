/*
 * =====================================================================================
 *
 *       Filename:    tinyHelloWorld.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-06 11:56:01
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
char* str = "Hello world!\n";
void print()
{
  asm("movl $13,%%edx \n\t"
      "movl $0,%%ecx \n\t"
      "movl $0,%%ebx \n\t"
      "movl $4,%%eax \n\t"
      "int $0x80     \n\t"
      ::"r"(str):"edx","ecx","ebx");
}

void exit()
{
  asm("movl $42,%ebx \n\t"
      "movl $1,%eax \n\t"
      "int $0x80    \n\t");
}

void nomain()
{
  print();
  exit();
}
