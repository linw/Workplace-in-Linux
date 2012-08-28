/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-24 22:18:55
 *       Last Edit:   2012-6-3 18:00:15
 *       Compiler:    gcc
 *       Description: pointers on c chaper8 exercises
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
// problem 1: 统计各类字符所占百分比
int type_to_int(const char c)
{
  if(iscntrl(c)) return 1;
  if(isspace(c)) return 2;
  if(isdigit(c)) return 3;
  if(islower(c)) return 4;
  if(isupper(c)) return 5;
  if(ispunct(c)) return 6;
  if(!isprint(c)) return 7;
}
void print_per(const char* ss)
{
  int type_per[8];
  char type[7][20];
  int i;
  strcpy(type[0],"contrl:");
  strcpy(type[1],"space:");
  strcpy(type[2],"digit:");
  strcpy(type[3],"lower:");
  strcpy(type[4],"upper:");
  strcpy(type[5],"punct:");
  strcpy(type[6],"none print:");
  for(i = 0; i < 8; ++i)
    type_per[i] = 0;
  while(*ss){
    ++type_per[type_to_int(*ss)];
    ++type_per[0];
    ++ss;
  }
  for(i = 0; i < 7; ++i){
    printf("%s:%f\n",type[i],(double)type_per[i+1]*100/type_per[0]);
  }    
}

// problem 2: my_strlen实现
char *my_strlen(char *ss,const size_t len)
{
  assert(len>=0);
  int i;
  i = 0;
  while(i != len){
    ++i;
  }
  *(ss+i) = '\0';
  return ss;
}


// problem 3: my_strcpy的实现
char *my_strcpy(char *dir,char const *sou, const int dir_len)
{
  int i = 0;
  char *p;
  p = dir;
  // 下面这段代码提示错误(i++<dir_len-1),赋值运算的左操作数必须是左值
  while((i++<dir_len-1) && (*dir++ = *sou++)){
  }
  *dir = '\0';
  return p;
}


// problem 4: my_strcat函数实现
void my_strcat(char *dest, char *src, const int dest_len)
{
  int i,len;
  char *p;
  char *q;
  i = len = 0;
  p = dest;
  q = src;
  while(*p++){
    ++len;
  }
  --p;
  assert(dest_len>=len);
  while((len++ < dest_len) && (*p++ = *q++)){
    /* ++len; */
  }
  *p = '\0';
}


// problem 6: 实现my_strcpy_end()函数
char *my_strcpy_end(char *dest, char const *src)
{
  while(*(dest++) = *(src++));
  return dest;  
}


// problem 7: 编写my_strrchr()
char *my_strrchr( char const *str, int ch)
{
  char *dir;
  dir = 0;
  while(*str){
    if(*str == ch) dir = str;
    ++str; 
  }
  return dir;
}


// problem 8: 编写my_strnchr函数
char *my_strnchr(char const *str, int ch, int which)
{
  int count;
  char c;
  char *p;
  count = 0;
  p = 0;
  while(c = *(str++)){
    if(c == ch) ++count;
    if(count == which) {
      p = str - 1;
      break;
    }
  }
  return p;
}

// problem 9: 编写字符串查找函数
int count_chars( char const *str, char const *chars)
{
  int count;
  char c;
  char cc;
  char *p_chars;
  count = 0;
  while(c = *(str++)){
    p_chars = chars;
    while(cc = *(p_chars++)){
      if(cc == c) {
	++count;
	break;
      }
    }
  }
  return count;
}


// problem 10: 编写函数判断是否为回文
int palindrome( char const *string)
{
  int i,j;
  i = j = 0;
  while(string[j]){++j;}
  --j;
  while(i<j){
    if(!isalpha(string[i])) { ++i; continue;}
    if(!isalpha(string[j])) { --j; continue;}
    if(string[i] == string[j]){
      ++i;
      --j;
    }
    else break;
  }
  if(i>=j) return 1;
  return 0;
}


// problem 11: 计算字符串中单词the的个数
char *get_next_word_start(char const *str)
{
  if(!isalpha(*str)) {
    while(*str&&!isalpha(*str)){
      ++str;
    }
  }
  else {
    while(*str&&isalpha(*str)){
      ++str;
    }
    while(*str&&!isalpha(*str)){
      ++str;
    }
  }
  return str;
}
int cal_word(char const *str, char const *word)
{
  int count;
  char *p_word;
  int is_start;
  is_start = 0;
  count = 0;
  str = get_next_word_start(str);
  p_word = word;
  while(*str){
    if(*p_word && (*str == *p_word)){
      ++str;
      ++p_word;
      continue;
    }
    if(!isalpha(*str) && (*p_word == '\0')){
      ++count;
      /* str = get_word_start(str); */
      /* p_word = word; */
    }
    str = get_next_word_start(str);
    p_word = word;
  }
  return count;
}


// probem 12,13,14: 数据加密
int prepare_key(char *key)
{
  int alpha[26] = {0};
  int i,j;
  char *p = key;
  if(key == NULL) return 0;
  else {
    while(*key){
      if(!isalpha(*key)) {
	return 0;
      }
      *key = toupper(*key);
      alpha[*key - 'A'] = 1;
      ++key;
    }
  }
  for(i = 0,j = 0; p[i]; ++i){
    if(alpha[p[i] - 'A'] == 1){
      alpha[p[i]-'A'] = 2;
      p[j] = p[i];
      ++j;
    }
  }
  for(i = 0; i < 26; ++i){
    if(!alpha[i]){
      p[j] = i + 'A';
      ++j;
    }
  }
  p[j] = '\0';
  /* printf("%d\n",strlen(p)); */
  return 1;
}

