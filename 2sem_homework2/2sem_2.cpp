#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BankCell {
private:
    bool isOpen;
public:
    BankCell() {
        isOpen = false;
    }
    void open() {
        isOpen = true;
        std::cout << "Bank cell is open" << std::endl;
    }
    void close() {
        isOpen = false;
        std::cout << "Bank cell is closed" << std::endl;
    }
    bool isCellOpen() const {
        return isOpen;
    }
};

class Human {
private:
    std::string name;
public:
    Human(std::string nm) {
        name = nm;
    }
    std::string getName() const {
        return name;
    }
};

class BankCellOwner {
private:
    std::shared_ptr<BankCell> cell;
    std::vector<std::shared_ptr<Human>> owners;
public:
    BankCellOwner() {
        cell = std::make_shared<BankCell>();
    }
    void addOwner(std::shared_ptr<Human> owner) {
        if (cell->isCellOpen()) {
            std::cout << owner->getName() << " is the new owner of the bank cell" << std::endl;
            owners.push_back(owner);
        }
        else {
            std::cout << "Can\'t add owner. Bank cell is closed" << std::endl;
        }
    }
    void removeOwner(std::shared_ptr<Human> owner) {
        if (cell->isCellOpen()) {
            auto it = std::find(owners.begin(), owners.end(), owner);
            if (it != owners.end()) {
                std::cout << owner->getName() << " is removed from the bank cell owners" << std::endl;
                owners.erase(it);
            }
            else {
                std::cout << owner->getName() << " is not an owner of the bank cell" << std::endl;
            }
        }
        else {
            std::cout << "Can\'t remove owner. Bank cell is closed" << std::endl;
        }
    }
    void openCell() {
        cell->open();
    }
    void closeCell() {
        cell->close();
    }
};

int main() {
    std::shared_ptr<BankCellOwner> bco = std::make_shared<BankCellOwner>();
    std::shared_ptr<Human> h1 = std::make_shared<Human>("John");
    std::shared_ptr<Human> h2 = std::make_shared<Human>("Kate");
    std::shared_ptr<Human> h3 = std::make_shared<Human>("Alex");

    bco->openCell();
    bco->addOwner(h1);
    bco->addOwner(h2);
    bco->addOwner(h3);

    bco->closeCell();
    bco->addOwner(h2);

    bco->openCell();
    bco->removeOwner(h1);

    bco->removeOwner(h1);

    return 0;
}
