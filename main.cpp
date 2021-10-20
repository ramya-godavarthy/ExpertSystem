/*
 * main.cpp
 *
 */
#include <iostream>
#include <string>
#include "backwardChaining.cpp"
#include "forwardChaining.cpp"
using namespace std;
int main() {
cout << "\t--------------------------------------------------------------------------------------" << endl << endl;
cout << "\t\tExpert System for Car Diagnosis and Repair Recommendation" << endl;
cout << "\t--------------------------------------------------------------------------------------" << endl << endl;
bool exitOption = false; int option;
string fault_ans, fault, represent;
string listDisplay;
      while (!exitOption)
      {
             cout << endl;
             cout << "\tChoose an option from the following:" << endl;
             cout << "\t\t1. Car Fault Detection and Diagnosis " << endl;
             cout << "\t\t2. Repair Recommendation" << endl;
             cout << "\t\t3. Display the list" << endl;
             cout << "\t\t4. exit" << endl;
             cin >> option;
             backwardChaining back;
             forwardChaining forward;
             switch (option)
             {
             case 1:
             {
            cout << "\t------------------------------------------------------------------------------" << endl << endl;   
            cout << "\t\t\t\t CAR DIAGNOSIS SYSTEM" << endl;
            cout << "\t\t\tPlease answer the following symptoms:" << endl;
            cout << "\t------------------------------------------------------------------------------" << endl << endl;
                   fault = back.diagnosis();
                   if (fault != "No Fault Found") {
                   cout << "=============================================" << endl << endl;
                          cout << "Do you want repair recommendation for identified " << fault << " : Yes/No" << endl;
                          cin >> fault_ans;
                          transform(fault_ans.begin(), fault_ans.end(), fault_ans.begin(), ::toupper); 
                          if (fault_ans == "YES")
                          {
                         transform(fault.begin(), fault.end(), fault.begin(), ::toupper);
                         forward.repair(fault);
                          }
                   }
                  cout << "Exiting fault Identification System" << endl; break;
                   }
             
            case 2: {
            cout << "\tEnter the fault from the given list: " << endl;
            cout << " FAULTY_SPARK_PLUG\tFUEL_PUMP_MOTOR\tBLOWN_FUSE\tDEAD_BATTERY\tSTARTER_MOTOR\tSTARTER_SOLENOID\tFUEL_PUMP_BLOCKAGE\n"
                  << "DAMAGED_WHEEL_BEARING\tAIR_FLOW_SENSOR\tFUEL_RATIO_SENSOR\tFUEL_PUMP_MOTOR\tFAULTY_IGNITION_SWITCH\tFAULTY_FUEL_PRESSURE_REGULATOR\n"
                  << "CLOGGED_AIR_FILTER\tOIL_LEAK_IN_COMBUSTION_CHAMBER\tCOOLENT_VAPORIZATION\tUNEVEN_BRAKE_DISCS\tLEAK_IN_SYSTEM\tFAILING_FUEL_RETURN_HOSE\n"
                  << "CRANKSHAFT_POSITION_SENSOR_FAILURE\tFAULTY_ABS_WHEEL_SPEED_SENSOR\tLOW_TRANSMISSION_FLUID\tBLOCKED_CONDENSER\tBAD_BRAKE_BOOSTER\n"
                  << "FAULTY_THROTTLE_SENSOR\tFAULTY_SPARK_KNOCK_SENSOR\tBAD_ALTERNATOR\tLOW_OIL_LEVEL\tWIPER_MOTOR\tEXHAUST_HANGER_SYSTEM_FAULT\n\n"<< endl;
            cin >> fault;
            transform(fault.begin(), fault.end(), fault.begin(), ::toupper); 
            forward.repair(fault);
            break;
            }

            case 3 : {
                  back.display();
                  forward.display();
                  break;
            }

           case 4  : {
             exitOption = true;
                   cout << "\t\tThank you for using expert system " << endl;
                   break;
                 } 
            default: {
                   cout << "Invalid Entry";
                  break; }
            } }
return 0; }

     
