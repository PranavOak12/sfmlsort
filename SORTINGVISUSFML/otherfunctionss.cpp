#include "otherfunctionss.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

void CopyArray(int src[],int dest[],int n) //here i have added size parameter for the printchange func to work properly 
{
    for (int i = 0;i < n;i++)
    {
        dest[i] = src[i];
    }
}

int randomnumbetween(int a,int b)
{
    std::random_device rd;
    std::mt19937 mtengine (rd());
    std::uniform_int_distribution<int> distribution(a,b);
    int randomnum = distribution(mtengine);
    return randomnum;
}

double getwavelenght(int arrayvalue)
{
    return (3*arrayvalue + 400);
}

double gamma_correction(double value, double gamma) 
{
    return std::pow(value, gamma);
}
#include <vector>
#include <cmath>

std::vector<int> wavelength_to_rgb(double wavelength, double gamma)
{
    double attenuation, R, G, B;

    if (wavelength >= 380 && wavelength <= 440) {
        attenuation = 0.3 + 0.7 * (wavelength - 380) / (440 - 380);
        R = gamma_correction((-(wavelength - 440) / (440 - 380)) * attenuation, gamma);
        G = 0.0;
        B = gamma_correction((1.0 * attenuation), gamma);
    } else if (wavelength >= 440 && wavelength <= 490) {
        R = 0.0;
        G = gamma_correction(((wavelength - 440) / (490 - 440)), gamma);
        B = 1.0;
    } else if (wavelength >= 490 && wavelength <= 510) {
        R = 0.0;
        G = 1.0;
        B = gamma_correction((-(wavelength - 510) / (510 - 490)), gamma);
    } else if (wavelength >= 510 && wavelength <= 580) {
        R = gamma_correction(((wavelength - 510) / (580 - 510)), gamma);
        G = 1.0;
        B = 0.0;
    } else if (wavelength >= 580 && wavelength <= 645) {
        R = 1.0;
        G = gamma_correction((-(wavelength - 645) / (645 - 580)), gamma);
        B = 0.0;
    } else if (wavelength >= 645 && wavelength <= 750) {
        attenuation = 0.3 + 0.7 * (750 - wavelength) / (750 - 645);
        R = gamma_correction((1.0 * attenuation), gamma);
        G = 0.0;
        B = 0.0;
    } else {
        R = 0.0;
        G = 0.0;
        B = 0.0;
    }

    int intR = static_cast<int>(R * 255);
    int intG = static_cast<int>(G * 255);
    int intB = static_cast<int>(B * 255);

    // Create a vector and store the RGB values
    std::vector<int> rgbVector = {intR, intG, intB};

    return rgbVector;
}
