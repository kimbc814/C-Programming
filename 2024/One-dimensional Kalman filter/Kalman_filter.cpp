#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MEASUREMENT_COUNT 458  // 데이터 개수
#define PROCESS_NOISE_COVARIANCE 0.0001 // 프로세스 노이즈의 분산 
#define MEASUREMENT_NOISE_COVARIANCE 0.2 // 측정 노이즈의 분산 

// 칼만 필터 구조체 정의
typedef struct {
    double xHat; // 추정된 상태 변수
    double P; // 상태 공분산
    double Q; // 프로세스 노이즈 공분산
    double R; // 측정 노이즈 공분산
} KalmanFilter;

// 칼만 필터 초기화 함수
void kalmanFilterInit(KalmanFilter* kf, double initial_estimate, double initial_covariance) {
    kf->xHat = initial_estimate;
    kf->P = initial_covariance;
    kf->Q = PROCESS_NOISE_COVARIANCE; // 프로세스 노이즈의 분산 설정
    kf->R = MEASUREMENT_NOISE_COVARIANCE; // 측정 노이즈의 분산 설정
}


void kalmanPredict(KalmanFilter* kf) {
    // 예측 단계: 상태 및 공분산 예측
    kf->xHat = kf->xHat;
    kf->P = kf->P + kf->Q;
}

void kalmanUpdate(KalmanFilter* kf, double measurement) {
    // 측정 단계: 측정을 사용하여 상태 및 공분산 업데이트
    double K = kf->P / (kf->P + kf->R);
    kf->xHat = kf->xHat + K * (measurement - kf->xHat);
    kf->P = (1 - K) * kf->P;
}
void kalmanOptimizeParameters(KalmanFilter* kf, double measurements[], int measurement_count) {
    double min_error = DBL_MAX; // 최소 오차
    double best_Q, best_R; // 최적의 Q와 R 값
    double Q_candidate, R_candidate; // 후보 Q와 R 값

    // Q와 R 값 후보 범위 설정
    double Q_min = 0.00001;
    double Q_max = 1.0;
    double R_min = 0.001;
    double R_max = 5.0;

    // Q와 R 값 후보들을 반복적으로 시도하여 최적의 값을 찾음
    for (Q_candidate = Q_min; Q_candidate <= Q_max; Q_candidate += 0.01) {
        for (R_candidate = R_min; R_candidate <= R_max; R_candidate += 0.01) {
            kalmanFilterInit(kf, measurements[0], 1.0); // 초기화
            kf->Q = Q_candidate;
            kf->R = R_candidate;

            double total_error = 0.0;
            for (int i = 0; i < measurement_count; ++i) {
                kalmanPredict(kf);
                kalmanUpdate(kf, measurements[i]);
                total_error += kf->P; // 예측 오차의 합산
            }

            // 최소 오차인 경우 최적의 Q와 R 값을 업데이트
            if (total_error < min_error) {
                min_error = total_error;
                best_Q = Q_candidate;
                best_R = R_candidate;
            }
        }
    }

    // 최적의 Q와 R 값을 설정
    kf->Q = best_Q;
    kf->R = best_R;
    printf("Q : %lf\tR : %lf\n", best_Q, best_R);
}

int main() {
    //데이터 입출력 경로 지정
    char filepath_input[3][100] = { "C:/Users/pc_01/Desktop/input1.txt" ,"C:/Users/pc_01/Desktop/input2.txt" ,"C:/Users/pc_01/Desktop/input3.txt" };
    char fileath_output[3][100] = { "C:/Users/pc_01/Desktop/output1.txt" ,"C:/Users/pc_01/Desktop/output2.txt" ,"C:/Users/pc_01/Desktop/output3.txt" };

    for (int jj = 0; jj < 3; jj++) {
        FILE* input_file = fopen(filepath_input[jj], "r");
        if (input_file == NULL) {
            printf("Error opening input file.\n");
            return 1;
        }
        double measurements[MEASUREMENT_COUNT];
        for (int i = 0; i < MEASUREMENT_COUNT; ++i) {
            if (fscanf(input_file, "%lf", &measurements[i]) != 1) {
                printf("Error reading input file.\n");
                fclose(input_file);
                return 1;
            }
        }
        fclose(input_file);

        KalmanFilter kf;
        kalmanFilterInit(&kf, measurements[0], 1.0); // 초기 상태 추정값과 공분산 값 설정
        kalmanOptimizeParameters(&kf, measurements, MEASUREMENT_COUNT);


        double filtered_measurements[MEASUREMENT_COUNT];
        for (int i = 0; i < MEASUREMENT_COUNT; ++i) {
            // 예측 단계
            kalmanPredict(&kf);

            // 업데이트 단계
            kalmanUpdate(&kf, measurements[i]);

            // 필터링된 결과 저장
            filtered_measurements[i] = kf.xHat;
        }

        FILE* output_file = fopen(fileath_output[jj], "w");
        if (output_file == NULL) {
            printf("Error opening output file.\n");
            return 1;
        }

        for (int i = 0; i < MEASUREMENT_COUNT; ++i) {
            fprintf(output_file, "%.8f\n", filtered_measurements[i]);
        }

        fclose(output_file);
    }

    return 0;
}
