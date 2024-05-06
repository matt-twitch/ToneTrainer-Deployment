/*
  ==============================================================================

    TT_ModelManager.cpp
    Created: 2 Apr 2024 11:29:53am
    Author:  Matt Twitchen

  ==============================================================================
*/

#include "TT_ModelManager.h"

using namespace tiny_dnn;

TT_ModelManager::TT_ModelManager()
{
    // construct models
    constructSpectralModel();
    constructTemporalModel();
    
    // load models
    spectralModel.load((juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDesktopDirectory).getFullPathName()).toStdString() + "/ToneTrainer/Models/spectral-model");
    temporalModel.load((juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDesktopDirectory).getFullPathName()).toStdString() + "/ToneTrainer/Models/temporal-model");
}

TT_ModelManager::~TT_ModelManager()
{
    
}

void TT_ModelManager::constructSpectralModel()
{
    // Encoder
    spectralModel << fully_connected_layer(spectralParamDim, spectralParamDim);
    spectralModel << activation::leaky_relu();
    spectralModel << recurrent_layer(lstm(spectralParamDim, hiddenSize), spectralParamDim);
    spectralModel << activation::leaky_relu();
    spectralModel << fully_connected_layer(hiddenSize, latentDim);
    
    // Decoder
    spectralModel << fully_connected_layer(latentDim, hiddenSize);
    spectralModel << activation::leaky_relu();
    spectralModel << recurrent_layer(lstm(hiddenSize, spectralParamDim), spectralParamDim);
    spectralModel << activation::leaky_relu();
    spectralModel << fully_connected_layer(spectralParamDim, spectralParamDim);
    spectralModel << activation::sigmoid();
}

void TT_ModelManager::constructTemporalModel()
{
    // Encoder
    temporalModel << fully_connected_layer(temporalParamDim, temporalParamDim);
    temporalModel << activation::leaky_relu();
    temporalModel << recurrent_layer(lstm(temporalParamDim, hiddenSize), temporalParamDim);
    temporalModel << activation::leaky_relu();
    temporalModel << fully_connected_layer(hiddenSize, latentDim);
    
    // Decoder
    temporalModel << fully_connected_layer(latentDim, hiddenSize);
    temporalModel << activation::leaky_relu();
    temporalModel << recurrent_layer(lstm(hiddenSize, temporalParamDim), temporalParamDim);
    temporalModel << activation::leaky_relu();
    temporalModel << fully_connected_layer(temporalParamDim, temporalParamDim);
    temporalModel << activation::sigmoid();
}

void TT_ModelManager::armSpectralModel(int tag)
{
    switch(tag)
    {
        case 1: // bright
            spectralTag = {1, 0, 0, 0, 0};
            constructor.setSpectralTag("Bright");
        break;
        case 2: // dark
            spectralTag = {0, 1, 0, 0, 0};
            constructor.setSpectralTag("Dark");
        break;
        case 3: // resonant
            spectralTag = {0, 0, 1, 0, 0};
            constructor.setSpectralTag("Resonant");
        break;
        case 4: // soft
            spectralTag = {0, 0, 0, 1, 0};
            constructor.setSpectralTag("Soft");
        break;
    }
}

void TT_ModelManager::armTemporalModel(int tag)
{
    switch(tag)
    {
        case 1: // pluck
            temporalTag = {0, 0, 0, 1, 0, 0, 0, 0, 0};
            constructor.setTemporalTag("Pluck");
        break;
        case 2: // long release
            temporalTag = {0, 0, 1, 0, 0, 0, 0, 0, 0};
            constructor.setTemporalTag("Long Release");
        break;
        case 3: // swell
            temporalTag = {0, 1, 0, 0, 0, 0, 0, 0, 0};
            constructor.setTemporalTag("Swell");
        break;
        case 4: // short
            temporalTag = {1, 0, 0, 0, 0, 0, 0, 0, 0};
            constructor.setTemporalTag("Short");
        break;
    }
}

void TT_ModelManager::generateSpectralParameters()
{
    spectralParams.clear();
    spectralResult = spectralModel.predict(spectralTag);
    
    for(int i = 0 ; i < spectralResult.size() ; i++)
        spectralParams.push_back(spectralResult.at(i));
    
    noiseGen.processNoiseSpectral(&spectralParams);
    constructor.setSpectralParams(spectralParams);
    
    spectralFlag = true;
}

void TT_ModelManager::generateTemporalParameters()
{
    temporalParams.clear();
    temporalResult = temporalModel.predict(temporalTag);
    
    for(int i = 0 ; i < temporalResult.size() ; i++)
        temporalParams.push_back(temporalResult.at(i));
    
    noiseGen.processNoiseTemporal(&temporalParams);
    constructor.setTemporalParams(temporalParams);
    
    temporalFlag = true;
}

void TT_ModelManager::savePatch()
{
    constructor.savePatch(spectralParams, temporalParams);
}

void TT_ModelManager::reset()
{
    spectralTag.clear();
    temporalTag.clear();
    
    spectralResult.clear();
    temporalResult.clear();
    
    spectralParams.clear();
    temporalParams.clear();
    
    constructor.reset();
}
