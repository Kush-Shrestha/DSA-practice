#include <iostream>

// Class for Quadratic Hash Table using a simple fixed-size array
class QuadraticHashTable {
private:
    int table[10]; // Fixed-size array, hardcoded to 10

public:
    // Constructor to initialize the table
    QuadraticHashTable() {
        // Initialize all slots to -1 (empty)
        for (int i = 0; i < 10; ++i) {
            table[i] = -1;
        }
    }

    // Insert a single value using quadratic probing
    bool insert(int value) {
        // Compute initial hash (mod 10 since size is hardcoded)
        int hash = value % 10;

        // If slot is empty, insert directly
        if (table[hash] == -1) {
            table[hash] = value;
            return true;
        }

        // Quadratic probing: try (hash + j*j) % 10 for j = 1, 2, 3, ...
        for (int j = 1; j <= 10; ++j) {
            int newIndex = (hash + j * j) % 10;
            if (table[newIndex] == -1) {
                table[newIndex] = value;
                return true;
            }
        }

        // Could not insert (table is full or no free slot found)
        return false;
    }

    // Insert multiple values at once (like the original function)
    void insertAll(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
            insert(arr[i]);
        }
    }

    // Print the table as space-separated values
    void printTable() const {
        for (int i = 0; i < 10; ++i) {
            if (i > 0) std::cout << " ";
            std::cout << table[i];
        }
        std::cout << std::endl;
    }
};

// Driver code
int main() {
    QuadraticHashTable hashTable;

    // Note: Simulations assume starting from an empty table and sequential insertions.
    // All values hash to 0 (since value % 10 == 0 for all).
    // Quadratic probing covers only certain indices for hash=0: 0,1,4,9,6,5 (and repeats).
    // Thus, only 6 slots can be filled from this cluster; indices 2,3,7,8 remain unreachable and empty.
    // Insertion 1: 10
    // Hash = 10 % 10 = 0
    // Slot 0 empty -> Placed at index 0
    hashTable.insert(10);

    // Insertion 2: 20
    // Hash = 20 % 10 = 0 (collision at 0)
    // Probe j=1: (0 + 1*1) % 10 = 1 (empty) -> Placed at index 1
    hashTable.insert(20);

    // Insertion 3: 30
    // Hash = 30 % 10 = 0 (collision at 0)
    // Probe j=1: (0 + 1*1) % 10 = 1 (occupied)
    // Probe j=2: (0 + 2*2) % 10 = 4 (empty) -> Placed at index 4
    hashTable.insert(30);

    // Insertion 4: 40
    // Hash = 40 % 10 = 0 (collision at 0)
    // Probe j=1: 1 (occupied)
    // Probe j=2: 4 (occupied)
    // Probe j=3: (0 + 3*3) % 10 = 9 (empty) -> Placed at index 9
    hashTable.insert(40);

    // Insertion 5: 50
    // Hash = 50 % 10 = 0 (collision at 0)
    // Probe j=1: 1 (occupied)
    // Probe j=2: 4 (occupied)
    // Probe j=3: 9 (occupied)
    // Probe j=4: (0 + 4*4) % 10 = 16 % 10 = 6 (empty) -> Placed at index 6
    hashTable.insert(50);

    // Insertion 6: 60
    // Hash = 60 % 10 = 0 (collision at 0)
    // Probe j=1: 1 (occupied)
    // Probe j=2: 4 (occupied)
    // Probe j=3: 9 (occupied)
    // Probe j=4: 6 (occupied)
    // Probe j=5: (0 + 5*5) % 10 = 25 % 10 = 5 (empty) -> Placed at index 5
    hashTable.insert(60);

    // Insertion 7: 70
    // Hash = 70 % 10 = 0 (collision at 0)
    // Probe j=1: 1 (occupied)
    // Probe j=2: 4 (occupied)
    // Probe j=3: 9 (occupied)
    // Probe j=4: 6 (occupied)
    // Probe j=5: 5 (occupied)
    // Probe j=6: (0 + 6*6) % 10 = 36 % 10 = 6 (occupied)
    // Probe j=7: (0 + 7*7) % 10 = 49 % 10 = 9 (occupied)
    // Probe j=8: (0 + 8*8) % 10 = 64 % 10 = 4 (occupied)
    // Probe j=9: (0 + 9*9) % 10 = 81 % 10 = 1 (occupied)
    // Probe j=10: (0 + 10*10) % 10 = 100 % 10 = 0 (occupied)
    // No empty slot found in probe sequence -> Insertion fails (table not full, but cluster is)
    hashTable.insert(70);

    // Insertion 8: 80
    // Same as above: All probes in 0,1,4,9,6,5 are occupied -> Insertion fails
    hashTable.insert(80);

    // Insertion 9: 90
    // Same as above: All probes in 0,1,4,9,6,5 are occupied -> Insertion fails
    hashTable.insert(90);

    // Final table: Only first 6 inserted. Indices covered: 0,1,4,5,6,9 (the probe cluster for hash=0).
    // Indices not covered/reachable: 2,3,7,8 remain -1.
    // Output: 10 20 -1 -1 30 60 50 -1 -1 40
    hashTable.printTable();

    return 0;
}