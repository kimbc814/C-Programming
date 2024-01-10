#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>

class RLC_Circuit {
private:
    double R;
    double L;
    double C;
    double frequency;
    double V_p;

    double X_L;
    double X_C;
    double Z;

    double I_p;
    double phase_angle;

    void calculateParameters() {
        X_L = 2 * M_PI * frequency * L;
        X_C = 1.0 / (2 * M_PI * frequency * C);
        Z = sqrt(pow(R, 2) + pow(X_L - X_C, 2));
        I_p = V_p / Z;
        phase_angle = 180.0 / M_PI * atan((X_L - X_C) / R);
    }

public:
    RLC_Circuit() {
        R = 0.0;
        L = 0.0;
        C = 0.0;
        frequency = 0.0;
        V_p = 0.0;

        X_L = 0.0;
        X_C = 0.0;
        Z = 0.0;

        I_p = 0.0;
        phase_angle = 0.0;
    }
    ~RLC_Circuit() {
    }
    void getInput() {
        std::cout << "input R (ohm): ";
        std::cin >> R;

        std::cout << "input L (Henry): ";
        std::cin >> L;

        std::cout << "input C (micro Farad): ";
        std::cin >> C;
        C = C / pow(10, 6);

        std::cout << "input frequency : ";
        std::cin >> frequency;

        std::cout << "input V_p : ";
        std::cin >> V_p;
    }

    void displayResults() {
        circuit.calculateParameters();
        std::printf("X_L = 2 * PI * frequency * L =  %0.3lf(ohm)\n", X_L);
        std::printf("X_C =1 / (2 * PI * frequency * C) = %0.3lf(ohm)\n", X_C);
        std::printf("Z = (R^2 + (X_L -X_C)^2 )^(1/2) = %0.3lf(ohm)\n", Z);

        std::printf("I_p = V_p / Z = %0.3lf (A)\n", I_p);
        std::printf("phase angle = atan((X_L-X_C) / R) = %0.1lf(deg)\n", phase_angle);

        std::printf("V_R최대 = I_최대 * R = (%0.3lf ohm)(%0.3lf ohm) = %0.2lf V\n", I_p, R, I_p * R);
        std::printf("V_L최대 = I_최대 * L = (%0.3lf ohm)(%0.3lf ohm) = %0.2lf V\n", I_p, X_L, I_p * X_L);
        std::printf("V_C최대 = I_최대 * C = (%0.3lf ohm)(%0.3lf ohm) = %0.2lf V\n", I_p, X_C, I_p * X_C);
    }
};

int main() {
    RLCircuit circuit;
    
    circuit.getInput();
    circuit.displayResults();

    return 0;
}
