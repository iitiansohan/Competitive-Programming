#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to process a type and return its canonical form
string process_type(const string& type, map<string, string>& type_definitions, int& deref_count) {
    int pointer_count = 0;
    string base = "";
    
    // Count pointers (*) and dereferences (&)
    for (char c : type) {
        if (c == '*') {
            pointer_count++;
        } else if (c == '&') {
            if (pointer_count > 0) pointer_count--; // Dereference a pointer
            else deref_count++; // Dereference that needs to be processed later
        } else {
            base += c;
        }
    }
    
    // Resolve the base type using typedefs
    while (type_definitions.count(base)) {
        string resolved = type_definitions[base];
        base = "";
        for (char c : resolved) {
            if (c == '*') pointer_count++;
            else if (c == '&') {
                if (pointer_count > 0) pointer_count--;
                else return "errtype";
            } else {
                base += c;
            }
        }
    }

    // If the base is void, check the validity of the dereferencing
    if (base == "void") {
        if (deref_count > pointer_count) return "errtype";
        pointer_count -= deref_count;
    }

    string result = "void";
    while (pointer_count--) result += '*'; // Add the necessary number of pointers
    return result;
}

int32_t main() 
{
    ios::sync_with_stdio(false); // Fast input/output
    cin.tie(nullptr); // Fast input/output

    int n;
    cin >> n;
    cin.ignore(); // To clear the newline after reading `n`
    
    map<string, string> type_definitions;
    type_definitions["void"] = "void";
    type_definitions["errtype"] = "errtype";
    
    for (int i = 0; i < n; ++i) {
        string operation;
        getline(cin, operation);
        
        if (operation.substr(0, 7) == "typedef") {
            // Parse typedef operation: "typedef A B"
            int space_pos = operation.find(' ', 8);  // Find the space after the type A
            string A = operation.substr(8, space_pos - 8);  // Extract type A
            string B = operation.substr(space_pos + 1);  // Extract type B
            
            int deref_count = 0;
            string resolved_A = process_type(A, type_definitions, deref_count);
            type_definitions[B] = resolved_A;  // Store the new type definition
            
        } else if (operation.substr(0, 6) == "typeof") {
            // Parse typeof operation: "typeof A"
            string A = operation.substr(7);  // Extract the type after "typeof"
            
            int deref_count = 0;
            string result = process_type(A, type_definitions, deref_count);
            
            if (deref_count > 0 || result == "errtype") {
                cout << "errtype\n";
            } else {
                cout << result << endl;
            }
        }
    }

    return 0;
}
