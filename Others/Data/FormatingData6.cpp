#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>

// the starting index of print table
#define start 5

using namespace std;

// Enumerated return values
enum return_value {success, fileOpenFailed, badCommandLine, badLineOfFile};

// Declarations
void readFileToTable(vector < vector <string> > &table, char *fileName); // store whole file to vector
void storeEachRow(string line, vector <string> &rowElement); // store a line to vector
void displyTable(const vector < vector <string> > &table); // display the table we read in


// Entrance
int main(int argc, char * argv[])
{
    // table stores every rowElement
    vector < vector <string> > table;
    // The program will disply the file which reads into memory, not sorted
    readFileToTable(table, argv[1]);
    displyTable(table);
    return success;
}


void readFileToTable(vector < vector <string> > &table, char *fileName) {
    // Try to read file, if faild display a message
    ifstream ifs(fileName);
    if(ifs.is_open()) {
        string line;
        // rowElement stores data read from file
        vector <string> rowElement;
        while(ifs.good()) {
            rowElement.clear();
            getline(ifs,line);
            // After get each line, do the file tab parsing and store it to the vector
            storeEachRow(line,rowElement);
            table.push_back(rowElement);
        }
    }
}


void storeEachRow(string line, vector <string> &rowElement) {
    // divide the string into tokens and push them into rowElement
    string tempS;
    stringstream ss(line);
    float tempI;
    while (ss >> tempS) {
        stringstream iss(tempS);
        if (iss >> tempI) {
            stringstream tempss;
            if (tempI >= 1000 and tempI < 1000000) {
                float i = tempI / 1000.0;
                char str[20];
                sprintf(str, "%4.1f", i);
                strcat(str,"K");
                tempss << str;
            } else if (tempI >= 1000000) {
                float i = tempI / 1000000;
                char str[20];
                sprintf(str, "%4.1f", i);
                strcat(str,"M");
                tempss << str;
            } else {
                tempss << tempI;
            }
            rowElement.push_back(tempss.str());
        }
    }
}

void displyTable(const vector < vector <string> > &table) {
    for (size_t i = 0; i < table.size(); i += 2) {
        for (size_t j = start; j < table[i].size(); j++) {
            cout << table[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << endl;
    for (size_t i = 1; i < table.size(); i += 2) {
        for (size_t j = start; j < table[i].size(); j++) {
            cout << table[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << endl;
}

