#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int strlenght(string s)
{
  int l=0;
  while (s[l] !='\0')
      l++;
  return l;
}
int charlenght(char *s)
{
  int l=0;
  while (s[l] !='\0')
      l++;
  return l;
}
void printstring(char *s)
{
  int i=0;
  while(s[i] != '\0')
     printf("%c", s[i++]);
}

void spojdvastringa(char *s, string s1 ) //slicno strcat
{
  int i,j;
  i=0;
  while (s[i]!='\0') i++;
  for (j=i;j<i+strlenght(s1);j++)
      s[j]=s1[j-i];
}

string biblioteka(int cifra){
  string rec="aaaa";
  int i;
  if (cifra<4){
    i=0;
    while (cifra>0){
      rec[i]=rec[i]+1;
      cifra=cifra-1;
      i=i+1;
    }
    return rec;
  }
  else if (cifra%5==4){
    rec[0]=rec[0]+1;
    rec[1]=rec[1]+cifra+1;
    return rec;
  }
  else {
    rec[0]=rec[0]+5;
    cifra=cifra-5;
    i=1;
    while (cifra>0){
      rec[i]=rec[i]+1;
      cifra=cifra-1;
      i=i+1;
    }
    return rec;
  }
}
int dekbiblioteka(char *s, int i){
  int k, zbir=0, broj=0;
  int a[4];
  for (k=i;k<i+4;k++){
    a[k-i]=(int)s[k]-97;
    zbir=zbir+a[k-i];
  }
  if (zbir<4) return (a[0]+a[1]+a[2]);
  else if (a[0]==1) return (a[1]- a[0]);
  else return (a[0]+a[1]+a[2]+a[3]);
}
string desetice(string s){
  int i=0;
  for (i=0;i<strlenght(s);i++) s[i]=s[i]+6;
  return s;
}
void dekdesetice(char *s, int i){
  int k;
  for (k=i;k<i+4;k++) s[k]=s[k]-6;
}
string stotine(string s){
  int i=0;
  for (i=0;i<strlenght(s);i++) s[i]=s[i]+12;
  return s;
}
void dekstotine(char *s, int i){
  int k;
  for (k=i;k<i+4;k++) s[k]=s[k]-12;
}

void koder(int *a, int n, char *s){
  int i;
  if (n==1) spojdvastringa(s,biblioteka(a[0]));
  else if (n==2){
    int st=0; int d=0; int j=0;
    d=a[0];
    j=a[1];
    spojdvastringa(s,desetice(biblioteka(d)));
    spojdvastringa(s,biblioteka(j));
  }
  else{
    for (i=0;i<=n-3-(n%3);i=i+3){
      int st=0; int d=0; int j=0;
      st=a[i]; d=a[i+1]; j=a[i+2];
      spojdvastringa(s,stotine(biblioteka(st)));
      spojdvastringa(s,desetice(biblioteka(d)));
      spojdvastringa(s,biblioteka(j));
    }
    if (n%3==1){
      spojdvastringa(s,biblioteka(a[i]));
    }
    else if (n%3==2){
      spojdvastringa(s,desetice(biblioteka(a[i])));
      spojdvastringa(s,biblioteka(a[i+1]));
    }
  }
}

void dekoder(int *a, int m, char *s){
  int i,j;
  int n=m/4;
  if (m==4) a[0]=dekbiblioteka(s,0);
  else if (m==8){
    dekdesetice(s,0);
    a[0]=dekbiblioteka(s,0);
    a[1]=dekbiblioteka(s,4);
  }
  else{
    j=0; i=0;
    while(j<n-n%3){
      dekstotine(s,i);
      a[j]=dekbiblioteka(s,i);
      dekdesetice(s,i+4);
      a[j+1]=dekbiblioteka(s,i+4);
      a[j+2]=dekbiblioteka(s,i+8);
      j=j+3;
      i=i+12;
    }
    
    if (n%3==1){
      a[n-1]=dekbiblioteka(s,i);
    }
    else if (n%3==2){
      dekdesetice(s,i);
      a[n-2]=dekbiblioteka(s,i);
      a[n-1]=dekbiblioteka(s,i+4);
    }
  }
}


int main() {
  int n,i;
  
  printf("Unesite broj cifara broja za kodiranje:\n");
  scanf("%d", &n);
  int *a=(int*)malloc(n*sizeof(int));
  printf("Unesite cifre broja za kodiranje razdvojene razmakom:");
  for (i=0; i<n; i++) scanf("%d", &a[i]);
  char *s=(char*)malloc(n*4*sizeof(char));
  koder(a,n,s);
  printf("Vasa kodirana poruka: \n");
  printstring(s);
  printf(" \n");

  printf("Rezultat dekodiranja kodirane poruke: \n");
  int *a1=(int*)malloc(n*sizeof(int));
  dekoder(a1, 4*n, s);
  for (i=0;i<n;i++) 
    printf("%d ", a1[i]);

  /*char *s1=(char*)malloc(200*sizeof(char));
  printf("Unesite kodiranu poruku za dekodiranje:");
  scanf("%s", s1);
  int m1=charlenght(s1);
  s1 = (char*)realloc(s1,m1);
  int n1=m1/4;
  int *a1=(int*)malloc(n1*sizeof(int));
  dekoder(a1,m1,s1);
  for (i=0;i<n1;i++) 
  printf("%d ", a1[i]);*/

}