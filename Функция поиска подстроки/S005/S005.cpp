#include <iostream>

int main()// Функция поиска подстроки
{
    char str[256];
    char findSTR[256];
  
    char f[] = "%s";
    char fd[] = "%d";

    std::cout << "String:";
    char poiskSTR[256] = "Poisk string:";

    __asm
    {
        lea ebx, str

        push ebx

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea edx, poiskSTR

        push edx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea edx, findSTR

        push edx

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, str
        lea edx, findSTR
        dec ebx
        dec edx
        lea ecx, fd
        mov ecx, -1
        push ecx

        FindStr :
        inc ebx
            inc ecx
            mov al, [ebx]
            cmp al, 0
            jz RepeatComp
            jmp Continue
            RepeatComp :
        inc edx
            mov ah, [edx]
            cmp ah, 0
            jz end
            add esp, 4
            mov eax, -1
            push eax
            jmp end
            Continue :
        inc edx
            mov ah, [edx]
            cmp ah, 0
            jz end
            cmp al, ah
            jz CompareResult
            lea edx, findSTR
            dec edx
            add esp, 4
            mov eax, -1
            push eax
            jmp FindStr
            CompareResult :
        pop eax
            cmp eax, -1
            jg Next
            push ecx
            jmp FindStr
            Next :
        push eax
            jmp FindStr

            end :
        lea ebx, fd
            push ebx
            call printf
            add esp, 8
    }
}

