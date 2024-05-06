/*
  ==============================================================================

    TT_NoiseGen.h
    Created: 8 Apr 2024 3:10:38pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <random>

class TT_NoiseGen
{
public:
    
    TT_NoiseGen();
    ~TT_NoiseGen();
    
    void setTag(juce::Identifier newTag);
    
    void processNoiseSpectral(std::vector<float>* params);
    void processNoiseTemporal(std::vector<float>* params);
    float processParameter(float param);
    
private:
    
    juce::Identifier currentTag;
};
