// Backward Chaining
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <stack>

using namespace std;

class backwardChaining{
       public:

       vector<string> conclst;
       vector<int> rule_number;
       vector<string> clvarlst;
       vector<string> varlst;
       stack<string> conclusion_stack;
       vector<string> conditions[30];
       string line,word,diagnosis_result;
       vector<string> instantiate;

       string ABS_LIGHT_ON, ACCELERATOR_HESITATION, AC_NOT_WORKING, BATTERY_TERMINALS_CONNECTIONS, BRAKE_SHUDDER, CARBURETOR_FLOODING, 
              CAR_STALLING, CHECK_ENGINE_LIGHT, CRANK, DELAYED_GEAR_SHIFT, DIM_ITERIOR_LIGHT, ENGINE_COLD, ENGINE_LIGHT_ON, ENGINE_MISFIRES, 
              ENGINE_SPUTTERS, ENGINE_TEMP_GAUGE, EXHAUST_HANGS_LOW, EXHAUST_SMOKE_COLOR, FUEL_TO_FILTER, GAS_CAP_LEAK, GAS_SMELL_WHEN_DRIVING, 
              GROWLING_NOISE, HARD_BRAKE_PEDAL, HEADLIGHTS_TURN, HIGH_ENGINE_REVIVING, IGNITION, INCREASED_STOPPING_DISTANCE, INTERIOR_LIGHTS_NOT_WORKING,
              LOW_OIL_PRESSURE_LIGHT_ON, NO_STARTER_NOISE, REDUCED_MILEAGE, REDUCTION_IN_MILEAGE, REFIGERENT_NOT_COOLING, ROUGH_IDLE, SLOW_ACCELERATION,
              SPARK_IN_SPARK_PLUG, STARTER_CLICKING, STARTER_MOTOR_WONT_START, STARTER_STALLING, STEERING_SHAKING, STICKY_BRAKE_CALIPER, SUDDEN_SPEED_SURGE,
              TRACTION_CONTROL_LIGHT_ON, UNEVENTREAD, UNEVEN_ACCELERATION, WIPER_FUSE_WORKING, WIPER_NOT_WORKING;
       
       void backwardList();
       int backwardKnowledge();
       void display();
       void ask(int);
       void conditionAsk(string);
       string diagnosis();
};

void backwardChaining::backwardList()
{
  ifstream rules ("backward_rules.txt");
    
    if(rules.is_open())
    {
        while(getline(rules,line))
        {
            stringstream s(line);
            int x = 0;
             s >> x;
            rule_number.push_back(x);
            int max = 0;
            while(s >> word){
              if (word == "IF" || word == "AND" || word == "THEN"
              || word =="YES" || word == "NO" || word == "SLOW"
              || word == "GOOD" || word == "GRAY" || word == "BLUE"
              || word == "WHITE" || word == "ON" || word == "BLACK")
                continue;
              else if(word == "PROBLEM")
                break;
              else{
                if(max < 4){
                clvarlst.push_back(word);
                max++;
                }
              }
                  
              }
              s >> word;
              conclst.push_back(word);
              while(max < 4){
              clvarlst.push_back("");
              max++;
              }
            }   
        rules.close();
    }
   else cout << "Unable to open file" << endl;
   int num = 0;
   for(int i = 0; i < rule_number.size(); i++){
       int clsnum = (4 * (rule_number[i]/10 - 1));
       while(clvarlst[clsnum] != ""){
         conditions[num].push_back(clvarlst[clsnum]);
         clsnum++;
       }
       num++;
   }
  
  vector<string> var;
  for(int i = 0; i < clvarlst.size(); i++)
      var.push_back(clvarlst[i]);

  sort(var.begin(), var.end());
  int j = 0;
  varlst.push_back(var[0]);
  for(int i = 1; i < var.size(); i++)
    {
      if (var[i] != varlst[j]){
      varlst.push_back(var[i]);
      j++;
      }
     else
     continue;
    }
for(int i = 0; i < varlst.size();i++){
  instantiate.push_back("NI");
 }
}

