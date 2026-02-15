#include<iostream>
#include<string> 

using namespace std ;

class Solution {
    public:
        string addBinary(string a, string b) {
            /*
                Try for the optimal solution rather than going for 
                the brute -> best -> optimal 
                Reverse the string 
            */
            reverse(a.begin() , a.end() ) ;
            reverse(b.begin() , b.end() ) ;
            int n = a.size() ; 
            int m = b.size() ; 
            int carry = 0 ; 
            int l = min( n , m ) ; 
            string res = "" ; 
            for( int i = 0 ; i < l ; i++ ){
                int sum = 0 ; 
                if( a[i] == '1' && b[i] == '1' ){
                    sum = 2 ; 
                }else if( a[i] == '0' && b[i] == '0' ){
                    sum = 0 ; 
                }else{
                    sum = 1 ; 
                }
                sum += carry ; 
                if( sum == 3 ){
                    res += '1' ; 
                    carry = 1 ; 
                }else if( sum == 2 ){
                    res += '0' ; 
                    carry = 1 ; 
                }else if( sum == 1 ){
                    carry = 0 ; 
                    res += '1' ;
                }else{
                    carry = 0 ; 
                    res += '0' ; 
                }
            }
            int i ; 
            i = l ; 
            while( l < n && i < n ){
                int sum = 0 ; 
                if( a[i] == '1' ){
                    sum = 1 ; 
                }
                sum += carry ; 
                if( sum == 2 ){
                    res += '0' ; 
                    carry = 1 ; 
                }else if( sum == 1){
                    res += '1' ; 
                    carry = 0 ; 
                }else{
                    carry = 0 ; 
                    res += '0' ; 
                }
                i++ ; 
            }
            cout << res << "\n" ;
            i = l ; 
            while( l < m && i < m ){
                int sum = 0 ; 
                if( b[i] == '1' ){
                    sum = 1 ; 
                }
                sum += carry ; 
                if( sum == 2 ){
                    res += '0' ; 
                    carry = 1 ; 
                }else if( sum == 1){
                    res += '1' ; 
                    carry = 0 ; 
                }else{
                    carry = 0 ; 
                    res += '0' ; 
                }
                i++ ; 
            }
            cout << res << "\n" ;
            if( carry == 1 ){
                res += '1' ;
            }
            cout << res << "\n" ;
            reverse(res.begin() , res.end()) ; 
            return res ; 
        }
    };