void encrypt( char *data, char const *key)
{
  char *p;
  p = data;
  while(*p){
    *p = toupper(*p);
    ++p;
  }
  while(*data){
    if(!isalpha(*data)){
      ++data;
      continue;
    }
    *data = key[(*data) - 'A'];
    ++data;    
  }
}

void decrypt(char *data,char const *key)
{
  char *p = data;
  int i;
  while(*data){
    if(!isalpha(*data)) {
      ++data;
      continue;
    }
    *data = toupper(*data);
    for(i = 0; key[i]; ++i)
      if(*data == key[i]) break;
    *data = i + 'A';
    ++data;
  }
}


// problem 15: 实现数字加逗号
void dollars(char *dest, char const *src)
{
  int len;
  int i;
  if(dest == NULL || src == NULL)
    return;
  *dest++ = '$';
  len = strlen(src);
  if(len >=3){
    for(i = len-2;i>0;){
      *dest++ = *src++;
      if(--i>0 && i%3 == 0)
	*dest++ = ',';
    }
  }
  else {
    *dest++ = '0';
  }

  *dest++ = '.';
  *dest++ = len<2?'0':*src++;
  *dest++ = len < 1 ? '0':*src++;
  *dest = '\0';
}


// problem 16: 格式化输出
void reverce( char *str )
{
  char *p;
  assert(str);
  p = str;
  while(*p) ++p;
  --p;
  while(str<p){
    *str ^= *p;
    *p ^= *str;
    *str ^= *p;
    ++str;
    --p;
  }
}
int format( char *format_string, char const *digit_string)
{
  char *p;
  char *q;
  int len,len1;
  len = 0;
  assert(format_string&&digit_string);
  len1 = strlen(digit_string);
  p = format_string;
  while(*p){
    if(*p++ == '#') ++len;
  }
  if(len < len1) return 0;
  reverce(format_string);
  reverce(digit_string);
  p = format_string;
  q = digit_string;
  while(*digit_string){
    if(*format_string == '#') {
      *format_string++ = *digit_string++;
    }
    else if(*format_string == '.'||
	    *format_string == ','){
      ++format_string;
    }
  }
  while(*format_string){
    *format_string = '@';
    ++format_string;
  }
  reverce(p);
  reverce(q);
  return 1;
}



// problem 17: 更加一般的格式化输出





main()
{
  /* char a[1000]; */
  /* strcpy(a,"Hello"); */
  /* strcat(a," World"); */
  /* printf("%s\n",a); */
  /* if(strncmp("abc","abcd",4) == 0) */
  /*   printf("yes\n"); */
  /* strncat(a,"Hello linwei",10); */
  /* printf("%s\n",a); */
  /* strncpy(a,"aaaaaaaaaa",5); */
  /* //  a[5] = 0; */
  /* printf("%s\n",a); */
  /* printf("%s\n",strrchr(a,'l')); */
  /* printf("%s\n",strpbrk(a,"abc")); */
  /* printf("%s\n",strstr("kilwnglw","lw")); */
  /* printf("%d\n",strspn("kinglw","lw")); */
  /* strcpy(a,"hello.linwei.world.python"); */
  /* strtok(a,"."); */
  /* printf("%s\n",a+6); */
  /* printf("%s\n",strerror(1)); */
  char a[100];
  char data[100];
  int i,j;
  char *p;
  for(i = 0; i < 100; ++i)
    a[i] = 'a';
  print_per("kinglwsjkdfjsm,d.msdsdlfjoqifsdf5s4df51s45sdfdklf");
  p = strncpy(a,"helloworld",5);
  printf("%s\n",a);
  my_strlen(a,5);
  printf("%s\n",a);
  my_strcpy(a,"kinglwskdjfsldkfjsdkfjdddddddddddddddddddddddddddddddfksjdkfjsdkfjsdf\
sdkfjsdkjlfksdljffffdkfj",100);
  printf("%s\n",a);
  my_strcat(a,"hello",100);
  printf("%s\n",a);
  printf("%s\n",my_strrchr("kinlsdkglw",'l'));
  printf("%s\n",my_strnchr("kinglwkinglwkinglw",'i',0));
  printf("%d\n",count_chars("aaaaaacda","abac"));
  /* if(palindrome("kinglwwlgnik")) printf("Yes"); */
  printf("%d\n",cal_word(".,/kinglw the,the lw,the the ","the"));
  strcpy(a,"trailblazers");
  strcpy(data,"attack at dawn");
  prepare_key(a);
  encrypt(data,a);
  printf("%s\n%s\n",data,a);
  decrypt(data,a);
  printf("%s\n",data);
  strcpy(a,"01234567890");
  dollars(data,a);
  printf("%s\n",data);
  strcpy(data,"#,###,###.##");
  strcpy(a,"1234235");
  format(data,a);
  //  reverce(a);
  printf("%s\n",data);
}