void backwardChaining::display(){
        backwardList();
    cout << "\n\t\t\t LIST REPRESENTATION FOR BACKWARD CHAINING\t\t"<<endl;
    cout << "\n-----------------------------------------------------------------------------------------------\n";    
    cout<<"\n Rule Number and Conclusion List: Faults and Conditions"<<endl;
    cout << "\n-----------------------------------------------------------------------------------------------\n";
    for(int i = 0; i < rule_number.size(); i++){
    cout << rule_number[i] << "\t" << conclst[i] << endl;
    for(int j = 0; j < conditions[i].size(); j++){
    cout << "\t\t" << conditions[i][j] << endl;
    }
    }

    cout << "\n-----------------------------------------------------------------------------------------------\n";
    cout << "\n Variable List: " << endl;
    cout << "\n-----------------------------------------------------------------------------------------------\n";
     for(int i = 0; i < varlst.size(); i++){
            cout << varlst[i] << endl; 
     }

     cout << "\n-----------------------------------------------------------------------------------------------\n";
     cout << "\n Clause Number and Clause Variable List: " << endl;
     cout << "\n-----------------------------------------------------------------------------------------------\n";
     for(int i = 0; i < clvarlst.size(); i++){
            cout << i+1 << "\t" << clvarlst[i] << endl; 
     }
}

