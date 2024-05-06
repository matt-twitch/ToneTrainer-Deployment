/*
  ==============================================================================

    TT_TemporalView.cpp
    Created: 1 Apr 2024 12:07:45pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#include "TT_TemporalView.h"
TT_TemporalView::TT_TemporalView(TT_ModelManager* mm) : manager(mm), generate("Generate")
{
    viewLabel.setFont(StyleSheet::Fonts::header);
    viewLabel.setText("Temporal", juce::dontSendNotification);
    viewLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&viewLabel);
    
    // init tag select
    selectTagLabel.setFont(StyleSheet::Fonts::body);
    selectTagLabel.setText("Select Tag", juce::dontSendNotification);
    selectTagLabel.setJustificationType(juce::Justification::left);
    selectTagLabel.attachToComponent(&selectTag, true);
    
    addAndMakeVisible(&selectTagLabel);
    
    selectTag.addItem("Pluck", 1);
    selectTag.addItem("Long Release", 2);
    selectTag.addItem("Swell", 3);
    selectTag.addItem("Short", 4);
    selectTag.setColour(0x1000b00, StyleSheet::Colours::temporal);
    addAndMakeVisible(&selectTag);
    selectTag.onChange = [this]
    {
        manager->armTemporalModel(selectTag.getSelectedId());
        generate.setEnabled(true);
    };
    
    // init action button
    generate.setColour(0x1000100, StyleSheet::Colours::temporal);
    generate.setColour(0x1000101, StyleSheet::Colours::temporalBrighter);
    generate.setEnabled(false);
    addAndMakeVisible(&generate);
    generate.onClick = [this] { manager->generateTemporalParameters(); };
}

TT_TemporalView::~TT_TemporalView()
{
    manager = nullptr;
}

void TT_TemporalView::paint (juce::Graphics& g)
{
    // paint background
    g.setColour(StyleSheet::Colours::subViewBG);
    g.fillRect(getLocalBounds());
    g.setColour(StyleSheet::Colours::subViewOL);
    g.drawRect(getLocalBounds());
}

void TT_TemporalView::resized()
{
    auto bounds = getLocalBounds();
    
    // text
    auto headerBounds = bounds.removeFromTop(Bounds::SubView::headerHeight);
    auto footer = bounds.removeFromBottom(Bounds::SubView::actionHeight);
    viewLabel.setBounds(headerBounds);
    
    // labels
    auto labelBounds = bounds.removeFromLeft(Bounds::SubView::labelWidth);
    auto selectTagLabelBounds = labelBounds.removeFromTop(Bounds::SubView::labelHeight);
    
    selectTagLabel.setBounds(selectTagLabelBounds);
    
    // components
    auto selectTagBounds = bounds.removeFromTop(Bounds::SubView::dropDownHeight);
    
    selectTag.setBounds(selectTagBounds.reduced(Bounds::Margins::dropDown));
    generate.setBounds(footer.reduced(Bounds::Margins::actionButton));
}
