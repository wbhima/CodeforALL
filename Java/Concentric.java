/*
This program accepts a single integer number n as input.
The program then creates an mxm 2D array that counts outward from the center.
The center value is always 1. The array should be displayed on the console.

Example:

Input 

4

Output

4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/

import java.util.Scanner;

public class Concentric {
    public static void main(String[] args) throws Exception {
        Scanner mainInput = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int layers = mainInput.nextInt();
        int dimensions = (layers - 1) * 2 + 1;
        int midpoint = dimensions - layers;
        int[][] matrix = new int[dimensions][dimensions];
        
        for(int i = 0; i < layers; i++) {
            for(int j = 0; j < matrix.length; j++) {
                for(int k = 0; k < matrix[0].length; k++) {
                    if(j == midpoint - i) {
                        matrix[j][k] = i + 1;
                    } else if(j == midpoint + i) {
                        matrix[j][k] = i + 1;
                    } else if(k == midpoint - i && matrix[j][k] < i + 1) {
                        matrix[j][k] = i + 1;
                    } else if(k == midpoint + i && matrix[j][k] < i + 1) {
                        matrix[j][k] = i + 1;
                    }
                }
            }
        }
        
        //Printing the result!
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
        mainInput.close();
    }
}