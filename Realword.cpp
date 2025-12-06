#include <iostream>
using namespace std;

struct Customer {
    int id, arrivalTime, serviceTime, waitTime;
    Customer* next;
    Customer(int i, int a, int s) : id(i), arrivalTime(a), serviceTime(s), waitTime(0), next(nullptr) {}
};

struct Teller {
    int id, busyUntil, served;
    bool isBusy;
    Teller(int i) : id(i), busyUntil(0), served(0), isBusy(false) {}
};

class Queue {
    Customer *front, *rear;
    int size;
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    
    void enqueue(int id, int arrival, int service) {
        Customer* c = new Customer(id, arrival, service);
        if (!rear) front = rear = c;
        else { rear->next = c; rear = c; }
        size++;
    }
    
    Customer* dequeue() {
        if (!front) return nullptr;
        Customer* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        size--;
        return temp;
    }
    
    bool isEmpty() { return !front; }
    int getSize() { return size; }
    
    ~Queue() {
        while (!isEmpty()) delete dequeue();
    }
};

class BankSimulation {
    Queue queue;
    Teller** tellers;
    int numTellers, currentTime, totalCustomers, served, totalWait, maxWait, nextId;
    unsigned int seed;
    
    int random(int min, int max) {
        seed = (seed * 1103515245 + 12345) & 0x7fffffff;
        return min + (seed % (max - min + 1));
    }
    
public:
    BankSimulation(int n) : numTellers(n), currentTime(0), totalCustomers(0), 
                            served(0), totalWait(0), maxWait(0), nextId(1), seed(12345) {
        tellers = new Teller*[n];
        for (int i = 0; i < n; i++) tellers[i] = new Teller(i + 1);
    }
    
    void addCustomer(int time) {
        queue.enqueue(nextId++, time, random(5, 15));
        totalCustomers++;
    }
    
    void process(int time) {
        currentTime = time;
        for (int i = 0; i < numTellers; i++) {
            if (tellers[i]->isBusy && time >= tellers[i]->busyUntil)
                tellers[i]->isBusy = false;
            
            if (!tellers[i]->isBusy && !queue.isEmpty()) {
                Customer* c = queue.dequeue();
                c->waitTime = time - c->arrivalTime;
                tellers[i]->isBusy = true;
                tellers[i]->busyUntil = time + c->serviceTime;
                tellers[i]->served++;
                served++;
                totalWait += c->waitTime;
                if (c->waitTime > maxWait) maxWait = c->waitTime;
                cout << "T" << tellers[i]->id << " serving C" << c->id 
                     << " (wait: " << c->waitTime << "m)\n";
                delete c;
            }
        }
    }
    
    void showStatus() {
        cout << "\n[Time " << currentTime << "] Queue: " << queue.getSize() 
             << " | Served: " << served << "/" << totalCustomers << "\n";
    }
    
    void report() {
        cout << "\n=== REPORT ===\n";
        cout << "Customers: " << totalCustomers << " | Served: " << served << "\n";
        if (served > 0)
            cout << "Avg Wait: " << (double)totalWait/served << "m | Max: " << maxWait << "m\n";
        for (int i = 0; i < numTellers; i++)
            cout << "Teller " << tellers[i]->id << ": " << tellers[i]->served << " served\n";
    }
    
    ~BankSimulation() {
        for (int i = 0; i < numTellers; i++) delete tellers[i];
        delete[] tellers;
    }
};

int main() {
    BankSimulation bank(3);
    
    cout << "=== BANK QUEUE SIMULATION ===\n\n";
    
    // Time 0
    for (int i = 0; i < 5; i++) bank.addCustomer(0);
    bank.process(0);
    bank.showStatus();
    
    // Time 10
    for (int i = 0; i < 3; i++) bank.addCustomer(10);
    bank.process(10);
    bank.showStatus();
    
    // Time 20
    bank.addCustomer(20);
    bank.process(20);
    bank.showStatus();
    
    // Time 30
    bank.process(30);
    bank.showStatus();
    
    bank.report();
    
    return 0;
}