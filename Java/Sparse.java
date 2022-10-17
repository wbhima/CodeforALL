import java.util.*; 
  
class main { 
    static int checkSparse(int n) 
    { 
        if ((n & (n>>1)) >=1) 
            return 0; 
       
        return 1; 
    } 
      
    public static void main(String[] args) 
    { 
        System.out.println(checkSparse(72)) ; 
        System.out.println(checkSparse(12)) ; 
        System.out.println(checkSparse(2)) ; 
        System.out.println(checkSparse(3)) ; 
        } 
    }
