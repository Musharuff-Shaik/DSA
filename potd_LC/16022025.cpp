#include<iostream>
using namespace std ; 

class Solution {
    public:
        int reverseBits(int n) {
            // but its a lengthy process 
            string s = "" ; 
            while( n ){
                int bit = ( n % 2 ) ; 
                s += bit + '0' ; 
                n /= 2 ; 
            }
            int num = 0 ; 
            int size = s.size() ; 
            for( int i = size ; i < 32 ; i++ ){
                s += '0' ;
            }
            long long i = 1 ; 
            int j = 0 ; 
            for( int j = 31 ; j >=0 ; j-- ){
                int bit = 0 ; 
                if( ( s[j] == '1' ) ){
                    bit = 1 ;
                }
                num += ( i * bit ) ; 
                i *= 2 ; 
            }
            return num ; 
        }
    };