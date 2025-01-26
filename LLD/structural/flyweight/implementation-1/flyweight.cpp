#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;

class Iletter {
public:
    virtual void display(int x, int y) = 0;
    virtual ~Iletter() {};
};

class DocumentCharacter : public Iletter {
    char letter;
    string fontType;
    int size;

public:
    DocumentCharacter(char letter, string fontType, int size) : letter(letter), fontType(fontType), size(size) {}

    void display(int x, int y) override {
        cout << "Letter '" << letter << "' at position (" << x << ", " << y << "), FontType: " << fontType << endl;
    }
};

class CharacterFactory {
    unordered_map<char, std::shared_ptr<Iletter>> charMap;

public:
    CharacterFactory() {
        cout << "Char factory instance initialized" << endl;
    }

    shared_ptr<Iletter> createChar(char charValue, string fontType, int size) {
        if (charMap.find(charValue) != charMap.end()) {
            return charMap[charValue];
        } else {
            shared_ptr<Iletter> docChar = make_shared<DocumentCharacter>(charValue, fontType, size);
            charMap[charValue] = docChar;
            return docChar;
        }
    }
};

int main() {
    CharacterFactory factory;
    auto docChar = factory.createChar('t', "arial", 4);
    

    docChar->display(1, 2);
    auto char2 = factory.createChar('t', "arial", 4);
    char2->display(2,4);

    return 0;
}
