/**
 *
 *      ┌─┐╔═╗┌┬┐┌─┐
 *      │  ║ ║ ││├┤
 *      └─┘╚═╝─┴┘└─┘
 *   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
 *   │  ├─┤║║║└┐┌┘├─┤└─┐
 *   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
 *
 * Copyright (c) 2017 Code on Canvas Pty Ltd, http://CodeOnCanvas.cc
 *
 * This software is distributed under the MIT license
 * https://tldrlegal.com/license/mit-license
 *
 **/


#pragma once

#include <memory>
#include <vector>

#include "tsne.h"

class CinderTSNE {
public:
    std::vector<std::vector<double>> run(std::vector<std::vector<float>> &data,
            int dims = 2, double perplexity = 30, double theta = 0.5,
            bool normalize = true, bool runManually = false);
    std::vector<std::vector<double> > iterate();

private:
    void finish();
    
    TSNE tsne;
    std::vector<std::vector<double> > tsnePoints;

    std::vector<std::vector<float> > data;
    int dims;
    double perplexity;
    double theta;
    bool normalize;
    bool runManually;

    int N, D;
    double *X, *Y;

    int iter, max_iter;
};
