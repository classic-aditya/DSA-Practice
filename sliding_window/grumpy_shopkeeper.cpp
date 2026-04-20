// this is leetcode number - 1052 
#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION 
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // first we would take for sure number for customer that will be happy
        int custActual = 0;

        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 0)
                custActual += customers[i];
        }

        // Checking window wise
        int answer = 0;

        for (int x = 0; x <= (grumpy.size() - minutes); x++) {
            int custWin = custActual;

            for (int i = x; i < (x + minutes); i++) {
                if (grumpy[i] == 1)
                    custWin += customers[i];
            }

            answer = max(custWin, answer);
        }

        return answer;
    }
};

int main() {
    Solution obj;
    
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy    = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    cout << obj.maxSatisfied(customers, grumpy, minutes) << endl;

    return 0;
}