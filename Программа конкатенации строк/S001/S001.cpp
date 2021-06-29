#include <iostream>

int main()   //Программа конкатенации строк

{
    std::cout << "Vedite 2 stroki\n";
    char masif[514];
    char str[256]; 
    char str2[256]; 
    char f[] = "%s";
    
    __asm
    {

        lea esi, str
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi

        lea esi, str2
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi

        lea esi, [str]
        lea edi, [masif]
        b1:
        lodsb
            stosb
            cmp al, 0
            jnz b1

            lea esi, [str2]
            dec edi

            b2 :
        lodsb
            stosb
            cmp al, 0
            jnz b2

    }
    std::cout << masif;
}
