#include <iostream>
using namespace std;

int main()
{
    int a[5][5], trans[5][5], r, c, i, j;

    cout << "Enter rows of matrix: ";
    cin >> r;
    cout << "Enter columns of matrix: ";
    cin >> c;

    cout<<"\nEnter Elements to Matrix Below :: \n";

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;++j)
        {
            cout<<"\nEnter a1["<<i<<"]["<<j<<"] Element :: ";
            cin>>a[i][j];
        }

    }
    // Displaying the matrix a[][]
    cout << "\n The Entered Matrix is :: \n" << endl;
    for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                cout<<"\t"<<a[i][j];
            }
            printf("\n\n");
        }

    // Finding transpose of matrix a[][] and storing it in array trans[][].
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            trans[j][i]=a[i][j];
        }

    // Displaying the transpose,i.e, Displaying array trans[][].
    cout << endl << "Transpose of Matrix :: " << endl;
    for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                cout<<"\t"<<trans[i][j];
            }
            printf("\n\n");
        }

    return 0;
}
