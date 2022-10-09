#include <bits/stdc++.h>

using namespace std;

// Fills array S[] with span values    
void calculateSpan(int price[], int n, int S[])
{
        // Span value of first day is always 1    
        S[0] = 1;
        // Calculate span value of remaining days     
        // by linearly checking previous days    
        for (int i = 1; i < n; i++)
        {
                S[i] = 1; // Initialize span value     
                // Traverse left while the next element     
                // on left is smaller than price[i]    
                for (int j = i - 1;
                        (j >= 0) &&
                        (price[i] >= price[j]); j--)
                        S[i]++;
        }
}
// A utility function to print elements of array    
void printArray(int arr[], int n) 
{
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
}
// Driver code    
int main() 
{
        int size_arr = 0;
        cout << "Enter the size of the span array::\n";
        cin >> size_arr;
        int price[size_arr]; //= new int[size_arr];//{ 10, 4, 5, 90, 120, 80 };    
        int n = size_arr; //sizeof(price) / sizeof(price[0]);    
        int S[n];
        int data;
        int count = 0;
        char ch;
        // Do-while loop  
        // Do part for performing actions  
        do
        // Menu is displayed  
        // Users enter 'y' to continue 'n' if  
        // entered by user , the program terminates  
        {
                // Menu  
                // Display messages  
                cout << "Please Choose one of the Operations listed below::\n";
                cout << "1. To Insert a new span value to the array.\n";
                cout << "2. To Calculate span value entered in array.\n";
                cout << "3. To Display the Calculated span values.\n";
                cout << "\n";
                int choice;
                scanf("%d", & choice);
                // Switch case  
                switch (choice)
                {
                        // Case 1  
                case 1:
                        cout << "Enter the span value that you want to add to array :\n";
                        cin >> data;
                        price[count++] = data;
                        // Display message  
                        cout << "Data Added Successfully.\n";
                        // Break statement to terminate a case  
                        break;
                        // Case 2  
                case 2:
                        // Display message  
                        calculateSpan(price, n, S);
                        cout << "Span Values Calculated Successfully.";
                        // Break statement to terminate a case  
                        break;
                        // Case 3  
                case 3:
                        // Display message  
                        cout << "New calculated Span values:\n";
                        printArray(S, n);
                        // Break statement to terminate a case  
                        break;
                default:
                        // Print statement  
                        cout << "Please enter a valid option from the menu to proceed further.\n \n";
                        // Break statement  
                        break;
                }
                cout << "\nType [N or n] to terminate the program.\nType [Y or y] to continue the program.\n";
                cin >> ch;
        } while (!(ch == 'N' || ch == 'n'));
        return 0;
}
