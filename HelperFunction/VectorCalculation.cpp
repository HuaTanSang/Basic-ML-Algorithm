#pragma once 
#include <header.h>

class VectorCalculator
{
private: 
    vector<double> x; 
    vector<double> y; 

public: 
    // setter function 
    void setter(const vector<double> x_input, const vector<double> y_input) 
    {
        x = x_input; 
        y = y_input; 
    }

    // getter function 
    pair<vector<double>, vector<double>> getter(const vector<double> x, const vector<double> y)
    {
        return make_pair(x, y); 
    }

    // Element-wise multiply 
    vector<double> elementwiseMultiply(vector<double> a, vector<double> b)
    {
        // Check valid value
        if (x.size() != y.size()) 
        {
            throw runtime_error("Can not conduct multiplycation due to size mismatch!");
        }

        size_t lenght = x.size(); 
        vector<double> result(lenght); 

        for (int i = 0; i < lenght; i++) 
        {
            result[i] = x[i]*y[i]; 
        }

        return result; 
    }

    
};