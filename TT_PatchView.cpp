/*
  ==============================================================================

    TT_PatchView.cpp
    Created: 1 Apr 2024 12:07:57pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#include "TT_PatchView.h"
TT_PatchView::TT_PatchView(TT_ModelManager* mm) : manager(mm), save("Save")
{
    viewLabel.setFont(StyleSheet::Fonts::header);
    viewLabel.setText("Patch", juce::dontSendNotification);
    viewLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&viewLabel);
    
    // init display boxes
    initSpectralDisplays();
    initTemporalDisplays();
    
    // init display labels
    initSpectralLabels();
    initTemporalLabels();
    
    // init save from
    saveFromLabel.setFont(StyleSheet::Fonts::body);
    saveFromLabel.setText("Save From:", juce::dontSendNotification);
    saveFromLabel.setJustificationType(juce::Justification::left);
    saveFromLabel.attachToComponent(&saveFrom, true);
    addAndMakeVisible(&saveFromLabel);
    
    saveFrom.addItem("Spectral", 1);
    saveFrom.addItem("Temporal", 2);
    saveFrom.addItem("Both", 3);
    saveFrom.setColour(0x1000b00, StyleSheet::Colours::save);
    addAndMakeVisible(&saveFrom);
    saveFrom.onChange = [this]
    {
        manager->setMode(saveFrom.getSelectedId());
        save.setEnabled(true);
    };
    
    // init action button
    save.setColour(0x1000100, StyleSheet::Colours::save);
    save.setColour(0x1000101, StyleSheet::Colours::saveBrighter);
    save.setEnabled(false);
    addAndMakeVisible(&save);
    save.onClick = [this] { manager->savePatch(); };
    
    startTimerHz(33);
}

TT_PatchView::~TT_PatchView()
{
    manager = nullptr;
    // clear displays
}

void TT_PatchView::initDisplay(juce::TextEditor* display)
{
    display->setFont(StyleSheet::Fonts::body);
    // set colour
    display->setMultiLine(false);
    display->setReadOnly(true);
    display->setJustification(juce::Justification::centred);
    display->setColour(0x1000200, StyleSheet::Colours::display);
    addAndMakeVisible(display);
}

void TT_PatchView::initSpectralDisplays()
{
    initDisplay(&cutoff);
    initDisplay(&emphasis);
    initDisplay(&filterContourSpec);
    initDisplay(&osc2Detune);
    initDisplay(&osc3Detune);
}

void TT_PatchView::initSpectralLabels()
{
    spectralLabel.setFont(StyleSheet::Fonts::subHeader);
    spectralLabel.setText("Spectral", juce::dontSendNotification);
    spectralLabel.setJustificationType(juce::Justification::left);
    addAndMakeVisible(&spectralLabel);
    
    cutoffLabel.setFont(StyleSheet::Fonts::body);
    cutoffLabel.setText("Filter Cutoff", juce::dontSendNotification);
    cutoffLabel.setJustificationType(juce::Justification::left);
    cutoffLabel.attachToComponent(&cutoff, true);
    addAndMakeVisible(&cutoffLabel);
    
    emphasisLabel.setFont(StyleSheet::Fonts::body);
    emphasisLabel.setText("Filter Emphasis", juce::dontSendNotification);
    emphasisLabel.setJustificationType(juce::Justification::left);
    emphasisLabel.attachToComponent(&emphasis, true);
    addAndMakeVisible(&emphasisLabel);
    
    filterContourSpecLabel.setFont(StyleSheet::Fonts::body);
    filterContourSpecLabel.setText("Filter Contour", juce::dontSendNotification);
    filterContourSpecLabel.setJustificationType(juce::Justification::left);
    filterContourSpecLabel.attachToComponent(&filterContourSpec, true);
    addAndMakeVisible(&filterContourSpecLabel);
    
    osc2DetuneLabel.setFont(StyleSheet::Fonts::body);
    osc2DetuneLabel.setText("Osc 2 Detune", juce::dontSendNotification);
    osc2DetuneLabel.setJustificationType(juce::Justification::left);
    osc2DetuneLabel.attachToComponent(&osc2Detune, true);
    addAndMakeVisible(&osc2DetuneLabel);
    
    osc3DetuneLabel.setFont(StyleSheet::Fonts::body);
    osc3DetuneLabel.setText("Osc 3 Detune", juce::dontSendNotification);
    osc3DetuneLabel.setJustificationType(juce::Justification::left);
    osc3DetuneLabel.attachToComponent(&osc3Detune, true);
    addAndMakeVisible(&osc3DetuneLabel);
}

void TT_PatchView::initTemporalDisplays()
{
    initDisplay(&filterAttack);
    initDisplay(&filterDecay);
    initDisplay(&filterSustain);
    initDisplay(&filterRelease);
    initDisplay(&filterContourTemp);
    initDisplay(&vcaAttack);
    initDisplay(&vcaDecay);
    initDisplay(&vcaSustain);
    initDisplay(&vcaRelease);
}

void TT_PatchView::initTemporalLabels()
{
    temporalLabel.setFont(StyleSheet::Fonts::subHeader);
    temporalLabel.setText("Temporal", juce::dontSendNotification);
    temporalLabel.setJustificationType(juce::Justification::left);
    addAndMakeVisible(&temporalLabel);
    
    filterAttackLabel.setFont(StyleSheet::Fonts::body);
    filterAttackLabel.setText("Filter Attack", juce::dontSendNotification);
    filterAttackLabel.setJustificationType(juce::Justification::left);
    filterAttackLabel.attachToComponent(&filterAttack, true);
    addAndMakeVisible(&filterAttackLabel);
    
    filterDecayLabel.setFont(StyleSheet::Fonts::body);
    filterDecayLabel.setText("Filter Decay", juce::dontSendNotification);
    filterDecayLabel.setJustificationType(juce::Justification::left);
    filterDecayLabel.attachToComponent(&filterDecay, true);
    addAndMakeVisible(&filterDecayLabel);
    
    filterSustainLabel.setFont(StyleSheet::Fonts::body);
    filterSustainLabel.setText("Filter Sustain", juce::dontSendNotification);
    filterSustainLabel.setJustificationType(juce::Justification::left);
    filterSustainLabel.attachToComponent(&filterSustain, true);
    addAndMakeVisible(&filterSustainLabel);
    
    filterReleaseLabel.setFont(StyleSheet::Fonts::body);
    filterReleaseLabel.setText("Filter Release", juce::dontSendNotification);
    filterReleaseLabel.setJustificationType(juce::Justification::left);
    filterReleaseLabel.attachToComponent(&filterRelease, true);
    addAndMakeVisible(&filterReleaseLabel);
    
    filterContourTempLabel.setFont(StyleSheet::Fonts::body);
    filterContourTempLabel.setText("Filter Contour", juce::dontSendNotification);
    filterContourTempLabel.setJustificationType(juce::Justification::left);
    filterContourTempLabel.attachToComponent(&filterContourTemp, true);
    addAndMakeVisible(&filterContourTempLabel);
    
    vcaAttackLabel.setFont(StyleSheet::Fonts::body);
    vcaAttackLabel.setText("VCA Attack", juce::dontSendNotification);
    vcaAttackLabel.setJustificationType(juce::Justification::left);
    vcaAttackLabel.attachToComponent(&vcaAttack, true);
    addAndMakeVisible(&vcaAttackLabel);
    
    vcaDecayLabel.setFont(StyleSheet::Fonts::body);
    vcaDecayLabel.setText("VCA Decay", juce::dontSendNotification);
    vcaDecayLabel.setJustificationType(juce::Justification::left);
    vcaDecayLabel.attachToComponent(&vcaDecay, true);
    addAndMakeVisible(&vcaDecayLabel);
    
    vcaSustainLabel.setFont(StyleSheet::Fonts::body);
    vcaSustainLabel.setText("VCA Sustain", juce::dontSendNotification);
    vcaSustainLabel.setJustificationType(juce::Justification::left);
    vcaSustainLabel.attachToComponent(&vcaSustain, true);
    addAndMakeVisible(&vcaSustainLabel);
    
    vcaReleaseLabel.setFont(StyleSheet::Fonts::body);
    vcaReleaseLabel.setText("VCA Release", juce::dontSendNotification);
    vcaReleaseLabel.setJustificationType(juce::Justification::left);
    vcaReleaseLabel.attachToComponent(&vcaRelease, true);
    addAndMakeVisible(&vcaReleaseLabel);
}

void TT_PatchView::paint (juce::Graphics& g)
{
    // paint background
    g.setColour(StyleSheet::Colours::subViewBG);
    g.fillRect(getLocalBounds());
    g.setColour(StyleSheet::Colours::subViewOL);
    g.drawRect(getLocalBounds());
}

void TT_PatchView::resized()
{
    auto bounds = getLocalBounds();
    
    // text
    auto headerBounds = bounds.removeFromTop(Bounds::SubView::headerHeight);
    auto footer = bounds.removeFromBottom(Bounds::SubView::actionHeight);
    auto saveFromBounds = bounds.removeFromBottom(Bounds::SubView::dropDownHeight);
    viewLabel.setBounds(headerBounds);
    
    // labels
    auto labelBounds = bounds.removeFromLeft(Bounds::SubView::patchLabelWidth);
    auto paramLabelHeight = labelBounds.getHeight() / 15;
    auto headerPadding = bounds.removeFromTop(paramLabelHeight);
    auto saveFromLabelBounds = bounds.removeFromBottom(Bounds::SubView::labelHeight - 10).removeFromLeft(Bounds::SubView::labelWidth);
    
    saveFromLabel.setBounds(saveFromLabelBounds);
    
    auto spectralLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto cutoffLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto emphasisLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto filterContourSpecLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto osc2DetuneLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto osc3DetuneLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    
    auto temporalLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto filterAttackLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto filterDecayLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto filterSustainLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto filterReleaseLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto filterContourTempLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto vcaAttackLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto vcaDecayLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto vcaSustainLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    auto vcaReleaseLabelBounds = labelBounds.removeFromTop(paramLabelHeight);
    
    spectralLabel.setBounds(spectralLabelBounds);
    cutoffLabel.setBounds(cutoffLabelBounds);
    emphasisLabel.setBounds(emphasisLabelBounds);
    filterContourSpecLabel.setBounds(filterContourSpecLabelBounds);
    osc2DetuneLabel.setBounds(osc2DetuneLabelBounds);
    osc3DetuneLabel.setBounds(osc3DetuneLabelBounds);
    
    temporalLabel.setBounds(temporalLabelBounds);
    filterAttackLabel.setBounds(filterAttackLabelBounds);
    filterDecayLabel.setBounds(filterDecayLabelBounds);
    filterSustainLabel.setBounds(filterSustainLabelBounds);
    filterReleaseLabel.setBounds(filterReleaseLabelBounds);
    filterContourTempLabel.setBounds(filterContourTempLabelBounds);
    vcaAttackLabel.setBounds(vcaAttackLabelBounds);
    vcaDecayLabel.setBounds(vcaDecayLabelBounds);
    vcaSustainLabel.setBounds(vcaSustainLabelBounds);
    vcaReleaseLabel.setBounds(vcaReleaseLabelBounds);
    
    // components
    auto paramHeight = bounds.getHeight() / 15;
    
    auto cutoffBounds = bounds.removeFromTop(paramHeight);
    auto emphasisBounds = bounds.removeFromTop(paramHeight);
    auto filterContourSpecBounds = bounds.removeFromTop(paramHeight);
    auto osc2DetuneBounds = bounds.removeFromTop(paramHeight);
    auto osc3DetuneBounds = bounds.removeFromTop(paramHeight);
    
    auto sectionPadding = bounds.removeFromTop(paramLabelHeight + 5);
    
    auto filterAttackBounds = bounds.removeFromTop(paramHeight);
    auto filterDecayBounds = bounds.removeFromTop(paramHeight);
    auto filterSustainBounds = bounds.removeFromTop(paramHeight);
    auto filterReleaseBounds = bounds.removeFromTop(paramHeight);
    auto filterContourTempBounds = bounds.removeFromTop(paramHeight);
    auto vcaAttackBounds = bounds.removeFromTop(paramHeight);
    auto vcaDecayBounds = bounds.removeFromTop(paramHeight);
    auto vcaSustainBounds = bounds.removeFromTop(paramHeight);
    auto vcaReleaseBounds = bounds.removeFromTop(paramHeight);
    
    cutoff.setBounds(cutoffBounds.reduced(Bounds::Margins::display));
    emphasis.setBounds(emphasisBounds.reduced(Bounds::Margins::display));
    filterContourSpec.setBounds(filterContourSpecBounds.reduced(Bounds::Margins::display));
    osc2Detune.setBounds(osc2DetuneBounds.reduced(Bounds::Margins::display));
    osc3Detune.setBounds(osc3DetuneBounds.reduced(Bounds::Margins::display));
    
    filterAttack.setBounds(filterAttackBounds.reduced(Bounds::Margins::display));
    filterDecay.setBounds(filterDecayBounds.reduced(Bounds::Margins::display));
    filterSustain.setBounds(filterSustainBounds.reduced(Bounds::Margins::display));
    filterRelease.setBounds(filterReleaseBounds.reduced(Bounds::Margins::display));
    filterContourTemp.setBounds(filterContourTempBounds.reduced(Bounds::Margins::display));
    vcaAttack.setBounds(vcaAttackBounds.reduced(Bounds::Margins::display));
    vcaDecay.setBounds(vcaDecayBounds.reduced(Bounds::Margins::display));
    vcaSustain.setBounds(vcaSustainBounds.reduced(Bounds::Margins::display));
    vcaRelease.setBounds(vcaReleaseBounds.reduced(Bounds::Margins::display));
    
    saveFrom.setBounds(saveFromBounds.reduced(Bounds::Margins::dropDown));
    save.setBounds(footer.reduced(Bounds::Margins::actionButton));
}

void TT_PatchView::setSpectralDisplays(std::vector<float> params)
{
    cutoff.setText((juce::String)params[0]);
    emphasis.setText((juce::String)params[1]);
    filterContourSpec.setText((juce::String)params[2]);
    osc2Detune.setText((juce::String)params[3]);
    osc3Detune.setText((juce::String)params[4]);
}

void TT_PatchView::setTemporalDisplays(std::vector<float> params)
{
    filterAttack.setText((juce::String)params[0]);
    filterDecay.setText((juce::String)params[1]);
    filterSustain.setText((juce::String)params[2]);
    filterRelease.setText((juce::String)params[3]);
    vcaAttack.setText((juce::String)params[4]);
    vcaDecay.setText((juce::String)params[5]);
    vcaSustain.setText((juce::String)params[6]);
    vcaRelease.setText((juce::String)params[7]);
    filterContourTemp.setText((juce::String)params[8]);
}

void TT_PatchView::clearSpectralDisplays()
{
    cutoff.clear();
    emphasis.clear();
    filterContourSpec.clear();
    osc2Detune.clear();
    osc3Detune.clear();
}

void TT_PatchView::clearTemporalDisplays()
{
    filterAttack.clear();
    filterDecay.clear();
    filterSustain.clear();
    filterRelease.clear();
    vcaAttack.clear();
    vcaDecay.clear();
    vcaSustain.clear();
    vcaRelease.clear();
    filterContourTemp.clear();
}
