#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            
            if (index < SIZE) {
                array[index] = *entry;
                index++;
            } else {
                if (!(entry->compare(&array[index - 1]))) {
                    cout << entry->name << "'s score is too low to be added!" << endl;
                    return;
                }
                array[index - 1] = *entry;
            }

            for (int i = index - 1; i > 0; i--) {
                if (array[i].compare(&array[i - 1])) {
                    Entry temp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = temp;
                } else {
                    break;
                }
            }
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};