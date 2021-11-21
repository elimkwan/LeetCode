// You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        /*
        Dynamic Programing Approach:
        Can only reach stair n from stair n-1 or stair n-2
        Hence, the number of ways to get to stair n equals to the number of ways to get to stair n-1 plus the number of ways to get to stair n-2
        */
        
        if (n <= 2) return n;
        
        vector<int> ways(n);
        ways[0] = 1; // Step 1
        ways[1] = 2; // Step 2
        
        for (int i=2; i<n; i++){
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n-1];
    }

};


// Naive Combinatoric
// Let k be the number of (steps in two) we choose to make
// And (n-2k) be the number of (steps in one) we made
// Total number of steps made = n-k
// Choose k from total number of steps made => C(n-k, k)

// If n=4 or n=5, the maximum value of k is 2;
// Ans=No. of ways to climb the stairs when k=0 +  when k=1 + when k=2

// General Form: Sum_{k=0}^{k=floor(n/2)} C(n-k, k)
//
//     int climbStairs(int n) {
//         int sum = 0;
//         for(int k=0; k<=floor(n/2); k++){
//             sum += combinations(n-k, k);
//         }
//         return sum;
//     }
    
//     int combinations(int n, int r){
//         return (n-r)/factorial(r);
//     }
    
//     int factorial(int n){
//         return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
//     }