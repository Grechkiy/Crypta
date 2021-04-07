#include <iostream>
#include <cstring>
#include <map>

long nod(int a, int b) {///Алгоритм Евклида
    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}

int gcdex(int a, int b, int &x, int &y) {///Расширенный аалгоритм Евклида
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d1 = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d1;
}

void frequency(char *text) {///Функция частотного анализа
    int n = strlen(text);
    std::map<char, int> mp;
    std::map<char, int>::iterator it;
    for (int i = 0; i < n; ++i) {
        it = mp.find(text[i]);
        if (it == mp.end()) {
            mp.insert(std::pair<char, int>(text[i], 1));
        } else {
            it->second++;
        }
    }
    for(std::map<char, int>::iterator i = mp.begin(); i!=mp.end(); ++i){
        std::cout << "The symbol '" << i->first << "'" << " occurs " << i->second << " times. Frequency "
                  << (static_cast<float>(i->second)/strlen(text))*100 << "%" << std::endl;
    }
}


int main() {
    int check;
    char *copy = new char[500];
    std::cout << "Enter a text:";
    gets(copy);
    for (int i = 0; i < strlen(copy); ++i) {
        copy[i] = tolower(copy[i]);
    }
    std::cout << "Choose cipher:" << std::endl;///Выбор шифра
    std::cout << "1 - Chesar cipher, 2 - Afinne cipher, 3 - Afinne reccurent cipher" << std::endl;
    std::cin >> check;
    char *text = new char[strlen(copy)];
    strcpy(text, copy);
    delete[] copy;
    if (check == 1) {///Шифр Цезаря
        int k, k1;
        std::cout << "Enter the coefficient:" << std::endl;
        std::cout << "k=";
        std::cin >> k;
        if (k < 0) {
            k1 = k % 26 + 26;
        } else k1 = k;
        for (int i = 0; i < strlen(text); ++i) {                ///Преобразование текста
            if (text[i] >= 97 && text[i] <= 122) {
                text[i] = ((text[i] - 97 + k1) % 26) + 97;
            }
        }
        std::cout << "Encrypted text:" << std::endl;
        for (int i = 0; i < strlen(text); ++i) {///Вывод зашифрованного текста
            std::cout << text[i];
        }
        std::cout << std::endl << "Frequency analysis encypted text:" << std::endl;
        frequency(text);
        std::cout << std::endl;
        std::cout << "Decoded text:" << std::endl;
        for (int i = 0; i < strlen(text); ++i) {///Вывод расшифрованного текста
            if (text[i] <= 97 + k1 - 1 && text[i] >= 97) {
                text[i] = ((text[i] - 97 - k + 26) % 26) + 97;
            } else if (text[i] >= 97 + k1 && text[i] <= 122) {
                text[i] = ((text[i] - 97 - k) % 26) + 97;
            }
            std::cout << text[i];
        }
        std::cout << std::endl << "Frequency analysis original text:" << std::endl;
        frequency(text);

    } else if (check == 2) {///Афинное преобразование
        int a, b, x, y, b1;
        std::cout << std::endl << "Afinne cipher:" << std::endl;
        std::cout << "Alphabet power - 26" << std::endl;
        std::cout << "Enter the coefficients:" << std::endl;
        std::cout << "a=";
        std::cin >> a;
        while (1 != nod(a, 26)) {
            std::cout << "Enter the coefficients:" << std::endl;
            std::cout << "a=";
            std::cin >> a;
        }
        std::cout << "b=";
        std::cin >> b;
        if (b < 0) {
            b1 = b % 26 + 26;
        } else {
            b1 = b;
        }
        for (int i = 0; i < strlen(text); ++i) {
            if (text[i] >= 97 && text[i] <= 122) {
                text[i] = ((a * (text[i] - 97) + b1) % 26) + 97;
            }
        }
        std::cout << "Encrypted text:" << std::endl;
        for (int i = 0; i < strlen(text); ++i) {///Вывод зашифрованного текста
            std::cout << text[i];
        }
        std::cout << std::endl << "Frequency analysis encrypted text:" << std::endl;
        frequency(text);
        std::cout << std::endl;
        std::cout << "Decoded text:" << std::endl;
        gcdex(a, 26, x, y);
        if (x < 0) {
            x = x % 26 + 26;
        }
        for (int i = 0; i < strlen(text); ++i) {///Вывод расшифрованного текста
            if (text[i] <= 97 + b1 - 1 && text[i] >= 97) {
                text[i] = ((x * (text[i] - 97 - b1 + 26)) % 26) + 97;
            } else if (text[i] >= 97 + b1 && text[i] <= 122) {
                text[i] = ((x * (text[i] - 97 - b1)) % 26) + 97;
            }
            std::cout << text[i];
        }
        std::cout << std::endl << "Frequency analysis original text:" << std::endl;
        frequency(text);

    } else if (check == 3) {///Афинное рекуррентное преобразование
        int a1, a2, b1, b2, x, y;
        std::cout << std::endl << "Afinne reccurent cipher:" << std::endl;
        std::cout << "Alphabet power - 26" << std::endl;
        std::cout << "Enter the coefficients:" << std::endl;
        std::cout << "a1=";
        std::cin >> a1;
        while (1 != nod(a1, 26)) {
            std::cout << "Enter the coefficients:" << std::endl;
            std::cout << "a1=";
            std::cin >> a1;
        }
        std::cout << "a2=";
        std::cin >> a2;
        while (1 != nod(a2, 26)) {
            std::cout << "Enter the coefficients:" << std::endl;
            std::cout << "a1=";
            std::cin >> a2;
        }
        std::cout << "b1=";
        std::cin >> b1;
        std::cout << "b2=";
        std::cin >> b2;
        int n = strlen(text);
        int *a = new int[n];
        a[0] = a1;
        a[1] = a2;
        for (int i = 2; i < n; ++i) {
            a[i] = (a[i - 2] * a[i - 1]) % 26;
        }
        int *b = new int[n];;
        b[0] = b1;
        b[1] = b2;
        for (int i = 2; i < n; ++i) {
            b[i] = (b[i - 2] + b[i - 1]);
            if (b[i] < 0) {
                b[i] = b[i] % 26 + 26;
            } else
                b[i] = b[i] % 26;
        }
        std::cout << std::endl;
        for (int i = 0; i < n; ++i) {
            if (text[i] >= 97 && text[i] <= 122) {
                text[i] = (a[i] * (text[i] - 97) + b[i]) % 26 + 97;
            }
        }
        std::cout << "Encrypted text:" << std::endl;
        for (int i = 0; i < n; ++i) {///Вывод зашифрованного текста
            std::cout << text[i];
        }
        std::cout << std::endl << "Frequency analysis encrypted text:" << std::endl;
        frequency(text);
        std::cout << std::endl;
        std::cout << "Decoded text:" << std::endl;
        for (int i = 0; i < n; ++i) {///Вывод расшифрованного текста
            gcdex(a[i], 26, x, y);
            if (x < 0)
                x = x % 26 + 26;
            if (text[i] >= 97 && text[i] <= 97 + b[i] - 1) {
                text[i] = ((x * (text[i] - 97 - b[i] + 26)) % 26) + 97;
            } else if (text[i] >= 97 + b[i] && text[i] <= 122) {
                text[i] = ((x * (text[i] - 97 - b[i])) % 26) + 97;
            }
            std::cout << text[i];
        }
        std::cout << std::endl << "Frequency analysis original text:" << std::endl;
        frequency(text);
        delete[]a;
        delete[]b;
    }

    delete[]text;
    return 0;
}