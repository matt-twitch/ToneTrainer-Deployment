/*
  ==============================================================================

    TT_PatchView.h
    Created: 1 Apr 2024 12:07:57pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once
#include "Constants.h"
#include "StyleSheet.h"
#include "TT_ModelManager.h"

//==============================================================================
/*
*/
class TT_PatchView  : public juce::Component, juce::Timer
{
public:
    
    TT_PatchView(TT_ModelManager* mm);
    ~TT_PatchView() override;

    void initDisplay(juce::TextEditor* display);
    
    void initSpectralDisplays();
    void initSpectralLabels();
    void initTemporalDisplays();
    void initTemporalLabels();
    
    void paint(juce::Graphics&) override;
    void resized() override;

    void setSpectralDisplays(std::vector<float> params);
    void setTemporalDisplays(std::vector<float> params);
    
    void clearSpectralDisplays();
    void clearTemporalDisplays();
    
private:

    void timerCallback() override
    {
        if(manager->getSpectralFlag())
        {
            clearSpectralDisplays();
            setSpectralDisplays(manager->getSpectralParams());
            manager->resetSpectralFlag();
        }
        
        if(manager->getTemporalFlag())
        {
            clearTemporalDisplays();
            setTemporalDisplays(manager->getTemporalParams());
            manager->resetTemporalFlag();
        }
    }
    
    TT_ModelManager* manager;
    
    juce::Label viewLabel;
    juce::Label saveFromLabel;
    
    juce::Label spectralLabel;
    juce::Label cutoffLabel;
    juce::Label emphasisLabel;
    juce::Label filterContourSpecLabel;
    juce::Label osc2DetuneLabel;
    juce::Label osc3DetuneLabel;
    
    juce::Label temporalLabel;
    juce::Label filterAttackLabel;
    juce::Label filterDecayLabel;
    juce::Label filterSustainLabel;
    juce::Label filterReleaseLabel;
    juce::Label filterContourTempLabel;
    juce::Label vcaAttackLabel;
    juce::Label vcaDecayLabel;
    juce::Label vcaSustainLabel;
    juce::Label vcaReleaseLabel;
    
    juce::TextEditor cutoff;
    juce::TextEditor emphasis;
    juce::TextEditor filterContourSpec;
    juce::TextEditor osc2Detune;
    juce::TextEditor osc3Detune;
    
    juce::TextEditor filterAttack;
    juce::TextEditor filterDecay;
    juce::TextEditor filterSustain;
    juce::TextEditor filterRelease;
    juce::TextEditor filterContourTemp;
    juce::TextEditor vcaAttack;
    juce::TextEditor vcaDecay;
    juce::TextEditor vcaSustain;
    juce::TextEditor vcaRelease;
    
    juce::ComboBox saveFrom;
    juce::TextButton save;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TT_PatchView)
};
