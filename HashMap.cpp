#include <iostream>

struct node {
    std::string name;
    node* next = nullptr;
};

int gethash(std::string name) {
    int hashsum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hashsum += abs(int(name[i]));
    }
    return hashsum % 10;
}

void push(node* index, std::string tempname) {
    int id = gethash(tempname);
    if (index[id].next == nullptr) {
        node* newnode = new node;
        newnode->name = tempname;
        index[id].next = newnode;
    }
    else {
        node* temp = &index[id];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        node* newnode = new node;
        newnode->name = tempname;
        temp->next = newnode;
    }
}

void print(node* index) {
    for (int i = 0; i < 10; i++) {
        std::cout << "[" << i << "]";
        node* temp = &index[i];
        while (temp->next != nullptr) {
            std::cout << " -> " << temp->next->name ;
            temp = temp->next;
        }
        std::cout << "\n";
    }
}

bool find(node* index, std::string tempname) {
    int id = gethash(tempname);
    node* temp = &index[id];
    while (temp->next != nullptr) {
        int i;
        for (i = 0; tempname[i] == temp->next->name[i]; i++) {
            if (tempname[i] == '\0' && temp->next->name[i] != '\0') {
                continue;
            }
            if (temp->next->name[i] == '\0' && tempname[i] != '\0') {
                continue;
            }
            if (tempname[i] == '\0' && temp->next->name[i] == '\0') {
                return true;
            }
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    node* index = new node[10];
    int count;
    std::string tempname;
    std::cout << "quantity of names to add:";
    std::cin >> count;
    std::cout << "\n";
    for (int i = 0; i < count; i++) {
        std::cout << "add name:";
        std::cin >> tempname;
        push(index, tempname);
    }
    std::cout << "\n\n";
    print(index);
    std::cout << "\n\n";
    bool findname;
    while (true) {
        std::cout << "name to find:";
        std::cin >> tempname;
        findname = find(index, tempname);
        if (findname) {
            std::cout << "finded";
        }
        else {
            std::cout << "not finded";
        }
        std::cout << "\n\n\'e\' for exit, or other letter for check another name:";
        std::cin >> tempname;
        if (tempname[0] == 'e'){
            break;
        }
    }
    return 0;
}