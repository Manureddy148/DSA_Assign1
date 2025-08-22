#include <iostream>

#include <iostream> 
#include <vector>   
#include <algorithm> 


void insertOperation(std::vector<int>& arr, int& n, int si);
void deleteOperation(std::vector<int>& arr, int& n);
void displayArray(const std::vector<int>& arr, int n);
void searchArray(const std::vector<int>& arr, int n);
void sortArray(std::vector<int>& arr, int n);
void mergeOperation(std::vector<int>& arr, int& n, int& si);

int main() {
    int n = 0; 
    int si;   

    std::cout << "Enter the maximum size of array: "; 
    std::cin >> si;


    std::vector<int> arr;
    arr.reserve(si);

    int choice;

    do {
        std::cout << "\n--- Array Operations Menu ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Display\n";
        std::cout << "4. Merge\n";
        std::cout << "5. Search\n";
        std::cout << "6. Sort\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                insertOperation(arr, n, si);
                break;
            case 2:
                deleteOperation(arr, n);
                break;
            case 3:
                displayArray(arr, n);
                break;
            case 4:
                mergeOperation(arr, n, si);
                break;
            case 5:
                searchArray(arr, n);
                break;
            case 6:
                sortArray(arr, n);
                break;
            case 7:
                std::cout << "Exiting program.\n";
                break; 
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7); 

    return 0;
}



void insertOperation(std::vector<int>& arr, int& n, int si) {
    int ele, ichoice, pos;\
    std::cout << "\n--- Insert Operation ---\n";
    std::cout << "1. Insert at Beginning\n";
    std::cout << "2. Insert at End\n";
    std::cout << "3. Insert at Given Position\n";
    std::cout << "4. Back to Main Menu\n";

    do {
        std::cout << "Current number of elements: " << n << "\n";
        std::cout << "Enter your choice: ";
        if (n >= si) {
            std::cout << "Array is full. Cannot insert more elements.\n";
            return; 
        }


        std::cin >> ichoice;

        switch (ichoice) {
            case 1: // Insert at beginning
                std::cout << "Enter the element to insert: ";
                std::cin >> ele;
           
                for (int i = n; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = ele;
                n++;
                std::cout << ele << " inserted at the beginning.\n";
                break;

            case 2: // Insert at end
                std::cout << "Enter the element to insert: ";
                std::cin >> ele;
                arr[n] = ele;
                n++;
                std::cout << ele << " inserted at the end.\n";
                break;

            case 3: // Insert at given position
                std::cout << "Enter the position (0 to " << n << "): ";
                std::cin >> pos;
                if (pos < 0 || pos > n) { 
                    std::cout << "Invalid position.\n";
                    break;
                }
                std::cout << "Enter the element to insert: ";
                std::cin >> ele;
              
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = ele;
                n++;
                std::cout << ele << " inserted at position " << pos << ".\n";
                break;

            case 4: 
                std::cout << "Returning to main menu.\n";
                break; 

            default:
                std::cout << "Invalid choice for insert operation. Please try again.\n";
                break;
        }
        std::cout << "\n"; 
    } while (ichoice != 4);
}

void deleteOperation(std::vector<int>& arr, int& n) {
    int dchoice, dpos;
    std::cout << "\n--- Delete Operation ---\n";
    std::cout << "1. Delete from Beginning\n";
    std::cout << "2. Delete from End\n";
    std::cout << "3. Delete at Given Position\n";
    std::cout << "4. Back to Main Menu\n";
    do {

        if (n == 0) {
            std::cout << "Array is empty. Cannot delete elements.\n";
            return; 
        }
        std::cout << "Current number of elements: " << n << "\n";


        std::cout << "Enter your choice: ";
        std::cin >> dchoice;

        switch (dchoice) {
            case 1: // Delete from beginning
                std::cout << "Deleting from beginning...\n";
                for (int i = 0; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                std::cout << "Element deleted from the beginning.\n";
                break;

            case 2: // Delete from end
                std::cout << "Deleting from ending...\n";
                n--; 
                std::cout << "Element deleted from the end.\n";
                break;

            case 3: // Delete at given position
                std::cout << "Enter the position to delete (0 to " << n - 1 << "): ";
                std::cin >> dpos;
                if (dpos < 0 || dpos >= n) {
                    std::cout << "Invalid position.\n";
                    break;
                }
                std::cout << "Deleting element at position " << dpos << "...\n";
                for (int i = dpos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                std::cout << "Element deleted from position " << dpos << ".\n";
                break;

            case 4: // Back to Main Menu
                std::cout << "Returning to main menu.\n";
                break; 

            default:
                std::cout << "Invalid choice for delete operation. Please try again.\n";
                break;
        }
        std::cout << "\n"; 
    } while (dchoice != 4); 
}

void displayArray(const std::vector<int>& arr, int n) {
    std::cout << "--- Displaying Array Elements ---\n";
    if (n == 0) {
        std::cout << "Array is empty.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void searchArray(const std::vector<int>& arr, int n) {
    std::cout << "--- Search Operation ---\n";
    if (n == 0) {
        std::cout << "Array is empty. Nothing to search.\n";
        return;
    }
    int ele;
    std::cout << "Enter the element to search: ";
    std::cin >> ele;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            std::cout << "Element " << ele << " found at index " << i << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Element " << ele << " not found in the array.\n";
    }
}
void mergeOperation(std::vector<int>& arr, int& n, int& si) {
    std::cout << "--- Merge Operation ---\n";
    int msize;
    std::cout << "Enter the size of the new array to merge: ";
    std::cin >> msize;
    if (msize <= 0) {
        std::cout << "Invalid size.\n";
        return;
    }
    std::vector<int> marr(msize);
    std::cout << "Enter " << msize << " elements for the new array:\n";
    for (int i = 0; i < msize; ++i) {
        std::cin >> marr[i];
    }

    if (n + msize > si) {
        si = n + msize;
        arr.reserve(si);
    }

    for (int i = 0; i < msize; ++i) {
        if (n < arr.size()) {
            arr[n] = marr[i];
        } else {
            arr.push_back(marr[i]);
        }
        n++;
    }
    std::cout << "Arrays merged successfully. New size: " << n << "\n";
}

void sortArray(std::vector<int>& arr, int n) {
    std::cout << "--- Sort Operation (Bubble Sort) ---\n";
    if (n <= 1) { 
        std::cout << "Array has 0 or 1 element. Already sorted.\n";
        displayArray(arr, n); 
        return;
    }

    std::cout << "Array elements before sorting:\n";
    displayArray(arr, n);


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    std::cout << "Array elements after sorting:\n";
    displayArray(arr, n);
}