#include<iostream>
using namespace std;
#define m 11

class Hashing {
private:
    int table[m];
    int count;      

public:
   
    Hashing() {
        count = 0;
        for (int i = 0; i < m; i++) {
            table[i] = -1;
        }
    }

    int hash(int value) {
        return value % m;
    }

    bool LinearProbing(int value) {
        if (count == m) {
            cout << "Table full, cannot insert " << value << endl;
            return false;   
        }
        int index = hash(value);

    
        if (table[index] == -1) {
            table[index] = value;
            count++;
            return true;
        }
        for (int k = 1; k < m; k++){  
            int newIndex = (index + k) % m;
            if (table[newIndex] == -1) {
                table[newIndex] = value;
                count++;
                return true;
            }
        }
    return false;
    }
    
    int LinearSearching(int value) {
        int startIdx = hash(value);
        
        if (table[startIdx] == value) {
            return startIdx;
        }
        if (table[startIdx] == -1) {
            return -1;
        }
        
        for (int j = 1; j < m; j++) {  
            int idx = (startIdx + j) % m;   
            if (table[idx] == value) {
                return idx;
            }
            if (table[idx] == -1) {
                return -1;
            }
        }
        return -1;
    }

    bool QuadraticProbing(int value) {
        if (count == m) {
            cout << "Table full, cannot insert " << value << endl;
            return false; 
        }
        int index = hash(value);
        if (table[index] == -1) {
            table[index] = value;
            count++;
            return true;
        }
        for (int k = 1; k < m; k++) {  
            int newIndex = (index + k*k) % m;
            if (table[newIndex] == -1) {
                table[newIndex] = value;
                count++;
                return true;
            }
        }
        return false;
    }

    int QuadraticSearching(int value) {
        int startIdx = hash(value);
     
        if (table[startIdx] == value) {
            return startIdx;
        }
        if (table[startIdx] == -1) {
            return -1;
        }
    
        for (int j = 1; j < m; j++) {  
            int idex = (startIdx + j*j) % m;  
            if (table[idex] == value) {
                return idex;
            }
            if (table[idex] == -1) {
                return -1;
            }
        }
        return -1;
    }

    bool DoubleHashing(int value) {
        if (count == m) {
            cout << "Table full, cannot insert " << value << endl;
            return false;   
        }
        int index = hash(value);
        int hash2 = 7 - (value % 7);

        if (table[index] == -1) {
            table[index] = value;
            count++;
            return true;
        }
        for (int k = 1; k < m; k++) {  
            int newIndex = (index + k * hash2) % m;
            if (table[newIndex] == -1) {
                table[newIndex] = value;
                count++;
                return true;
            }
        }
        return false;
    }
    //  Searching for double Hash
    int DoubleSearching(int value) {
        int prime = 7;
        int startIndex = hash(value);
        int hash2 = prime - (value % prime);

        if (table[startIndex] == value) {
            return startIndex;
        }
  
        if (table[startIndex] == -1) {
            return -1;
        }
     
        for (int j = 1; j < m; j++) {  
            int index = (startIndex + j * hash2) % m;
            if (table[index] == value) {
                return index;
            }
            if (table[index] == -1) {
                return -1;
            }
        }
        return -1;  
    }

    
    void printTable() const {
        for (int i = 0; i < m; ++i) {
            if (i > 0) cout << " ";
            cout << table[i];
        }
        cout << endl;
    }
};

int main() {
   Hashing h;
   h.LinearProbing(10);
    h.LinearProbing(4);
    h.LinearProbing(7);
    h.LinearProbing(15);
    h.LinearProbing(21);
    h.LinearProbing(9);
    h.LinearProbing(1);
    h.LinearProbing(34);
    h.LinearProbing(18);
    h.LinearProbing(28);
    h.LinearProbing(12);
    h.LinearProbing(5);

    int Linearfound=h.LinearSearching(9);
    if(Linearfound!=-1){
        cout<<"Value found at index: "<<Linearfound<<endl;
    }else{
        cout<<"Value not found"<<endl;
    }
    int Quadraticfound=h.QuadraticSearching(18);
    if(Quadraticfound!=-1){
        cout<<"Value found at index: "<<Quadraticfound<<endl;
    }else{
        cout<<"Value not found"<<endl;
    }
    int Doublefound=h.DoubleSearching(5);
    if(Doublefound!=-1){
        cout<<"Value found at index: "<<Doublefound<<endl;
    }else{
        cout<<"Value not found"<<endl;
    }
    h.printTable();

    return 0;
}
```
// Final Output 

Table full, cannot insert 5
Value found at index: 9
Value found at index: 8
Value not found(for 5)
21 1 34 12 4 15 28 7 18 9 10
```