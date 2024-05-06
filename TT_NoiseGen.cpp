/*
  ==============================================================================

    TT_NoiseGen.cpp
    Created: 8 Apr 2024 3:53:06pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#include "TT_NoiseGen.h"

TT_NoiseGen::TT_NoiseGen()
{

}

TT_NoiseGen::~TT_NoiseGen()
{
    
}

void TT_NoiseGen::setTag(juce::Identifier newTag)
{
    currentTag = newTag;
}

void TT_NoiseGen::processNoiseSpectral(std::vector<float>* params)
{
    for(int i = 0 ; i < params->size() ; i++)
    {
        float value = params->at(i);
        params->at(i) = processParameter(value);
    }
}

void TT_NoiseGen::processNoiseTemporal(std::vector<float>* params)
{
    for(int i = 0 ; i < params->size() ; i++)
    {
        float value = params->at(i);
        params->at(i) = processParameter(value);
    }
}

float TT_NoiseGen::processParameter(float param)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-0.15, 0.15);
    
    float originalValue = param;
    
    do
    {
        param = originalValue;
        float noise = dist(gen);
        param += noise;
    } while (param < 0);
  
    return param;
}
