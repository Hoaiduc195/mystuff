#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>

class Node {
public:
    int value;
    Node** forward;
    Node(int level, int value) {
        this->value = value;
        forward = new Node*[level + 1];
        for (int i = 0; i <= level; ++i)
            forward[i] = nullptr;
    }
    ~Node() {
        delete[] forward;
    }
};

class SkipList {
    int MAX_LEVEL;
    float P;
    int level;
    Node* header;

public:
    SkipList(int maxLevel = 16, float p = 0.5) {
        MAX_LEVEL = maxLevel;
        P = p;
        level = 0;
        header = new Node(MAX_LEVEL, INT_MIN);
        std::srand(std::time(nullptr));  // Seed RNG
    }

    int randomLevel() {
        int lvl = 0;
        while ((float)std::rand() / RAND_MAX < P && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

    void insert(int value) {
        Node* current = header;
        Node* update[MAX_LEVEL + 1];
        std::fill(update, update + MAX_LEVEL + 1, nullptr);

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];
        if (!current || current->value != value) {
            int lvl = randomLevel();
            if (lvl > level) {
                for (int i = level + 1; i <= lvl; ++i)
                    update[i] = header;
                level = lvl;
            }

            Node* newNode = new Node(lvl, value);
            for (int i = 0; i <= lvl; ++i) {
                newNode->forward[i] = update[i]->forward[i];
                    update[i]->forward[i] = newNode;
            }
        }
    }

    bool search(int value) {
        Node* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->value < value)
                current = current->forward[i];
        }
        current = current->forward[0];
        return current && current->value == value;
    }

    void remove(int value) {
        Node* current = header;
        Node* update[MAX_LEVEL + 1];
        std::fill(update, update + MAX_LEVEL + 1, nullptr);

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];
        if (current && current->value == value) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current)
                    break;
                update[i]->forward[i] = current->forward[i];
            }
            delete current;
            while (level > 0 && header->forward[level] == nullptr)
                level--;
        }
    }

    void display() {
        std::cout << "Skip List:\n";
        for (int i = level; i >= 0; i--) {
            Node* node = header->forward[i];
            std::cout << "Level " << i << ": ";
            while (node != nullptr) {
                std::cout << node->value << " ";
                node = node->forward[i];
            }
            std::cout << "\n";
        }
    }

    ~SkipList() {
        Node* current = header;
        while (current) {
            Node* next = current->forward[0];
            delete current;
            current = next;
        }
    }
};
