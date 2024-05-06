/*
  ==============================================================================

    TT_ModelManager.h
    Created: 2 Apr 2024 11:29:53am
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once
#include "TT_PatchConstructor.h"
#include "TT_NoiseGen.h"

class TT_ModelManager
{
public:
    
    TT_ModelManager();
    ~TT_ModelManager();
    
    void constructSpectralModel();
    void constructTemporalModel();
    
    void armSpectralModel(int tag);
    void armTemporalModel(int tag);
    
    void generateSpectralParameters();
    void generateTemporalParameters();
    
    bool getSpectralFlag() { return spectralFlag; }
    bool getTemporalFlag() { return temporalFlag; }
    
    std::vector<float> getSpectralParams() { return spectralParams; }
    std::vector<float> getTemporalParams() { return temporalParams; }
    
    void setMode(int newMode) { constructor.setMode(newMode); }
    void savePatch();
    
    void reset();
    void resetSpectralFlag() { spectralFlag = false; }
    void resetTemporalFlag() { temporalFlag = false; }
    
private:
    
    TT_PatchConstructor constructor;
    TT_NoiseGen noiseGen;
    
    tiny_dnn::network<tiny_dnn::sequential> spectralModel;
    tiny_dnn::core::backend_t backend_type = tiny_dnn::core::default_engine();
    int spectralParamDim = 5;
    int hiddenSize = 128;
    int latentDim = 1;
    
    tiny_dnn::network<tiny_dnn::sequential> temporalModel;
    int temporalParamDim = 9;
    
    tiny_dnn::vec_t spectralTag;
    tiny_dnn::vec_t temporalTag;
    
    tiny_dnn::vec_t spectralResult;
    tiny_dnn::vec_t temporalResult;
    
    std::vector<float> spectralParams;
    std::vector<float> temporalParams;
    
    bool spectralFlag = false;
    bool temporalFlag = false;
};
