#include <iostream>
#include <cmath>
#include <cstdlib> 
#include <iomanip>
 
using namespace std;
 
int main()
{
   int n, status = 1, num = 3, count, c;
   cout << "Enter the number of prime numbers to print\n";
   cin >> n;

   int nums[n];
   float storage[n];
 

   if ( n >= 1 )
   {
      cout << "First " << n <<" prime numbers are :-" << endl;
      cout << 2 << endl;
   }
 
   for ( count = 2 ; count <=n ;  )
   {
      for ( c = 2 ; c <= (int)sqrt(num) ; c++ )
      {
         if ( num%c == 0 ) 
         {
            status = 0;
            break;
         }
      }

      if ( status != 0 )
      {
         nums[count] = num;
         cout << num << endl;
         count++;
      }
      status = 1;
      num++;
   }   

   cout << "LOL" << endl;
   cout << endl;
   cout << endl;
   nums[0] = 2;

   for (int i = 2; i < count; i++)
   {
   	cout << nums[i] << endl;
   }

   double prod;
   double c1;
   double a;
   double b;
   double temp;

   //prod = 1/(1-(1/(2*2));
   prod = 1.333333333333333333333333333333;
   cout << "testprod " << prod << endl;

   storage[0] = 1.0;
   storage[1] = 1.0;


   for (int i = 2; i < count; i++)
   {
   	a = nums[i];
   	//cout << "A is: " << a << endl;
   	//cout << "A times A is " << (a*a) << endl;
   	b = (a*a);
   	//temp = (1 / (1 - 1/b));
   	c1 = (1 / b);
      temp = (1 / (1 - c1));
      storage[i] = temp;
   	//cout << c1 << endl;
   	prod = prod * temp;
   } 

   cout << endl;
   cout << endl;

   double newnum = 1.00;

   for (int i = 0; i < n; i++)
   {
       cout << nums[i] << "  " << storage[i] << endl;
      newnum = newnum * storage[i];
   }
   //cout << "lol" << endl;
float lol;
lol = prod;

   cout << "The calculation is: " << std::setprecision(50) << prod << endl;
cout << "float calculation is  " << std::setprecision(50) << lol << endl;

    cout << "The tested calculation is: " << std::setprecision(20) <<  newnum*1.3333333333333333333 << endl;
 
   return 0;
}
