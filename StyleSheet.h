/*
  ==============================================================================

    StyleSheet.h
    Created: 26 Mar 2024 6:11:01pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace Bounds
{
    namespace Main
    {
        static auto headerHeight = 30;
        static auto footerHeight = 30;
    
        static auto subViewWidth = 200;
        static auto subViewHeight = 320;
    }

    namespace SubView
    {
        static auto headerHeight = 30;
        static auto footerHeight = 10;

        static auto patchLabelWidth = 100;
    
        static auto labelWidth = 80;
        static auto labelHeight = 20;
    
        static auto bodyHeight = 80;

        static auto dropDownHeight = 40;

        static auto actionWidth = 120;
        static auto actionHeight = 40;
    }

    namespace Margins
    {
        static auto main = 20;
        static auto title = 5;
        static auto subView = 4;
    
        static auto dropDown = 7;
        static auto actionButton = 6;
        static auto display = 2;
    }
}

namespace StyleSheet
{
    namespace Colours
    {
        // backgrounds
        static auto mainBG = juce::Colours::saddlebrown.darker();
        static auto subViewBG = juce::Colours::black;
        static auto subViewOL = juce::Colours::white;
    
        // buttons and such
        static auto spectral = juce::Colours::blue;
        static auto spectralBrighter = juce::Colours::blue.brighter();
        static auto temporal = juce::Colours::red;
        static auto temporalBrighter = juce::Colours::red.brighter();
    
        static auto display = juce::Colours::black;
        static auto save = juce::Colours::darkgreen;
        static auto saveBrighter = juce::Colours::darkgreen.brighter();
    
        // text
        static auto title = juce::Colours::black;
        static auto headerText = juce::Colours::white;
        static auto bodyText = juce::Colours::white;
    }

    namespace Fonts
    {
        static auto title = juce::Font(24.0f);
        static auto header = juce::Font(18.0f);
        static auto subHeader = juce::Font(16.0f);
        static auto body = juce::Font(14.0f);
        static auto logger = juce::Font(12.0f);
    }
}
