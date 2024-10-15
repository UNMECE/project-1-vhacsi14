#include <iostream>
#include <iomanip>
#include <cmath>

struct _capacitor 
{
	double *time;       
	double *voltage;    
	double *current;    
	double C;           
};

typedef struct _capacitor Capacitor;



void allocCapacitor(Capacitor &cap, int num_timesteps) 
{
	capacitator.time = new double[num_timesteps];
	capacitator.voltage = new double[num_timesteps];
	capacitator.current = new double[num_timesteps];
}

void deallocCapacitor(Capacitor &cap) 
{
    delete[] capacitator.time;
    delete[] capacitator.voltage;
    delete[] capacitator.current;
}

void simuConstCurrent(Capacitor &cap, double I, double delta_t, int num_timesteps) 
{
	capacitator.voltage[0] = 0.0;  
	capacitator.current[0] = I;    
    
    for (int t = 1; t < num_timesteps; ++t) 
    {
        capacitator.voltage[t] = capacitator.voltage[t-1] + (capacitator.current[t-1] * delta_t / cap.C);
        capacitator.time[t] = t * delta_t;
        
        
        if (t % 200 == 0) 
	{
            std::cout << "Constant Current: Time = " << std::fixed << std::setprecision(6)
                      << capacitator.time[t] << " s, Voltage = " << capacitator.voltage[t] << " V\n";
        }
    }
}

void simConstantVoltage(Capacitor &cap, double V0, double R, double delta_t, int num_timesteps) 
{
    double initial_current = V0 / R;  
    capacitator.current[0] = initial_current;   
    capacitator.voltage[0] = 0.0;                
    capacitator.time[0] = 0.0;                   


    for (int t = 1; t < num_timesteps; ++t) 
    {
        capacitator.current[t] = capacitator.current[t-1] - (capacitator.current[t-1] * R * cap.C * delta_t);
        capacitator.voltage[t] = capacitator.voltage[t-1] + (capacitator.current[t-1] * delta_t / cap.C);
        capacitator.time[t] = t * delta_t;
        
        
        if (t % 200 == 0) 
	{
            std::cout << "Constant Voltage: Time = " << std::fixed << std::setprecision(6)
                      << capacitator.time[t] << " s, Voltage = " << capacitator.voltage[t] << " V, Current = " 
                      << capacitator.current[t] << " A\n";
        }
    }
}



int main() 
{
	const double delta_t = 1e-10;          

	const double final_time = 5e-6;        

	const int num_timesteps = static_cast<int>(final_time / delta_t);

	const double R = 1000.0;               

	const double C = 100e-12;             

 	const double I = 1e-2;                 

	const double V0 = 10.0;                


    Capacitor cap;
    	allocCapacitor(cap, num_timesteps);
    

    std::cout << "Simulating Constant Current Charging:\n";
    	simConstCurrent(cap, I, delta_t, num_timesteps);
    

    std::cout << "\nSimulating Constant Voltage Charging:\n";
    	simConstVoltage(cap, V0, R, delta_t, num_timesteps);

    deallocCapacitor(cap);
    
    return 0;
}

