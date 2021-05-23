/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 4, 2021, 8:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;


void swap(int& val1, int& val2){
    int temp;
    temp = val1;
    val1= val2;
    val2= temp;
    
}


int swapSortNoDupsOrMissingElemsArrayHasZero( int arr[], int n){
    int swapCount=0;
    int i=0;
    
    while(i<n){
        if(arr[i]!=arr[arr[i]]){
            swap(arr[i], arr[arr[i]]);
            swapCount++;
        }
        else{
            i++;
        }
    }
    return swapCount;
}


int swapSortNoDupsOrMissingElemsArrayStartsFromOne( int arr[], int n){
    int swapCount=0;
    int i=0;
    
    while(i<n){
        if(arr[i]!=arr[arr[i]-1]){
            swap(arr[i], arr[arr[i]-1]);
            swapCount++;
        }
        else{
            i++;
        }
    }
    return swapCount;
}

void getDupsAndMissingElems_ArrayStartsFromZero(int arr[], int n,vector<int>& missingElems, vector<int>& dupElem ){
    int  i=0;
    while(i< n){
        if(arr[i]!= arr[arr[i]]){
            swap(arr[i], arr[arr[i]]);
        }
        else {
            i++;
        }
    }
    
    for( int i=0;i<n;i++){
        if(arr[i]!=i){
            missingElems.push_back(i);
            dupElem.push_back(arr[i]);
        }
    }
    return;
}

void getDupsAndMissingElems_ArrayStartsFromOne(int arr[], int n , vector<int>& missingElems, vector<int>& dupElem){
    int  i=0;
    while(i< n){
        if(arr[i] != arr[arr[i]-1]){
            swap(arr[i], arr[arr[i]-1]);
        }
        else{
            i++;
        }
    }
    
    for( int i=0;i<n;i++){
        if(arr[i]!=(i+1)){
            missingElems.push_back(i+1);
            dupElem.push_back(arr[i]);
        }
    }
    return;
}


/*
 * 
 */
int main(int argc, char** argv) {
    
    int arr2[] ={1,0,5,4,3,2};
    cout<<endl<<"Number of Swaps needed to sort the array with no Dups and Missing Elements is " <<swapSortNoDupsOrMissingElemsArrayHasZero(arr2, 6);
    cout<<endl<<"Sorted List is ";
    for(int i=0; i<6;i++){
        cout<< arr2[i]<<"\t";
    }
    
    int arr3[] ={1,6,5,4,3,2};
    cout<<endl<<"Number of Swaps needed to sort the array with no Dups and Missing Elements is " <<swapSortNoDupsOrMissingElemsArrayStartsFromOne(arr3, 6);
    cout<<endl<<"Sorted List is ";
    for(int i=0; i<6;i++){
        cout<< arr3[i]<<"\t";
    }
    
    int arr[]={2,1,3,0,2,5,5,5};
    vector<int> missingElements;
    vector<int> duplicateElements;
    getDupsAndMissingElems_ArrayStartsFromZero(arr, 8,missingElements, duplicateElements);

    cout <<endl<<"Printing duplicates and missing elements : ";
    cout<<endl<<" Missing Elements :";
    for( auto x: missingElements){
        cout<< x<<"\t";
    }
    cout<<endl<<" duplicate Elements :";
    for( auto x: duplicateElements){
        cout<< x<<"\t";
    }    
    int arr1[]={2,1,4,3,3,5,5,5};
    vector<int> missingElements1;
    vector<int> duplicateElements1;
    getDupsAndMissingElems_ArrayStartsFromOne(arr1,8,missingElements1, duplicateElements1);

    cout <<endl<<"Now printing duplicates and missing elements : ";
    cout<<endl<<" Missing Elements :";
    for( auto x: missingElements1){
        cout<< x<<"\t";
    }
    cout<<endl<<" duplicate Elements :";
    for( auto x: duplicateElements1){
        cout<< x<<"\t";
    }
    return 0;
}

