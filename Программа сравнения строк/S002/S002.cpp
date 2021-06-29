#include <iostream>

int main() //Программа, которая сравнивает две строки. Cравнивнение двух строк с учётом регистра, печатает: 0 –если строки эквивалентны, 1 – если s1<s2, -1 — если s1>s2.
{
    char str[256];
    char str2[256];

    char pervyy[] = "Vvedite 1 stroky\n";
    char vtoryy[] = "Vvedite 2 stroky\n";
    char f[] = "%s";

    char menihe[] = "1\n";
    char bolhe[] = "-1\n";
    char equalent[] = "0\n";

    _asm {
        lea ebx, pervyy
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8

        lea ebx, str
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8

        lea ebx, vtoryy
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8

        lea ebx, str2
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8

        lea ebx, str
        dec ebx
        lea ecx, str2
        dec ecx

        b1 :
        inc ebx
            inc ecx
            mov al, [ebx]
            mov dl, [ecx]

            cmp al, 0
            je b2 // Обнаружение конца первой строки

            cmp dl, 0
            je f3 
            cmp al, dl
            je b1 

            jb f4 
            jmp f3 

            b2 :
        cmp dl, 0
            je f5 
            jmp f4

            // Вывод, когда первая строка меньше чем вторая строка
            f3 :  
        lea ebx, menihe
            push ebx
            lea ecx, f
            push ecx
            call printf
            add esp, 8
            jmp end

            // Вывод, когда первая строка больше чем вторая строка
            f4 : 
        lea ebx, bolhe
            push ebx
            lea ecx, f
            push ecx
            call printf
            add esp, 8
            jmp end

            // Вывод, когда две строки равны
            f5 : 
        lea ebx, equalent
            push ebx
            lea ecx, f
            push ecx
            call printf
            add esp, 8

            end:
    }
}
