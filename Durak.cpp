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
    int y = (int)c;
    y++;
    int choise = askint();
    system("CLS");
    setprint(&set[choise-1], 1, false);
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

int askint(){
    int intanswer = -1;
    do {
        printf("Enter number: ");
        intanswer = (int)getchar();
        intanswer -= 48;
    } while (intanswer < 1 || intanswer > 6);
    return intanswer;
}

bool askyn() {
    char charanswerb = 'x';
    do {
        printf("Enter y or n: ");
        charanswerb = getchar();
    } while (charanswerb != 'y' && charanswerb != 'Y' && charanswerb != 'n' && charanswerb != 'N');
    if (charanswerb == 'y' || charanswerb == 'Y') {
        return true;
    }
    else {
        return false;
    }
}
