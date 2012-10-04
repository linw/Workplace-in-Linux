#include <stdio.h>
#include <string.h>

main()
{
  int n,i,j;
  char letter[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
  char (*num)[8];
  char c;
  scanf("%d",&n);
  num = (char*)malloc(sizeof(char)*8*n);
  for(i = 0; i < n; ++i){
    j = 0;
    while((c = getchar())!='\n'){
      if(c>='0'&&c<='9'){
	num[i][j++] = c; 
	continue;
      }
      if(c>='A'&&c<='Y'){
	num[i][j++] = letter[c-'A'];
	continue;
      }
    }
    num[i][j] = '\0';
  }
}
