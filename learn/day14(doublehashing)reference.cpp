#include <iostream>

// Class for Double Hashing Hash Table (to avoid clustering)
class DoubleHashTable {
private:
    int table[11]; // Fixed-size array, use prime size for better probing
    int PRIME = 7; // Prime < size for hash2

public:
    DoubleHashTable() {
        for (int i = 0; i < 11; ++i) {
            table[i] = -1;
        }
    }

    int hash1(int value) {
        return value % 11;
    }

    int hash2(int value) {
        return PRIME - (value % PRIME);
    }

    bool insert(int value) {
        int index = hash1(value);
        if (table[index] == -1) {
            table[index] = value;
            return true;
        }
        for (int j = 1; j <= 11; ++j) {
            int newIndex = (index + j * hash2(value)) % 11;
            if (table[newIndex] == -1) {
                table[newIndex] = value;
                return true;
            }
        }
        return false;
    }

    void printTable() const {
        for (int i = 0; i < 11; ++i) {
            if (i > 0) std::cout << " ";
            std::cout << table[i];
        }
        std::cout << std::endl;
    }
};

int main() {
    DoubleHashTable hashTable;
    
    // === FILL TABLE COMPLETELY (11 values, unique hash1 positions 0-10) ===
    hashTable.insert(11); // hash1=0 → slot 0
    hashTable.insert(1);  // hash1=1 → slot 1
    hashTable.insert(2);  // hash1=2 → slot 2
    hashTable.insert(3);  // hash1=3 → slot 3
    hashTable.insert(4);  // hash1=4 → slot 4
    hashTable.insert(5);  // hash1=5 → slot 5
    hashTable.insert(6);  // hash1=6 → slot 6
    hashTable.insert(7);  // hash1=7 → slot 7
    hashTable.insert(8);  // hash1=8 → slot 8
    hashTable.insert(9);  // hash1=9 → slot 9
    hashTable.insert(10); // hash1=10→ slot 10
    
    std::cout << "Full table: ";
    hashTable.printTable(); // 11 1 2 3 4 5 6 7 8 9 10
    
    // === VALUE COLLIDING ~5+ TIMES: 22 ===
    // hash1(22) = 22%11 = 0 (COLLIDES with 11)
    // hash2(22) = 7 - (22%7=1) = 6
    // Probe sequence (ALL COLLIDE until table loops):
    // j=0: index=0 (occupied)
    // j=1: (0+1*6)%11=6 (occupied by 6)
    // j=2: (0+2*6)%11=1 (occupied by 1)  ← 2 collisions so far
    // j=3: (0+3*6)%11=7 (occupied by 7)
    // j=4: (0+4*6)%11=2 (occupied by 2)  ← 4 collisions
    // j=5: (0+5*6)%11=8 (occupied by 8)  ← **5 COLLISIONS**
    // j=6: (0+6*6)%11=4 (occupied by 4)
    // ... continues cycling all 11 slots → INSERT FAILS (table full)
    std::cout << "\nInsert 22 (collides 5+ times): ";
    if (!hashTable.insert(22)) {
        std::cout << "FAILED (table full after 5+ collisions!)" << std::endl;
    }
    
    // Table unchanged: still full
    std::cout << "Table after failed insert: ";
    hashTable.printTable();

    return 0;
}