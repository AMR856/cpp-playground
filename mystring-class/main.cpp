#include "./mystring.h"

int main() {
    std::cout << "Creating MyString objects...\n";
    MyString s1{"Hello"};
    MyString s2{" World"};
    MyString s3;

    std::cout << "\nTesting display():\n";
    std::cout << "s1: "; s1.display();
    std::cout << "s2: "; s2.display();
    std::cout << "s3 (empty): "; s3.display();

    std::cout << "\nTesting + operator (concatenation):\n";
    MyString s4 = s1 + s2;
    std::cout << "s1 + s2 = "; s4.display();

    std::cout << "\nTesting += operator (append):\n";
    s1 += s2;
    std::cout << "s1 after s1 += s2: "; s1.display();

    std::cout << "\nTesting unary - operator (convert to lowercase or other logic):\n";
    MyString s5 = -s1;
    std::cout << "-s1 = "; s5.display();

    std::cout << "\nTesting ! operator (is empty?):\n";
    std::cout << "s3 is empty? " << (!s3 ? "Yes" : "No") << std::endl;
    std::cout << "s1 is empty? " << (!s1 ? "Yes" : "No") << std::endl;

    std::cout << "\nTesting * operator (repetition):\n";
    MyString s6 = s2 * 3;
    std::cout << "s2 * 3 = "; s6.display();

    std::cout << "\nTesting comparison operators:\n";
    std::cout << "s1 == s4? " << (s1 == s4 ? "Yes" : "No") << std::endl;
    std::cout << "s1 != s2? " << (s1 != s2 ? "Yes" : "No") << std::endl;
    std::cout << "s1 < s2? " << (s1 < s2 ? "Yes" : "No") << std::endl;
    std::cout << "s1 > s2? " << (s1 > s2 ? "Yes" : "No") << std::endl;
    std::cout << "s1 <= s4? " << (s1 <= s4 ? "Yes" : "No") << std::endl;
    std::cout << "s1 >= s4? " << (s1 >= s4 ? "Yes" : "No") << std::endl;

    std::cout << "\nTesting move assignment:\n";
    MyString s7;
    s7 = MyString("Temporary move");
    std::cout << "s7 after move = "; s7.display();

    std::cout << "\nTesting copy assignment:\n";
    MyString s8;
    s8 = s7;
    std::cout << "s8 after s8 = s7 = "; s8.display();

    std::cout << "\nTesting stream insertion (<<):\n";
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;

    std::cout << "\nTesting stream extraction (>>):\n";
    MyString user_input;
    std::cout << "Enter a word for user_input: ";
    std::cin >> user_input;
    std::cout << "You entered: " << user_input << std::endl;
    return 0;
}
