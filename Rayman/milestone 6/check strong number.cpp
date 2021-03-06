/*
 *Strong number is a special number whose sum of factorial of digits is equal to the original number.
 *For example: 145 is strong number. Since, 1! + 4! + 5! = 145
 */
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
  long long int num=0, n, i, ld, factorial=1, sum=0;
    cout<<"enter a number to check strong number : "<<endl;
    cin>> num;
    n=num;
    while (n>0)
    {
        ld=n%10;
        if(ld!=0)
       {
           factorial=1;
           for(i=1; i<=ld; i++)
           {
               factorial*=i;
           }
       }
       else
       {
           ld=1;
       }
        sum+=factorial;
        n=n/10;
    }
    if(sum==num)
    cout<<"--> "<<sum<<" is a strong number."<<endl;
    else
    cout<<"--> "<<num<<" is not a strong number."<<endl;
    return 0;
}