void backwardChaining::ask(int i){
    switch(i){
        
       case 1: 
               cout << "Is ABS light On?: YES/No" << endl;
               cin >> ABS_LIGHT_ON;
               transform(ABS_LIGHT_ON.begin(), ABS_LIGHT_ON.end(), ABS_LIGHT_ON.begin(), ::toupper);
               break;

       case 2: 
                cout << "Does acceleration hesitates?: YES/No" << endl;
                cin >> ACCELERATOR_HESITATION;
                transform(ACCELERATOR_HESITATION.begin(), ACCELERATOR_HESITATION.end(), ACCELERATOR_HESITATION.begin(), ::toupper);
                break;

        case 3: 
                cout << "Is the Air Conditioner Working?: YES/No" << endl;
                cin >> AC_NOT_WORKING;
                transform(AC_NOT_WORKING.begin(), AC_NOT_WORKING.end(), AC_NOT_WORKING.begin(), ::toupper);
                break;

       case 4: 
               cout << "How is battery terminals?: good/bad" << endl;
               cin >> BATTERY_TERMINALS_CONNECTIONS;
               transform(BATTERY_TERMINALS_CONNECTIONS.begin(), BATTERY_TERMINALS_CONNECTIONS.end(), BATTERY_TERMINALS_CONNECTIONS.begin(), ::toupper);
               break;
      
      case 5: 
                cout << "Does brake shudder?: YES/No" << endl;
                cin >> BRAKE_SHUDDER;
                transform(BRAKE_SHUDDER.begin(), BRAKE_SHUDDER.end(), BRAKE_SHUDDER.begin(), ::toupper);
                break;

        case 6: 
                cout << "Is the carburetor flooding?: YES/No" << endl;
                cin >> CARBURETOR_FLOODING;
                transform(CARBURETOR_FLOODING.begin(), CARBURETOR_FLOODING.end(), CARBURETOR_FLOODING.begin(), ::toupper);
                break;
      case 7: 
               cout << "Is car stalling?: YES/No" << endl;
               cin >> CAR_STALLING;
               transform(CAR_STALLING.begin(), CAR_STALLING.end(), CAR_STALLING.begin(), ::toupper);
               break;
     
      
      case 8: 
               cout << "How is the engine light?: ON/OFF" << endl;
               cin >> CHECK_ENGINE_LIGHT;
               transform(CHECK_ENGINE_LIGHT.begin(), CHECK_ENGINE_LIGHT.end(), CHECK_ENGINE_LIGHT.begin(), ::toupper);
               break;

       case 9: 
                cout << "How is crank?: YES/No/slow" << endl;
                cin >> CRANK;
                transform(CRANK.begin(), CRANK.end(), CRANK.begin(), ::toupper);
                break;
       case 10: 
               cout << "Is there delay in the gear shift: YES/No" << endl;
               cin >> DELAYED_GEAR_SHIFT;
               transform(DELAYED_GEAR_SHIFT.begin(), DELAYED_GEAR_SHIFT.end(), DELAYED_GEAR_SHIFT.begin(), ::toupper);
               break;

       case 11: 
                cout << "Is the Interior light dim: YES/No" << endl;
                cin >> DIM_ITERIOR_LIGHT;
                transform(DIM_ITERIOR_LIGHT.begin(), DIM_ITERIOR_LIGHT.end(), DIM_ITERIOR_LIGHT.begin(), ::toupper);
                break;
       case 12: 
               cout << "Is engine cold: YES/No" << endl;
               cin >> ENGINE_COLD;
               transform(ENGINE_COLD.begin(), ENGINE_COLD.end(), ENGINE_COLD.begin(), ::toupper);
               break;

       case 13: 
                cout << "Is engine light on: YES/No" << endl;
                cin >> ENGINE_LIGHT_ON;
                transform(ENGINE_LIGHT_ON.begin(), ENGINE_LIGHT_ON.end(), ENGINE_LIGHT_ON.begin(), ::toupper);
                break;
       case 14: 
               cout << "Is engine misfires: YES/No" << endl;
               cin >> ENGINE_MISFIRES;
               transform(ENGINE_MISFIRES.begin(), ENGINE_MISFIRES.end(), ENGINE_MISFIRES.begin(), ::toupper);
               break;
      
      case 15: 
                cout << "Does engine sputters: YES/No" << endl;
                cin >> ENGINE_SPUTTERS;
                transform(ENGINE_SPUTTERS.begin(), ENGINE_SPUTTERS.end(), ENGINE_SPUTTERS.begin(), ::toupper);
                break;
      case 16: 
               cout << "Does engine temperature guage: YES/No" << endl;
               cin >> ENGINE_TEMP_GAUGE;
               transform(ENGINE_TEMP_GAUGE.begin(), ENGINE_TEMP_GAUGE.end(), ENGINE_TEMP_GAUGE.begin(), ::toupper);
               break;

      case 17: 
                cout << "Does exhaust hangs low: YES/No" << endl;
                cin >> EXHAUST_HANGS_LOW;
                transform(EXHAUST_HANGS_LOW.begin(), EXHAUST_HANGS_LOW.end(), EXHAUST_HANGS_LOW.begin(), ::toupper);
                break;
       case 18: 
               cout << "How is smoke from exhaust: black/gray/blue/white" << endl;
               cin >> EXHAUST_SMOKE_COLOR;
               transform(EXHAUST_SMOKE_COLOR.begin(), EXHAUST_SMOKE_COLOR.end(), EXHAUST_SMOKE_COLOR.begin(), ::toupper);
               break;

       case 19: 
                cout << "Is there fuel to filter: YES/No" << endl;
                cin >> FUEL_TO_FILTER;
                transform(FUEL_TO_FILTER.begin(), FUEL_TO_FILTER.end(), FUEL_TO_FILTER.begin(), ::toupper);
                break;
       case 20: 
               cout << "Does gas cap leak: YES/No" << endl;
               cin >> GAS_CAP_LEAK;
               transform(GAS_CAP_LEAK.begin(), GAS_CAP_LEAK.end(), GAS_CAP_LEAK.begin(), ::toupper);
               break;

       case 21: 
                cout << "Does gas smell while driving: YES/No" << endl;
                cin >> GAS_SMELL_WHEN_DRIVING;
                transform(GAS_SMELL_WHEN_DRIVING.begin(), GAS_SMELL_WHEN_DRIVING.end(), GAS_SMELL_WHEN_DRIVING.begin(), ::toupper);
                break;
       case 22: 
               cout << "Is there any growling noise: YES/No" << endl;
               cin >> GROWLING_NOISE;
               transform(GROWLING_NOISE.begin(), GROWLING_NOISE.end(), GROWLING_NOISE.begin(), ::toupper);
               break;

       case 23: 
                cout << "Is the brake pedal hard: YES/No" << endl;
                cin >> HARD_BRAKE_PEDAL;
                transform(HARD_BRAKE_PEDAL.begin(), HARD_BRAKE_PEDAL.end(), HARD_BRAKE_PEDAL.begin(), ::toupper);
                break;

       case 24: 
                cout << "Does headlights turn On: YES/No" << endl;
                cin >> HEADLIGHTS_TURN;
                transform(HEADLIGHTS_TURN.begin(), HEADLIGHTS_TURN.end(), HEADLIGHTS_TURN.begin(), ::toupper);
                break;
                
       case 25: 
               cout << "Does engine reviving high: YES/No" << endl;
               cin >> HIGH_ENGINE_REVIVING;
               transform(HIGH_ENGINE_REVIVING.begin(), HIGH_ENGINE_REVIVING.end(), HIGH_ENGINE_REVIVING.begin(), ::toupper);
               break;
      
      case 26: 
                cout << "Is Ignition: ON/OFF" << endl;
                cin >> IGNITION;
                transform(IGNITION.begin(), IGNITION.end(), IGNITION.begin(), ::toupper);
                break;
      case 27: 
               cout << "Is stopping distance increased: YES/No" << endl;
               cin >> INCREASED_STOPPING_DISTANCE;
               transform(INCREASED_STOPPING_DISTANCE.begin(), INCREASED_STOPPING_DISTANCE.end(), INCREASED_STOPPING_DISTANCE.begin(), ::toupper);
               break;
     
       case 28: 
               cout << "Is interior light working?: YES/No" << endl;
               cin >> INTERIOR_LIGHTS_NOT_WORKING;
               transform(INTERIOR_LIGHTS_NOT_WORKING.begin(), INTERIOR_LIGHTS_NOT_WORKING.end(), INTERIOR_LIGHTS_NOT_WORKING.begin(), ::toupper);
               break;

       case 29: 
                cout << "Is oil pressure light On?: YES/No" << endl;
                cin >> LOW_OIL_PRESSURE_LIGHT_ON;
                transform(LOW_OIL_PRESSURE_LIGHT_ON.begin(), LOW_OIL_PRESSURE_LIGHT_ON.end(), LOW_OIL_PRESSURE_LIGHT_ON.begin(), ::toupper);
                break;
       case 30: 
               cout << "Is there noise in starter?: YES/No" << endl;
               cin >> NO_STARTER_NOISE;
               transform(NO_STARTER_NOISE.begin(), NO_STARTER_NOISE.end(), NO_STARTER_NOISE.begin(), ::toupper);
               break;

       case 31: 
                cout << "Is the mileage reduced?: YES/No" << endl;
                cin >> REDUCED_MILEAGE;
                transform(REDUCED_MILEAGE.begin(), REDUCED_MILEAGE.end(), REDUCED_MILEAGE.begin(), ::toupper);
                break;
       case 32: 
               cout << "Is there reduction in mileage?: YES/No" << endl;
               cin >> REDUCTION_IN_MILEAGE;
               transform(REDUCTION_IN_MILEAGE.begin(), REDUCTION_IN_MILEAGE.end(), REDUCTION_IN_MILEAGE.begin(), ::toupper);
               break;

       case 33: 
                cout << "Does refigerent cooling?: YES/No" << endl;
                cin >> REFIGERENT_NOT_COOLING;
                transform(REFIGERENT_NOT_COOLING.begin(),REFIGERENT_NOT_COOLING.end(), REFIGERENT_NOT_COOLING.begin(), ::toupper);
                break;

        case 34: 
                cout << "Does car idles rough?: YES/No" << endl;
                cin >> ROUGH_IDLE;
                transform(ROUGH_IDLE.begin(), ROUGH_IDLE.end(), ROUGH_IDLE.begin(), ::toupper);
                break;
       case 35: 
               cout << "Does acceleration slowed?: YES/No" << endl;
               cin >> SLOW_ACCELERATION;
               transform(SLOW_ACCELERATION.begin(), SLOW_ACCELERATION.end(), SLOW_ACCELERATION.begin(), ::toupper);
               break;
      
      case 36: 
                cout << "Is there spark in spark plug: YES/No" << endl;
                cin >> SPARK_IN_SPARK_PLUG;
                transform(SPARK_IN_SPARK_PLUG.begin(), SPARK_IN_SPARK_PLUG.end(), SPARK_IN_SPARK_PLUG.begin(), ::toupper);
                break;
      case 37: 
               cout << "Is the starter clicking?: YES/No" << endl;
               cin >> STARTER_CLICKING;
               transform(STARTER_CLICKING.begin(), STARTER_CLICKING.end(), STARTER_CLICKING.begin(), ::toupper);
               break;

      case 38: 
               cout << "Does starter motor wont stop?: YES/No" << endl;
               cin >> STARTER_MOTOR_WONT_START;
               transform(STARTER_MOTOR_WONT_START.begin(), STARTER_MOTOR_WONT_START.end(), STARTER_MOTOR_WONT_START.begin(), ::toupper);
               break;


      case 39: 
               cout << "Is the starter stalling?: YES/No" << endl;
               cin >> STARTER_STALLING;
               transform(STARTER_STALLING.begin(), STARTER_STALLING.end(), STARTER_STALLING.begin(), ::toupper);
               break;
               
       case 40: 
                cout << "Is the steering shaking: YES/No" << endl;
                cin >> STEERING_SHAKING;
                transform(STEERING_SHAKING.begin(), STEERING_SHAKING.end(), STEERING_SHAKING.begin(), ::toupper);
                break;
       case 41: 
               cout << "Is the brake caliper sticky: YES/No" << endl;
               cin >> STICKY_BRAKE_CALIPER;
               transform(STICKY_BRAKE_CALIPER.begin(), STICKY_BRAKE_CALIPER.end(), STICKY_BRAKE_CALIPER.begin(), ::toupper);
               break;

       case 42: 
                cout << "Is there sudden speed surge?: YES/No" << endl;
                cin >> SUDDEN_SPEED_SURGE;
                transform(SUDDEN_SPEED_SURGE.begin(), SUDDEN_SPEED_SURGE.end(), SUDDEN_SPEED_SURGE.begin(), ::toupper);
                break;
       case 43: 
               cout << "Is traction control light on?: YES/No?" << endl;
               cin >> TRACTION_CONTROL_LIGHT_ON;
               transform(TRACTION_CONTROL_LIGHT_ON.begin(), TRACTION_CONTROL_LIGHT_ON.end(), TRACTION_CONTROL_LIGHT_ON.begin(), ::toupper);
               break;

       case 44: 
                cout << "Is the acceleration uneven : YES/No" << endl;
                cin >> UNEVEN_ACCELERATION;
                transform(UNEVEN_ACCELERATION.begin(), UNEVEN_ACCELERATION.end(), UNEVEN_ACCELERATION.begin(), ::toupper);
                break;
       case 45: 
               cout << "Is the tread uneven: YES/No" << endl;
               cin >> UNEVENTREAD;
               transform(UNEVENTREAD.begin(), UNEVENTREAD.end(), UNEVENTREAD.begin(), ::toupper);
               break;

       case 46: 
                cout << "Is the wiper fuse working: YES/No" << endl;
                cin >> WIPER_FUSE_WORKING;
                transform(WIPER_FUSE_WORKING.begin(), WIPER_FUSE_WORKING.end(), WIPER_FUSE_WORKING.begin(), ::toupper);
                break;
       case 47: 
               cout << "Is the wiper working: YES/No" << endl;
               cin >> WIPER_NOT_WORKING;
               transform(WIPER_NOT_WORKING.begin(), WIPER_NOT_WORKING.end(), WIPER_NOT_WORKING.begin(), ::toupper);
               break;

       default:
             cout << "Invalid Entry" << endl;
        }   
}

