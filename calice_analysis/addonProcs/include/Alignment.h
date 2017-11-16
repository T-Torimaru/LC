#ifndef ALIGNMENT_HH
#define ALIGNMENT_HH 1

// additional file for setup alignment

const unsigned NUM_RUNS = 15;
const unsigned NUM_SHIFTS = 8;
float ALIGN[NUM_RUNS][NUM_SHIFTS] = {
  {330645,   8.2,   0.9, -14.6,   -9.3,  -22.0,    -5.5,   -201.0},
  {330328,   6.9,  -3.7, -14.9,  -21.3,  -31.7,   -17.7,   -201.0},
  {330326,   6.6,   2.0, -15.3,  -16.4,  -33.1,   -12.7,   -201.0},
  {330332,   8.0,  -0.7, -13.6,  -18.1,  -28.9,   -14.2,   -201.0},
  {330796,   7.9,  -2.7, -13.5,  -11.9,  -20.6,    -5.8,   -201.0},
  {330797,   6.5,  -1.7, -15.2,  -11.0,  -23.7,    -3.5,   -201.0},
  {330777,   8.8,   1.2,  -8.0,  -56.7,  -16.7,   -52.6,   -201.0},
  {330850,   9.4,   3.7,   6.3,   -5.3,  -12.9,    -2.7,   -201.0},
  {331298,   4.4,  -4.1,   0.7,   -3.7,  -26.4,   -10.6,   -201.0},
  {331324,   6.11,  -4.49,   3.03,   -3.73,  -26.17,   -10.55,   -201.0},
  {331337,   2.81,  -3.72,  -0.26,   -3.02,  -29.31,    -9.76,   -201.0},
  {331339,   1.81,  -4.39,  -1.43,   -3.48,  -30.33,   -10.34,   -201.0},
  {330773,   4.82,  -2.02, -12.28,  -60.45,  -22.00,   -57.23,   -201.0},
  {330848,   8.30,  -1.20,   5.80,  -11.40,  -17.40,    -8.20,   -201.0},
  {330849,   8.30,   3.00,   4.80,   -6.30,   -7.70,    -4.00,   -201.0}
};
float ALIGN_MC[NUM_RUNS][NUM_SHIFTS] = {
  {330645,   0.00,  -0.00, -0.00,  -0.00,  -0.00,   -0.00,   -201.0},
  {330328,   0.00,  -0.00, -0.00,  -0.00,  -0.00,   -0.00,   -201.0},
  {330326,   0.00,  -0.00, -0.00,  -0.00,  -0.00,   -0.00,   -201.0},
  {330332,   0.00,   0.00, -14.73,  -18.16,    0.40,    -2.08,   -201.0},
  {330796,   7.91,  -2.70, -13.53,  -11.89,  -20.64,    -5.76,   -201.0},
  {330797,   6.46,  -1.67, -15.22,  -10.99,  -23.67,    -3.50,   -201.0},
  {330777,   0.00,   0.00, -17.08,  -79.50,  -47.50,   -75.70,   -201.0},
  {330773,   4.82,  -2.02, -12.28,  -60.45,  -22.00,   -57.23,   -201.0},
  {330848,   8.30,  -1.20,   5.80,  -11.40,  -17.40,    -8.20,   -201.0},
  {330849,   8.30,   3.00,   4.80,   -6.30,   -7.70,    -4.00,   -201.0},
  {330850,   0.00,   0.00,  74.00,   -5.40,   58.50,    -6.00,   -201.0},
  {331298,   0.00,  -0.00,  29.18,    8.05,  -27.65,    -9.73,   -201.0},
  {331324,   6.11,  -4.49,  31.33,    7.67,  -26.17,   -10.55,   -201.0},
  {331337,   2.81,  -3.72,  28.14,    8.38,  -29.31,    -9.76,   -201.0},
  {331339,   1.81,  -4.39,  26.87,    7.92,  -30.33,   -10.34,   -201.0}
};
#endif 
