#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
bool isPalindrome(char*);
void doPalindrome();
char* addOne(char*, int);
char* mystrrev(char*);
int main()
{
    int T;
    cin>>T;
    while ( T-- ) {
        doPalindrome();
    }
    return 0;
}

void doPalindrome() {
    char* p;

    p = (char*) calloc(10000001,  sizeof(char));
    cin>>p;
    if(isPalindrome(p)) {
        p = addOne(p, strlen(p) - 1);
    }
    int len = strlen(p);
    for(int i=0; i< (len / 2); i++) {
        if (p[len-1-i] != p [i]) {
            while (p [len -1 -i] != p[i]) {
                p = addOne(p, len -1 -i);
            }
        }
    }
    cout<<p<<endl;
    free(p);

}

bool isPalindrome(char* p)
{
    char* r = strdup(p);
    mystrrev(r);
    if( strcmp(p, r) == 0) {
            free(r);
        return true;
    }
    free(r);
    return false;

}

char* addOne(char *c, int index) {

    c[index] = c[index] + 1;
    bool prepend = false;
    while (c[index] > '9' && index >=0 )
    {
        c[index] = '0';
        index = index - 1;
        if (index == -1) {prepend = true; break;}
        c[index] = c[index] + 1;
    }
    if (prepend) {
        char* one;
        char* temp;
        one = (char*) malloc(sizeof(2));
        one[0] = '1';
        one[1] = '\0';
        temp = strcat(one, c);
        free(c);
        c = temp;
    }

    return c;
}

char *mystrrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
