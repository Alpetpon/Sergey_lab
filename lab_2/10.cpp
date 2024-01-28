#include <iostream>

// Класс Bin
class Bin {
public:
    unsigned char m_bin0 : 1;
    unsigned char m_bin1 : 1;
    unsigned char m_bin2 : 1;
    unsigned char m_bin3 : 1;
    unsigned char m_bin4 : 1;
    unsigned char m_bin5 : 1;
    unsigned char m_bin6 : 1;
    unsigned char m_bin7 : 1;

    void Show() {
        std::cout << static_cast<int>(m_bin7) << m_bin6 << m_bin5 << m_bin4 << " "
                  << m_bin3 << m_bin2 << m_bin1 << m_bin0 << "b";
    }

    void ShowPos(int pos) {
        if (pos >= 0 && pos <= 7) {
            std::cout << static_cast<int>((m_bin7 >> pos) & 1);
        } else {
            std::cout << "Invalid position";
        }
    }

    void Edit(int pos, int val) {
        if (pos >= 0 && pos <= 7 && (val == 0 || val == 1)) {
            if (val == 1) {
                m_bin7 |= (1 << pos);
            } else {
                m_bin7 &= ~(1 << pos);
            }
        } else {
            std::cout << "Invalid position or value";
        }
    }

    friend union Bytes;
};

// Класс Oct
class Oct {
public:
    unsigned char m_oct0 : 3;
    unsigned char m_oct1 : 3;
    unsigned char m_oct2 : 2;

    void Show() {
        std::cout << static_cast<int>(m_oct2) << m_oct1 << m_oct0 << "o";
    }

    void ShowPos(int pos) {
        if (pos >= 0 && pos <= 5) {
            int shift = 3 * (1 - pos % 2);
            std::cout << static_cast<int>((m_oct2 >> shift) & 7);
        } else {
            std::cout << "Invalid position";
        }
    }

    void Edit(int pos, int val) {
        if (pos >= 0 && pos <= 5 && val >= 0 && val <= 7) {
            int shift = 3 * (1 - pos % 2);
            m_oct2 &= ~(7 << shift);
            m_oct2 |= (val << shift);
        } else {
            std::cout << "Invalid position or value";
        }
    }

    friend union Bytes;
};

// Класс Hex
class Hex {
public:
    unsigned char m_hex0 : 4;
    unsigned char m_hex1 : 4;

    void Show() {
        std::cout << std::hex << static_cast<int>(m_hex1) << m_hex0 << "h" << std::dec;
    }

    void ShowPos(int pos) {
        if (pos >= 0 && pos <= 3) {
            int shift = 4 * (1 - pos % 2);
            std::cout << std::hex << static_cast<int>((m_hex1 >> shift) & 0xF) << std::dec;
        } else {
            std::cout << "Invalid position";
        }
    }

    void Edit(int pos, int val) {
        if (pos >= 0 && pos <= 3 && val >= 0 && val <= 15) {
            int shift = 4 * (1 - pos % 2);
            m_hex1 &= ~(0xF << shift);
            m_hex1 |= (val << shift);
        } else {
            std::cout << "Invalid position or value";
        }
    }

    friend union Bytes;
};

// Объединение Bytes
union Bytes {
public:
    Bin m_bin;
    Oct m_oct;
    Hex m_hex;
    unsigned char m_dec;

    Bytes(unsigned char byte) : m_dec(byte) {}

    void ShowBin() { m_bin.Show(); }

    void ShowOct() { m_oct.Show(); }

    void ShowHex() { m_hex.Show(); }

    void ShowDec() { std::cout << static_cast<int>(m_dec) << "d"; }

    void ShowChar() {
        if (m_dec >= 32 && m_dec <= 126) {
            std::cout << static_cast<char>(m_dec);
        } else {
            std::cout << "Not printable";
        }
    }

    void ShowBinPos(int pos) { m_bin.ShowPos(pos); }

    void ShowOctPos(int pos) { m_oct.ShowPos(pos); }

    void ShowHexPos(int pos) { m_hex.ShowPos(pos); }

    void EditBin(int pos, int val) { m_bin.Edit(pos, val); }

    void EditOct(int pos, int val) { m_oct.Edit(pos, val); }

    void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
};

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
