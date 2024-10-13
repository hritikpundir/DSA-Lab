// #include<iostream>
// using namespace std;
// void alldivisors(int num){
//     for(int i=1;i<=num;i++){
//         if(num%i == 0){
//             cout<<i<<" ";
//         }
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter the num: ";
//     cin>>n;
//     alldivisors(n);
//     return 0;
// }

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=i; j++){
                if(i%j == 0){
                    sum = sum + j;
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends