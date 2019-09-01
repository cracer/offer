#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

//定制一个仿函数
 typedef map<string, int>::iterator CountIte;
 struct compare
 {
     bool operator()(CountIte lhs, CountIte rhs){
         return lhs->second > rhs->second;
     }
 };
 void get_topK_gramar(const vector<string>& v, int k)
 {
     //统计vector中各种相同key出现的次数
     map<string, int> countMap;
     for( int i =0; i< v.size( ); ++i)
     {
     //  map<string, int>::iterator it = countMap.find(v[ i]);
     //  if(it != countMap.end( ))//countmap中存在v[ i] 
     //      ++it->second;
     //  else
     //      countMap.insert( make_pair(v[i], 1);
         countMap[v[i]]++;
     }
 
     //定置仿函数,以每种编程语言出现次数进行排序
     //注意：不能用set来排序，因为它会去重，即其会将具有相同value值的某种语言过滤掉
     multiset<CountIte, compare> sortSet;
     CountIte cit = countMap.begin( );
     while( cit != countMap.end( ))
     {
         sortSet.insert(cit);
         ++cit;
     }
 
     multiset<CountIte, compare>::iterator it1 =  sortSet.begin( );
     for(; it1 != sortSet.end( ); ++it1)
     {
         if( k--)
             cout<<(*it1)->first<<":"<<(*it1)->second<<endl;
     }
 }
 int main( )
 {
     vector<string> v;
     v.push_back("python" );
     v.push_back("PHP" );
     v.push_back("PHP" );
     v.push_back("PHP" );
     v.push_back("PHP" );
     v.push_back("Java" );
     v.push_back("PHP" );
     v.push_back("C/C++" );
     v.push_back("C/C++" );
     v.push_back("python" );
     v.push_back("Java" );
     v.push_back("Java" );
     //统计语言次数,或者前K种语言
     get_topK_gramar(v, 3);
	 return 0;
 }