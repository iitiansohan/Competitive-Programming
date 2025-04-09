#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Define a maximum size for the matrix
const int MAX_SIZE = 1000; // Adjust as needed

// Function to generate a random sparse matrix
void generateSparseMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int q = n * n;
    int p = q / 20;
    
    // Initialize matrix with zeros
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }
    // Generate p random positions and fill with random values between 1 and 9
    for (int i = 0; i < p; ++i) {
        int index = rand() % q;
        matrix[index/n][index % n] = rand() % 9 + 1;
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout <<"\n";
    }
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to represent a matrix in sparse format and print it
void printSparse(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        bool hasNonZero = false;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                if (!hasNonZero) {
                    cout << "Row " << i << ": ";
                    hasNonZero = true;
                }
                cout << "(Col " << j << ": " << matrix[i][j] << ") ";
            }
        }
        if (hasNonZero) {
            cout <<"\n";
        }
    }
}

// Function to add two sparse matrices
void addSparse(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;
    int A[MAX_SIZE][MAX_SIZE]{};
    int B[MAX_SIZE][MAX_SIZE]{};
    int C[MAX_SIZE][MAX_SIZE]{};
    
    // Generate sparse matrices A and B
    generateSparseMatrix(A, n);
    generateSparseMatrix(B, n);

    cout << "Matrix A:" <<"\n";
    printMatrix(A, n);
    cout << "\n";
    
    cout << "Matrix B:" <<"\n";
    printMatrix(B, n);
    cout << "\n";

    // Sum matrices in normal representation
    clock_t start_time = clock();
    addMatrices(A, B, C, n);
    clock_t end_time = clock();
    double normal_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    cout << "Matrix C=(A + B):" << "\n";
    printMatrix(C, n);
    cout << "\n";

    // Print sparse representation of A and B
    cout << "Sparse representation of Matrix A:" << "\n";
    printSparse(A, n);
    cout << "\n";
    
    cout << "Sparse representation of Matrix B:" << "\n";
    printSparse(B, n);
    cout << "\n";

    // Sum matrices in sparse representation
    start_time = clock();
    addSparse(A, B, C, n);
    end_time = clock();
    double sparse_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sparse representation of Matrix C (A + B):" << "\n";
    printSparse(C, n);
    cout << std::endl;
    
    // Compare time taken
    cout << "Time taken for normal 2D matrix addition: " << normal_time << " seconds" << "\n";
    cout << "Time taken for sparse matrix addition: " << sparse_time << " seconds" << "\n";
    
    return 0;
}
