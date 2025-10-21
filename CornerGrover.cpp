#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// ------------------------------------------------------
// Class Declaration
// ------------------------------------------------------
class GroceryTracker {
private:
    map<string, int> itemFrequency; // Stores each item and its frequency
    string inputFileName;
    string backupFileName;

public:
    // Constructor
    GroceryTracker(string inputFile, string backupFile) {
        inputFileName = inputFile;
        backupFileName = backupFile;
    }

    // Reads data from input file and populates the map
    void LoadData() {
        ifstream inputFile(inputFileName);
        string item;

        if (!inputFile.is_open()) {
            cerr << "Error: Could not open input file: " << inputFileName << endl;
            return;
        }

        while (inputFile >> item) {
            itemFrequency[item]++;
        }
        inputFile.close();

        WriteBackupFile();
    }

    // Writes frequencies to backup file
    void WriteBackupFile() {
        ofstream outFile(backupFileName);
        if (!outFile.is_open()) {
            cerr << "Error: Could not create backup file." << endl;
            return;
        }

        for (auto const& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

    // Returns frequency of a single item
    int GetItemFrequency(string itemName) {
        if (itemFrequency.find(itemName) != itemFrequency.end()) {
            return itemFrequency[itemName];
        } else {
            return 0; // Item not found
        }
    }

    // Prints all items and their frequencies
    void PrintAllFrequencies() {
        cout << left << setw(15) << "Item" << "Frequency" << endl;
        cout << "-------------------------" << endl;
        for (auto const& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << pair.second << endl;
        }
    }

    // Prints histogram of frequencies
    void PrintHistogram() {
        cout << "\nItem Frequency Histogram:" << endl;
        cout << "--------------------------" << endl;
        for (auto const& pair : itemFrequency) {
            cout << setw(15) << left << pair.first;
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// ------------------------------------------------------
// Main Function
// ------------------------------------------------------
int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    tracker.LoadData();

    int choice = 0;
    string item;

    while (true) {
        cout << "\n======= Corner Grocer Menu =======" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\nEnter item name: ";
            cin >> item;
            cout << item << " appears " << tracker.GetItemFrequency(item) << " times." << endl;
            break;

        case 2:
            tracker.PrintAllFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
