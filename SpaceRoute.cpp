#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;



public:
    template <typename T>
    SpaceRoute(); // Constructor
    SpaceRoute();
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data);
    void addWaypointAtEnd(T& data);
    void addWaypointAtIndex(int index, T& data);
    void removeWaypointAtBeginning();
    void removeWaypointAtEnd();
    void removeWaypointAtIndex(int index);
    void traverseForward();
    void traverseBackward();
    Node<T>* getWaypoint(int index);
    void setWaypoint(int index, T& data);
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

template <typename T>
SpaceRoute<T>::SpaceRoute() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
SpaceRoute<T>::~SpaceRoute() {
    while (head != nullptr) {
        Node<T>* current = head;
        head = head->next;
        delete current;
    }
    tail = nullptr;
}

template<typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T &data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        // if list is empty
        head = newNode;
        tail = newNode;
    } else {
        //if list is not empty
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtEnd(T &data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        // if list is empty
        head = newNode;
        tail = newNode;
    } else {
        // if list is not empty
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T &data) {
    if (index == 0) {
        // checks if index is at zero, if so, uses previously defined method and ends
        addWaypointAtBeginning(data);
        return;
    }

}


