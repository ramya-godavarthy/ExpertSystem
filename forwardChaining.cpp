// Forward Chaining 

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;

class forwardChaining{
       public:

       vector<string> conclst[30];
       vector<int> rule_number;
       vector<string> clvarlst;
       vector<string> varlst;
       queue<int> conclusion_queue;
       vector<string> conditions[30];
       string line,word;
       vector<string> instantiate;

       void forwardList();
       int forwardKnowledge();
       void display();
       void ask(int);
       void repair(string);
       void diagnosis();
};

void forwardChaining::forwardList()
{
  ifstream rules ("forward_rules.txt");
    
    if(rules.is_open())
    { 
            int n = 0;
        while(getline(rules,line))
        {
            stringstream s(line);
            int x = 0;
             s >> x;
            rule_number.push_back(x);
            int max = 0;
            s >> word;
            s >> word;
            s >> word;
            clvarlst.push_back(word);
            max++;
            varlst.push_back(word);
            s >> word;
            s >> word;
            while(s >> word){
              conclst[n].push_back(word);
              }
              while(max < 4){
              clvarlst.push_back("");
              max++;
              }
              n++;
            }   
        rules.close();
    }
   else cout << "Unable to open file" << endl;
   
for(int i = 0; i < varlst.size();i++){
  instantiate.push_back("NI");
 }
}

void forwardChaining::display(){
       forwardList();
    cout << "\n\t\t\t LIST REPRESENTATION FOR FORWARD CHAINING\t\t"<<endl;
    cout << "\n-----------------------------------------------------------------------------------------------\n";
    cout << "\n \t\t Variable List: " << endl;
    cout << "\n-----------------------------------------------------------------------------------------------\n";
     for(int i = 0; i < varlst.size(); i++){
            cout << varlst[i] << endl; 
     }

     cout << "\n-----------------------------------------------------------------------------------------------\n";
     cout << "\n Clause number and Clause Variable List: " << endl;
     cout << "\n-----------------------------------------------------------------------------------------------\n";
     for(int i = 0; i < clvarlst.size(); i++){
            cout << i+1 << "\t" << clvarlst[i] << endl; 
     }
    
    cout << "\n-----------------------------------------------------------------------------------------------\n";
     cout << "\n Conclusion List: " << endl;
     cout << "\n-----------------------------------------------------------------------------------------------\n";
     for(int i = 0; i < 30; i++){
             for(int j = 0; j < conclst[i].size(); j++)
            cout << conclst[i][j] << " "; 
            cout << endl;
     }
    
}

void forwardChaining::repair(string flt){
       forwardList();
       int i;
      for(i = 0; i < clvarlst.size(); i++){
          if(clvarlst[i] == flt)
          break;}
          cout << clvarlst[i]<<endl;
          int rulenum = (10 * ((i)/4 + 1));
          int m;
      for(m = 0; m < rule_number.size(); m++)
     {
             if(rule_number[m] == rulenum){
                     break;
             }
     }
     cout << "Repair Recommendation : \n"; 
             for(int l = 0; l < conclst[m].size(); l++) {  
             cout << conclst[m][l] << " ";
             }
             cout << endl;
}




