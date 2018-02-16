#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory() : INVENTORY_CAPACITY(6) {
	invCapacity = INVENTORY_CAPACITY;
	inventory[INVENTORY_CAPACITY];
	Initialize(inventory, INVENTORY_CAPACITY);
}

Inventory::~Inventory() {
	
}

// initializes a container
void Inventory::Initialize(const string* container[], int capacity) {
	// set all elements to null
	for (int i = 0; i < capacity; ++i) {
		container[i] = NULL;
	}
}

// tests filled status of a comtainer
bool Inventory::isFull(const string* const container[], int capacity) {
	bool full = true;
	int i = 0;

	while (full && i < capacity) {
		//if theres at least on empty slot...
		if (container[i] == NULL) {
			// then the container isnt full
			full = false;
		}
		++i;
	}
	return full;
}

// tests if an item is in a container
bool Inventory::Contains(const string* const pItem, const string* container[], int capacity) {
	bool has = false;
	int i = 0;

	while (!has && i < capacity) {
		if (container[i] == pItem) {
			has = true;
		}
		++i;
	}
	return has;
}

//tests empty status of a container
bool Inventory::isEmpty(const string* const container[], int capacity) {
	bool empty = true;
	int i = 0;

	while (empty && i < capacity) {
		// if a slot isnt empty
		if (container[i] != NULL) {
			// then the container isnt empty
			empty = false;
		}
		++i;
	}
	return empty;
}

// displays the items in a container
void Inventory::Display(const string* const container[], int capacity) {
	//if container is empty display message saying so and return
	if (isEmpty(container, capacity)) {
		cout << "<Empty>" << endl;
		return;
	}
	// otherwise send all strings pointed to by elements of container to cout
	for (int i = 0; i < capacity; ++i) {
		if (container[i] != NULL) {
			cout << *(container[i]) << endl;
		}
	}
}

// adds an item to a container
void Inventory::Add(const string* const pItem, const string* container[], int capacity) {
	if (pItem == NULL) {
		return;
	}

	if (Contains(pItem, container, capacity)) {
		cout << "Item already present. cant add.";
		cout << endl;
		return;
	}

	if (isFull(container, capacity)) {
		cout << "Container full. Cant add." << endl;
		return;
	}

	// find first null pointer in container point it to string pItem points to
	bool found = false;
	int i = 0;

	while (!found && i < capacity) {
		if (container[i] == NULL) {
			container[i] = pItem;

			found = true;
		}
		++i;
	}
}

// removes an item from a container
void Inventory::Remove(const string* const pItem, const string* container[], int capacity) {
	if (pItem == NULL) {
		return;
	}

	// set element that is equal to pItem to NULL
	bool found = false;
	int i = 0;

	while (!found && i < capacity) {
		if (container[i] == pItem) {
			container[i] == NULL;

			found = true;
		}
		++i;
	}

	//if item wasnt found, say so
	if (!found) {
		cout << "Item not found. Cant remove." << endl;
	}
}

// gets the inventories capacity
int Inventory::getCapacity() {
	return invCapacity;
}

const string* Inventory::getInventory() {
	return inventory[getCapacity()];
}