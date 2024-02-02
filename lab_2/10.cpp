#include "bytes.h"

int main() {
    Bytes byte(0x1F);
    byte.ShowHex();
    std::cout << std::endl;
    byte.ShowBin();
    std::cout << std::endl;
    byte.ShowDec();
    std::cout << std::endl;
    byte.ShowChar();
    std::cout << std::endl;

    byte.ShowHexPos(0);
    std::cout << std::endl;
    byte.ShowBinPos(2);
    std::cout << std::endl;

    byte.EditHex(1, 8);
    byte.ShowHex(); 
    std::cout << std::endl;

    return 0;
}
