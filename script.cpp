#include <bits/stdc++.h>

using namespace std;
float exploreExploitRatio = 0;

bool fx(vector<int>&tab, int max){
    
    //for(auto item : tab) cout << item << " ";
    int explore = INT_MIN;
    int exploit = 0;
    for(int i = 0; i < exploreExploitRatio*tab.size(); i++){
        explore = ((explore>tab[i])?(explore):(tab[i]));
        
    }
    
    for(int i = exploreExploitRatio*tab.size()+1; i < tab.size(); i++){
        if(tab[i] > explore){
            exploit = tab[i];
            break;
        }else if(i == tab.size()-1){
            exploit = tab[i];
        }
    }
    
   
    
    if(exploit == max){ return true;}
    else { return false;}
    
    
}

int main()
{
    
    int iterationCount = 0;
    
    cout << "how many times to run? ";
    cin >> iterationCount;
    
    vector<int>nums;
    
    int noOfElems = 0;
    cout << "no. of secretaries in the pool: ";
    cin >> noOfElems;
    
    for(int i = 0; i < noOfElems; i++){
        nums.push_back(i);
    }
    
    
    for(exploreExploitRatio = 0.01; exploreExploitRatio < 0.99; exploreExploitRatio += 0.01){
        int correctCount = 0;
        
        
        
        for(int j = 0; j < iterationCount; j++){
            
            shuffle(nums.begin(), nums.end(), random_device());
            if(fx(nums, noOfElems-1))correctCount++;
        }
        
        cout <<  "explore-exploit ratio of "<<(int)((exploreExploitRatio)*100) << "% results in " <<(int)(((float)correctCount/iterationCount)*100)<<"% accuracy"<< endl; 
    }
}
