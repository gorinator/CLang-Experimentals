#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

struct card {
    int mast;
    int value;
    bool kozyr;
};

enum masti {  // ♥ - 3, ♦ - 4, ♣ - 5, ♠ - 6
    chervi = 3,
    bubi = 4,
    kresti = 5,
    piki = 6
};

enum karty {  // V - 11, D - 12, K - 13, T - 14
    valet = 11,
    dama = 12,
    karol = 13,
    tuz = 14
};

void setprint(card* set, int n, bool numeration);
bool askyn();
int askint();


int main() {
    card set[6];
    set[0] = { chervi,6 };
    set[1] = { bubi, valet};
    set[2] = { piki,10 };
    set[3] = { kresti,tuz };
    set[4] = { chervi,8 };
    set[5] = { bubi,dama };
    setprint(&set[0], 6, true);
    bool c = askyn();
    int choise = askint();
    system("CLS");
    setprint(&set[choise-1], 1, false);
    std::cout << choise;
    return 0;
}

void setprint(card* set, int n, bool numeration) {
     for (int i = 0; i < n; i++) {
         printf("/////\t");
     }
     printf("\n");
     for (int i = 0; i < n; i++) {
         printf("/ %c /\t", (char)set[i].mast);
     }
     printf("\n");
     for (int i = 0; i < n; i++) {
         switch (set[i].value) {
         case 10:
             printf("/ %i/\t", set[i].value);
             break;
         case 11:
             printf("/ %c /\t", 'V');
             break;
         case 12:
             printf("/ %c /\t", 'D');
             break;
         case 13:
             printf("/ %c /\t", 'K');
             break;
         case 14:
             printf("/ %c /\t", 'T');
             break;
         default:
             printf("/ %i /\t", set[i].value);
             break;
         }
     }
     printf("\n");
     for (int i = 0; i < n; i++) {
         printf("/ %c /\t", (char)set[i].mast);
     }
     printf("\n");
     for (int i = 0; i < n; i++) {
         printf("/////\t");
     }
     printf("\n");
     if (numeration) {
         for (int i = 0; i < n; i++) {
             printf("  %i  \t", i + 1);
         }
     }
     printf("\n\n");
}

int askint(){ // тут не доделал косяк с числами более 3 и 4 знаков
    int intanswer = -1;
    do {
        printf("Enter number: ");
        char intin[20];
        std::cin >> intin;
        intanswer = 0;
        int n = strlen(intin);
        int countx = 1;
        if (n > 1) {
            for (int k = 1; k < n; k++) {
                countx *= 10;
            }
        }
        if (countx > 1) {
            for (int x = countx, i = 0; i < n; i++, x /= 10) {
                if (intin[i] == '0' || intin[i] == '1' || intin[i] == '2' || intin[i] == '3' || intin[i] == '4' || intin[i] == '5' || intin[i] == '6' || intin[i] == '7' || intin[i] == '8' || intin[i] == '9') {
                    int temp = (int)intin[i];
                    temp -= 48;
                    intanswer += temp * x;
                }
            }
        }
        if (n == 1) {
            for (int i = 0; i < n; i++) {
                if (intin[i] == '0' || intin[i] == '1' || intin[i] == '2' || intin[i] == '3' || intin[i] == '4' || intin[i] == '5' || intin[i] == '6' || intin[i] == '7' || intin[i] == '8' || intin[i] == '9') {
                    int temp = (int)intin[i];
                    temp -= 48;
                    intanswer += temp;
                }
            }
        }
    } while (intanswer < 1 || intanswer > 360000);
    return intanswer;
}

bool askyn() {
    char charanswerb = 'x';
    do {
        printf("Enter y or n: ");
        std::string in;
        std::cin >> in;
        charanswerb = in[0];
    } while (charanswerb != 'y' && charanswerb != 'Y' && charanswerb != 'n' && charanswerb != 'N');
    if (charanswerb == 'y' || charanswerb == 'Y') {
        return true;
    }
    else {
        return false;
    }
}
