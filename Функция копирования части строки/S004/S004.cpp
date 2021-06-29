#include <iostream>
int main()// Функция копирования части строки
{
    int IndexCopy;
    int DlinaCopy;
    char String[] = " ";

    char f[] = "%s";
    char fd[] = "%d";
    char str[256];
    char s[256] = "\n";

    std::cout << "String:";
    char outStr1[256] = "Index to start cop: ";
    char outStr2[256] = "Dlina of the copy: ";

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

        lea ebx, IndexCopy

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

        lea ebx, DlinaCopy

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ecx, fd
        mov ecx, -1
        dec esi

        push edx
        mov edx, IndexCopy

        lea ecx, fd
        mov ecx, -1
        dec esi

        lea ebx, str
        push ebx
        dec ebx

        DlinaCopygthStr :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz DlinaCopygthStr
            push ecx

            StartCopy :
        cmp IndexCopy, 0
            jge DlinaCopygthCopy

            mov IndexCopy, 0

            DlinaCopygthCopy :
            cmp DlinaCopy, 0
            jl StrNoChange

            IndexCopyBiggerDlinaCopygth :
        cmp IndexCopy, ecx
            jg StrNoChange

            add edx, DlinaCopy

            CheckDlinaCopygthCopy :

        cmp edx, ecx
            jbe Later
            mov edx, ecx

            Later :
        add esp, 8
            mov ecx, -1
            dec esi

            lea esi, [str]
            lea edi, [s]
            push edi
            dec esi

            mov edx, IndexCopy

            Write :
        inc esi
            inc ecx
            cmp ecx, edx
            jne Write

            add edx, DlinaCopy

            ContinueWrite :
        inc ecx
            lodsb
            stosb
            cmp ecx, edx
            jne ContinueWrite

            jmp End

            StrNoChange :
        add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [String]
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

