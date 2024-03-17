#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <iostream>
#include <random>
#include <cmath>
#include <vector>

double getwavelenght(int arrayvalue);
void printchange(int array[], int size);
void CopyArray(int src[], int dest[], int n);
int randomnumbetween(int a, int b);
double gamma_correction(double value, double gamma);
std::vector<int> wavelength_to_rgb(double wavelength = 0, double gamma = 0.8);
#endif // MY_HEADER_H
