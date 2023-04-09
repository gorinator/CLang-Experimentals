/******************************************************************
 *                                                                *
 *    Primitive string output in the middle of specified frame    *
 *                                                                *
 ******************************************************************/

#include <iostream>
#define tempArr 100  // maximum length of temp arrays

int main() {
    std::cout << "Enter your string:" << std::endl;
    char* sArr = new char[tempArr];
    std::cin.getline(sArr, tempArr);
    std::cout << "Enter frame symbol:" << std::endl; // only first symbol will be used
    char* smblArr = new char[tempArr];
    std::cin.getline(smblArr, tempArr);
    std::cout << "Enter frame lenth:" << std::endl;
    int flenth;
    std::cin >> flenth;
    flenth -= 1; // offset by - 1, as we work with array addresses, otherwise the string is 1 char longer
    std::cout << "Enter frame height:" << std::endl;
    int fheight;
    std::cin >> fheight;
    fheight -= 1; // offset by - 1, as we work with array addresses, otherwise the count of strings will be +1 
    std::cout << std::endl;
    int send = 0;
    for (int i = 0; i < tempArr; i++) {
        if ((*(sArr + i)) != 0) {
            send = i;
        }
        else {
            break;
        }
    }
    if ((send > (flenth - 2)) || (fheight < 2)) { // Checking for the capacity. Line cannot be longer than the length of frame - 2 characters for chars in edges, and frame cannot be lower than 3 lines
        std::cout << ">Incompatible sizes<" << std::endl;
    }
    else {
        int mheight = fheight / 2;
        int mlenth = (flenth - send) / 2;
        int lcount = 0;
        int hcount = 0;
        while (lcount <= flenth) {
            std::cout << smblArr[0];
            lcount++;
        }
        std::cout << std::endl;
        hcount++;
        lcount = 0;
        while (hcount < mheight) {
            for (lcount = 0; lcount <= flenth; lcount++) {
                if ((lcount == 0) || (lcount == flenth)) {
                    std::cout << smblArr[0];
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            hcount++;
            lcount = 0;
        }
        lcount = 0;
        if (hcount == mheight) {
            if (lcount == 0) {
                std::cout << smblArr[0];
                lcount++;
            }
            while ((lcount > 0) && (lcount < mlenth)) {
                std::cout << " ";
                lcount++;
            }
            std::cout << sArr;
            lcount = lcount + send + 1;
            while (lcount < flenth) {
                std::cout << " ";
                lcount++;
            }
            if (lcount == flenth) {
                std::cout << smblArr[0];
                lcount = 0;
                std::cout << std::endl;
            }
        }
        hcount++;
        while (hcount < fheight) {
            for (lcount = 0; lcount <= flenth; lcount++) {
                if ((lcount == 0) || (lcount == flenth)) {
                    std::cout << smblArr[0];
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            hcount++;
            lcount = 0;
        }
        lcount = 0;
        while (lcount <= flenth) {
            std::cout << smblArr[0];
            lcount++;
        }
        std::cout << std::endl;
    }
    delete[] sArr;
    delete[] smblArr;
    return 0;
}
