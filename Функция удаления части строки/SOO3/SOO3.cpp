#include <iostream>

int main() //Функция удаления части строки
{   
    int StrIndex;
    int StrDlina;
    int StrKoll;

    char str[256];
    char s[256];

    char f[] = "%s";
    char fd[] = "%d";

    std::cout << "String:\n";
    char outStr1[256] = "Vvedite index nachala: ";
    char outStr2[256] = "Vvedite dliny dly ydalenaiy: ";

    __asm
    {
        lea esi, str

        push esi

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, outStr1

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, StrIndex

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ebx, outStr2

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, StrDlina

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ecx, fd
        mov ecx, -1
        dec esi

        push edx
        mov edx, StrIndex

        lea ebx, str
        push ebx
        dec ebx

        StrDlinagthStr :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz StrDlinagthStr
            push ecx

            StartDelete :
        cmp StrIndex, 0
            jge StrDlinagthDelete

            mov StrIndex, 0

            StrDlinagthDelete :
            cmp StrDlina, 0
            jl StrNoChange

            StrIndexBiggerStrDlinagth :
        cmp StrIndex, ecx
            jg StrNoChange

            add esp, 8
            mov StrKoll, ecx
            mov ecx, 0
            dec esi

            lea esi, [str]
            lea edi, [s]
            push edi

            mov edx, StrIndex

            cmp edx, 1
            jl AddStrDlinagth

            StartWrite :
        inc ecx
            lodsb
            stosb
            cmp ecx, edx
            jne StartWrite

            AddStrDlinagth :
        add edx, StrDlina
            mov eax, StrKoll
            cmp edx, eax
            jbe EndWrite
            mov edx, eax

            EndWrite :
        inc esi
            inc ecx
            cmp ecx, edx
            jne EndWrite

            ContinueEndWrite :
        lodsb
            stosb
            cmp al, 0
            jnz ContinueEndWrite

            jmp End



        StrNoChange:
        add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [str]
            lea edi, [s]
            push edi

            ContinueNoChange :
        lodsb
            stosb
            cmp al, 0
            jnz ContinueNoChange

            End :
        pop edi
            pop esi
    }
    std::cout << "Itogo: ";
    std::cout << s;
}

