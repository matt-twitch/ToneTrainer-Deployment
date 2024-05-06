/*
  ==============================================================================

    TT_SpectralView.h
    Created: 1 Apr 2024 12:07:29pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Constants.h"
#include "StyleSheet.h"
#include "TT_ModelManager.h"

//==============================================================================
/*
*/
class TT_SpectralView  : public juce::Component
{
public:
    
    TT_SpectralView(TT_ModelManager* mm);
    ~TT_SpectralView() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    
    TT_ModelManager* manager;
    
    juce::Label viewLabel;
    juce::Label selectTagLabel;
    
    juce::ComboBox selectTag;
    juce::TextButton generate;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TT_SpectralView)
};
