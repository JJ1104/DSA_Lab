#include <stdio.h>

void cpystring(char str[],char cpystr[], int index){
    cpystr[index] = str[index];

    if (str[index] == '\0') 
        return;
    cpystring(str, cpystr, index + 1);

}


int main(){
    char str[20],cpystr[20];
    printf("Enter the string: ");
    gets(str);
    cpystring(str,cpystr,0);
    printf("Copied String is : %s ", cpystr);
    return 0;
}