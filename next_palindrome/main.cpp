#include <iostream>
#include <cstring>

using namespace std;
bool isPalindrome(char*);
void doPalindrome();
char* addOne(char*, int);
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
    char p[100];
    cin>>p;
    //isPalindrome(p);
    cout<<addOne(p, strlen(p) - 1);

}

bool isPalindrome(char* p)
{
    char* r = strrev(p);

}

char* addOne(char *c, int index) {

    c[index] += 1;
    bool prepend = false;
    while (c[index] > '9' && index >=0 )
    {
        c[index] = '0';
        index = index - 1;
        if (index == -1) {prepend = true; break;}
        c[index]++;
    }
    if (prepend) {
            char one[2] = "1";
        c = strcat(one, c);
    }

    return c;
}
