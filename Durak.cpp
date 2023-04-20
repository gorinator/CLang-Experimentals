#include <stdio.h>
#include <iostream>
#include <string.h>

struct card {
    int mast;
    int value;
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


void cardprint(card somecard);

int main() {
    card c6{chervi,6};
    cardprint(c6);
    return 0;
}

void cardprint(card somecard) {
     printf("/////\n");
     printf("/ %c /\n", (char)somecard.mast);
     if (somecard.value > 9) {
         printf("/ %i/\n", somecard.value);
     }
     else {
         printf("/ %i /\n", somecard.value);
     }
     printf("/ %c /\n", (char)somecard.mast);
     printf("/////\n");
}