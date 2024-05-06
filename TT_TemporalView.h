/*
  ==============================================================================

    TT_TemporalView.h
    Created: 1 Apr 2024 12:07:45pm
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
class TT_TemporalView  : public juce::Component
{
public:
    
    TT_TemporalView(TT_ModelManager* mm);
    ~TT_TemporalView() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    
    TT_ModelManager* manager;
    
    juce::Label viewLabel;
    juce::Label selectTagLabel;
    
    juce::ComboBox selectTag;
    juce::TextButton generate;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TT_TemporalView)
};
