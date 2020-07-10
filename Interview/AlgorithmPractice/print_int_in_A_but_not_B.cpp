#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    Solution(){};
    void printAnotB(vector<int>& A, vector<int>& B){
        
        int lenA = A.size();
        int lenB = B.size();
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> ret;
        int j = 0;
        for(int i = 0; i < lenA; i++){
            while(A[i] > B[j]){
                j++;
            }
            if(A[i] < B[j]){
                ret.push_back(A[i]);
            }
        }

        for(int& i: ret){
            cout << "ret: " << i << ", ";
        }
        cout << endl;
    }

    //without sort
    void printAnotB(vector<int>& A, vector<int>& B){
        
        int lenA = A.size();
        int lenB = B.size();
        
        set<int> cacheB;
        for(int& i:B){
            cacheB.insert(i);
        }

        for(int i = 0; i < lenA; i++){
            if(!cacheB.count(A[i])){
                cout << "ret: " << A[i] << ", ";
            }
        }
    }

};

int main(){

    Solution* sol = new Solution;
    vector<int> A = { 5, 888, 4, 99, 0, 1, 66, 87, 34, 55};
    vector<int> B = { 7, 1, 87, 3, 4, 0};
    sol->printAnotB( A, B);

    return 0;
}