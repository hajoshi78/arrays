/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on March 19, 2021, 11:00 AM
 */

#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

pair<int,int> getTwoSumIndexes(int arr[], int n, int sum){
    pair<int,int> result;
    map<int,int> complementsMap;
    result = make_pair(-1,-1);
    if(n>=2){
        for(int i=0;i<n;i++){
            int searchVal = sum - arr[i];
            map<int,int>::iterator index= complementsMap.find(searchVal);
            
            if(index== complementsMap.end()){
                complementsMap[arr[i]] = i;
            }
            else{
                result = make_pair(i, index->second);
                break;
            }
        }
    }
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={2,4,10,15,7,20};
    pair<int,int> twoSumIndex = getTwoSumIndexes(arr, 6,19);
    cout <<"Indexes : (" <<  twoSumIndex.first << ", " <<twoSumIndex.second <<")";
    return 0;
}

