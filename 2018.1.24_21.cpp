#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if ( pushV.empty() == true || popV.empty() == true ) return false ;
        vector<int> vec ;
        int j = 0 ;

        for ( int i = 0; i < pushV.size(); ++ i ) {
            vec.push_back( pushV[i] ) ;
            while ( j < popV.size() && popV[j] == vec.back() ) {
                vec.pop_back() ;
                ++ j ;
            }
        }

        return vec.empty() ;
    }
};
