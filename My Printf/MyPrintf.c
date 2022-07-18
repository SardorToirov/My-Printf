#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int  my_putchar(char c){
    write(1, &c, 1);
    return 1;
}


int my_printstr(char* s){

    
    int i = 0; 
    while(i<strlen(s)){
        my_putchar(s[i]);
        i++;
    }
    return i;
}


char*  contento(int o){
    long dec, quot;
    int octnum[100], i=1,j;
    dec = o;
    int sum =0;
    quot = dec;
    while (quot !=0){
        octnum[i++] =quot % 8;
        quot = quot /8;
        sum++;
    }
    char *str;
    str = (char*)malloc(sizeof(char)*sum);
    sum=0;
    for (j= i-1; j>0;j--){
        str[sum++]=octnum[j]+'0';
    }
    return str;
}
char *decimalToHexadecimal(long int decimalNumber)
{
      long int quot;
      long int rem;
      static char hexDecNum[100];
    
      quot = decimalNumber;
      int i = 0,sum=0,j;
      while (quot != 0)
      {
        rem = quot % 16;
    
        if (rem < 10)
        {
          rem = rem + 48;
        }
        else
        {
          rem = rem + 55;
        }
       hexDecNum[i++] = rem;
      quot = quot / 16;
      }
        hexDecNum[i] = 0;
            char *str;
    str = (char*)malloc(sizeof(char)*i);
        for (j= i-1; j>=0;j--){
        str[sum++]=hexDecNum[j];
    }
      return str;           
}

int sonchar(int d,char x){
    if(x=='u'){
       d = d * -1;
    }

    int b=0;
    if(d < 0){
      d= d * -1;
      b++;
    }
    
    int* p;
    int i=0;
    int a=0;

    if(d==0){
        my_printstr("0");
        i++;
    }
    else{
    p=(int*)malloc(sizeof(int)*1000);

    while(d!=0){
        p[i]=d%10;
        d=d/10;
        i++;
    }
    char*joy1;
    joy1=(char*)malloc(sizeof(int)*i+1);
    if(b==1){
        joy1[0]='-';
        a++;
    }
    for(int j = i-1;j>=0;j--){
        joy1[a]=p[j]+'0';
        a++;
    } 
    i = my_printstr(joy1);
    }
    return i;
}
char* sendaddress(unsigned long int x, int col){
    unsigned long int firstnum = x;
    unsigned int len = 0;
    char* result = NULL;
    unsigned long int temp_n;

    firstnum = firstnum > 0 ? firstnum : -(firstnum);
    while(x){
        x = x/col;
        len++;
    } 
    if(!(result = (char*)malloc(sizeof(char) * len + 1))){
        return NULL;
    }
    *(result + len) = '\0';
    len--;
    while(firstnum > 0){
        temp_n = firstnum % col;
        if(temp_n < 10)
            *(result + len) = temp_n + '0';
        else 
            *(result + len) = ((temp_n)-10 + 97);
        firstnum = firstnum / col;
        len--;
    }
    return result;
}

int my_printf(char* str, ...){
    va_list royhat;
    va_start(royhat ,str);
    char* string = NULL;
     intptr_t value_p;
      int len;
    char joy;
    int x=0;
    char* joylar;
    int* p;
    int sonjoy;

    for(int i=0;i<strlen(str);i++){
        if(str[i]=='%'){
            i++;
       
            switch (str[i]) {
                case 'c':
                    joy = (char) va_arg(royhat, int);   
                    x++;
                    my_putchar(joy);
                break;

                case 's':
                    joylar =va_arg(royhat ,char*);
                    if(string==(char*)NULL){
                        string= "(null)";
                    }
                     x+= my_printstr(string);
                   
                break;

                case 'd':
                    sonjoy=va_arg(royhat ,int);
                    x+=sonchar(sonjoy, 'd');
                break;
                case 'u':
                    sonjoy=va_arg(royhat ,int);
                    x+=sonchar(sonjoy, 'u');
                break;

                case 'o':
                    sonjoy = va_arg(royhat, int);
                    x+= my_printstr(contento(sonjoy));
                break;
                
                case 'x':
                    sonjoy = va_arg(royhat, int);
                    x+= my_printstr(decimalToHexadecimal(sonjoy));
                break;
                  case 'p':
                    value_p = va_arg(royhat, intptr_t);
                    string = sendaddress(value_p, 16);
                    write(1, "0x", 2);
                    len = my_printstr(string);
                    x += len+2;
                break; 
            }
            
        }
        else{
           x+= my_putchar(str[i]);
        }
    }
    return x;
}


int main(){
    int j = my_printf("%p!\n","hgkiiugiguel");
    printf("%d", j);
    
    return 0;
}