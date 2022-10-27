#include <iostream>
 
int main()
{
    long long int n;
    std::cin>>n;
    long long int sum = 0;
    long long int result = 0;
    for(long int i =1; i<=n; i++)
    {
        long long int a;
        std::cin>>a;
        sum += a*i;
        result += sum;
    }
    std::cout<<result<<std::endl;
}
