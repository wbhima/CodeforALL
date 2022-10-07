int romanToInt(string s) {
        
          unordered_map<char, int> Rom_Int = { { 'I' , 1 }, // We simply store all the symbol and value as key value pair using an unordered map 
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = Rom_Int[s.back()];  // We store last character of string and store mapped int value in sum
   for (int i = s.length() - 2; i >= 0; --i) //loop from second last element to start of string
   {  
       if (Rom_Int[s[i]] < Rom_Int[s[i + 1]]) //we subtract from sum if next value from back is lesser
       {
           sum -= Rom_Int[s[i]];
       }
       else  //we add to sum if next value from back is greater or equal
       {
           sum += Rom_Int[s[i]];
       }
       
       // if s="IV" then first 'V' is encountered so sum=5; then next character i.e 'I' is less so we subtract its value from sum ie sum = 5-1 = 4
       // if s="VI" then first 'I' is encountered so sum=1; then next character i.e 'V' is greater so we add its value to sum ie sum = 1+5 = 6 , same way we add for same values
   }
   
   return sum; //We finally return sum
    }