void backwardChaining::conditionAsk(string flt){
       int i;
      for(i = 0; i < conclst.size(); i++){
          if(conclst[i] == flt)
          break;}

  int clsnum = (4 * (rule_number[i]/10 - 1));
  while(clvarlst[clsnum] != ""){
      conclusion_stack.push(clvarlst[clsnum]);
      clsnum++;
  }
  
  while(!conclusion_stack.empty()){
    int j;
     for(j = 0; j < varlst.size(); j++ ) {
        if(conclusion_stack.top() == varlst[j])
        break;
     }
     if(instantiate[j] != "I" ){
       ask(j);
      instantiate[j] = "I";
     }
     conclusion_stack.pop();
  }
}

int backwardChaining :: backwardKnowledge(){
     //Checks if conditions for the fault are true
     int s = 0;
     
                if(IGNITION == "ON" && CRANK == "YES" && SPARK_IN_SPARK_PLUG == "NO" )
                         s = 1;
                        
	         if(CRANK =="YES" && STARTER_STALLING =="YES") 
                        s = 1;
                        
                 if (CRANK =="YES" && INTERIOR_LIGHTS_NOT_WORKING =="YES") 
                        s = 1;
                        
	         if (CRANK == "NO" && BATTERY_TERMINALS_CONNECTIONS == "GOOD" && HEADLIGHTS_TURN =="YES") 
                        s = 1;
                        
	         if (CRANK == "SLOW" && STARTER_CLICKING =="YES") 
                        s = 1;
                        
                 if (STARTER_CLICKING =="YES" && STARTER_MOTOR_WONT_START =="YES") 
                        s = 1;
                        
	         if (SPARK_IN_SPARK_PLUG =="YES" && FUEL_TO_FILTER == "NO")
                        s = 1;
                        
	         if (STEERING_SHAKING =="YES" && UNEVENTREAD =="YES") 
                        s = 1;
                        
	         if (ENGINE_SPUTTERS =="YES" && REDUCTION_IN_MILEAGE =="YES") 
                        s = 1;
                        
	         if (REDUCED_MILEAGE =="YES" && ROUGH_IDLE =="YES" )
                        s = 1;
                        
	         if (CAR_STALLING =="YES" && ENGINE_TEMP_GAUGE =="YES") 
                       s = 1;
                       
	         if (CAR_STALLING =="YES" && NO_STARTER_NOISE =="YES") 
                       s = 1;
                       
	         if (ENGINE_MISFIRES =="YES" && EXHAUST_SMOKE_COLOR == "BLACK")
                        s = 1;
                       
	         if (EXHAUST_SMOKE_COLOR == "GRAY") 
                        s = 1;
                       
	         if (EXHAUST_SMOKE_COLOR == "BLUE") 
                       s = 1;
                       
	         if (EXHAUST_SMOKE_COLOR == "WHITE" && ENGINE_COLD =="YES") 
                       s = 1;
                       
	         if (BRAKE_SHUDDER =="YES" && STICKY_BRAKE_CALIPER =="YES") 
                       s = 1;
                       
	         if (GAS_SMELL_WHEN_DRIVING =="YES" && GAS_CAP_LEAK == "NO") 
                      s = 1;
                      
	         if (GAS_SMELL_WHEN_DRIVING =="YES" && CARBURETOR_FLOODING =="YES") 
                      s = 1;
                      
	         if (CHECK_ENGINE_LIGHT == "ON" && UNEVEN_ACCELERATION =="YES") 
                      s = 1;
                     
	         if (ABS_LIGHT_ON =="YES" && TRACTION_CONTROL_LIGHT_ON =="YES") 
                       s = 1;
                       
	         if (DELAYED_GEAR_SHIFT =="YES" && HIGH_ENGINE_REVIVING =="YES") 
                        s = 1;
                       
	         if (AC_NOT_WORKING =="YES" && REFIGERENT_NOT_COOLING =="YES") 
                         s = 1;
                        
	         if (HARD_BRAKE_PEDAL =="YES" && INCREASED_STOPPING_DISTANCE =="YES" )
                        s = 1;
                       
	         if (ACCELERATOR_HESITATION =="YES" && SUDDEN_SPEED_SURGE =="YES") 
                        s = 1;
                       
	         if (SLOW_ACCELERATION =="YES" && ENGINE_LIGHT_ON =="YES") 
                       s = 1;
                       
	         if (DIM_ITERIOR_LIGHT =="YES" && GROWLING_NOISE =="YES") 
                        s = 1;
                        
	         if (LOW_OIL_PRESSURE_LIGHT_ON =="YES") 
                        s = 1;
                       
	         if (WIPER_NOT_WORKING =="YES" && WIPER_FUSE_WORKING =="YES")
                        s = 1;
                        
	         if (EXHAUST_HANGS_LOW =="YES") 
                         s = 1;

     return s;
}

string backwardChaining::diagnosis(){
        backwardList();
       cout << "Answer the following questions to identify faults: "<< endl;
       for(int i = 0; i < conclst.size();i++) {
              conditionAsk(conclst[i]);
              int f = 0;
              f = backwardKnowledge();
              if(f == 1){
                      diagnosis_result = conclst[i];
                cout << "Fault identified in: " << diagnosis_result << endl;
                break;
              }  
              else if(i==conclst.size())
              diagnosis_result = " No Fault Found ";
       }
       return diagnosis_result;
}




