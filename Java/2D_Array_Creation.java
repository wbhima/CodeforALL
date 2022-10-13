import java.util.Scanner;

public class ArrayCreation2D {
    public ArrayCreation2D() {
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of rows and columns: ");
        int nr = sc.nextInt();
        int nc = sc.nextInt();
        int[][] b = new int[nr][nc];

        int i;
        int j;
        for(i = 0; i < nr; ++i) {
            for(j = 0; j < nc; ++j) {
                b[i][j] = sc.nextInt();
            }
        }

        System.out.println("The elements are");

        for(i = 0; i < nr; ++i) {
            for(j = 0; j < nc; ++j) {
                System.out.println(b[i][j]);
            }
        }

    }
}
