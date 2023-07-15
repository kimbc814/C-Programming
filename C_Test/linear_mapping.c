#include <stdio.h>

#define NO_CALIBRATION_POINT 5

struct CalibrationData {
    double X[NO_CALIBRATION_POINT];
    double y[NO_CALIBRATION_POINT];
}cal_data;

double linear_mapping(double x, struct CalibrationData cal_data)
{
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;

    if (x <= cal_data.X[0]) {
         x1 = cal_data.X[0];
         x2 = cal_data.X[1];
         y1 = cal_data.y[0];
         y2 = cal_data.y[1];
    }
    else if (x >= cal_data.X[NO_CALIBRATION_POINT - 1]) {
         x1 = cal_data.X[NO_CALIBRATION_POINT - 2];
         x2 = cal_data.X[NO_CALIBRATION_POINT - 1];
         y1 = cal_data.y[NO_CALIBRATION_POINT - 2];
         y2 = cal_data.y[NO_CALIBRATION_POINT - 1];
    }
    else {
        int i = 0;
        for (i = 0; i < NO_CALIBRATION_POINT - 1; i++) {
            if (x >= cal_data.X[i] && x < cal_data.X[i + 1]) {
                break;
            }
        }
         x1 = cal_data.X[i];
         x2 = cal_data.X[i + 1];
         y1 = cal_data.y[i];
         y2 = cal_data.y[i + 1];

    }
    double y = y1 + (x - x1) * ((y2 - y1) / (x2 - x1));
    return y;
}

int main()
{
    cal_data = {
        {0.0, 1.0, 2.0, 3.0, 4.0},
        {-30.0, -15.0, 0.0, 15.0, 30.0}  // y °ª
    };

    double x = 2.0;
    double mapped_value = linear_mapping(x, cal_data);
    printf("Mapped value: %.2f\n", mapped_value);

    return 0;
}