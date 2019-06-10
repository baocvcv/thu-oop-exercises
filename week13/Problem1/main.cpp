#include "Customer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <time.h>

using namespace std;

string read_file(string filename);

int main(){
    const int N_pattern = 10;
    const int N_source = 3;

    string path = "input/";
    string pattern_files[N_pattern] = {
        "pattern1.txt", "pattern2.txt", "pattern3.txt", "pattern4.txt", "pattern5.txt", "pattern6.txt", "pattern7.txt", "pattern8.txt", "pattern9.txt", "pattern10.txt"
    };
    string source_files[N_source] = {
        "source1.txt","source2.txt","source3.txt"
    };

    Customer customer;

    // test first strategy
    customer.SetStrategy(0);
    cout << "Running the Karp-Rabin algorithm\n";
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N_source; i++){
        cout << "Examining source " << i + 1 << endl;
        string source = read_file(path+source_files[i]);
        for (int j = 0; j < N_pattern; j++){
            cout << "  Checking pattern " << j + 1 << endl;
            string pattern = read_file(path+pattern_files[j]);
            customer.run(pattern, source);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    double t0 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    t0 *= 1e-9; // transform to seconds

    // test first strategy
    customer.SetStrategy(1);
    cout << "Running the KMP algorithm\n";
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N_source; i++){
        cout << "Examining source " << i + 1 << endl;
        string source = read_file(path+source_files[i]);
        for (int j = 0; j < N_pattern; j++){
            cout << "  Checking pattern " << j + 1 << endl;
            string pattern = read_file(path+pattern_files[j]);
            customer.run(pattern, source);
        }
    }
    end = chrono::high_resolution_clock::now();
    double t1 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    t1 *= 1e-9; // transform to seconds

    cout << "Karp-Rabin used a total of " << t0 << " seconds.\n";
    cout << "KMP used a total of " << t1 << " seconds.\n";

    return 0;
}

string read_file(string filename){
    ifstream infile(filename);
    string res;

    if(!infile.is_open()){
        cout << "Error reading file " << filename << endl;
        return res;
    }
    while(!infile.eof()){
        string s;
        getline(infile, s);
        res = res + s;
    }
    infile.close();
    return res;
}