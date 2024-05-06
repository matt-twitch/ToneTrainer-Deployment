/*
  ==============================================================================

    TT_PatchConstructor.h
    Created: 2 Apr 2024 11:30:07am
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once
#include "tiny_dnn/tiny_dnn.h"
#include "TT_NoiseGen.h"
#include "TT_PatchNames.h"

class TT_PatchConstructor
{
public:
    
    TT_PatchConstructor();
    ~TT_PatchConstructor();
    
    void setMode(int newMode);
    void setSpectralTag(juce::String newTag) { spectralTag = newTag; }
    void setTemporalTag(juce::String newTag) { temporalTag = newTag; }
    void setSpectralParams(std::vector<float> newParams) { spectralParams = newParams; }
    void setTemporalParams(std::vector<float> newParams) { temporalParams = newParams; }
    
    juce::XmlElement constructPatch(std::vector<float> spectralParams, std::vector<float> temporalParams);
    void setMetadata(juce::XmlElement* metadata);
    void constructSpectralParameters(juce::XmlElement* parameterNode);
    void constructTemporalParameters(juce::XmlElement* parameterNode);
    
    void savePatch(std::vector<float> spectralParams, std::vector<float> temporalParams);
    void reset();
    
private:
    
    enum Mode
    {
        SPECTRAL = 0,
        TEMPORAL,
        BOTH
    } mode;
    
    juce::String spectralTag;
    juce::String temporalTag;
    
    std::vector<float> spectralParams;
    std::vector<float> temporalParams;
    
    juce::String patchName = "Init";
};
