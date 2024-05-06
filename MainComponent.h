#pragma once

#include <JuceHeader.h>
#include "TT_PatchView.h"
#include "TT_SpectralView.h"
#include "TT_TemporalView.h"
#include "TT_ModelManager.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Label title;
    
    TT_SpectralView spectralView;
    TT_TemporalView temporalView;
    TT_PatchView patchView;
    
    TT_ModelManager manager;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
