#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : spectralView(&manager), temporalView(&manager), patchView(&manager)
{
    title.setFont(StyleSheet::Fonts::title);
    title.setText("ToneTrainer - Minimonsta2", juce::dontSendNotification);
    title.setJustificationType(juce::Justification::left);
    title.attachToComponent(this, false);
    addAndMakeVisible(&title);
    
    addAndMakeVisible(&spectralView);
    addAndMakeVisible(&temporalView);
    addAndMakeVisible(&patchView);
    
    setSize(440, 500);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(StyleSheet::Colours::mainBG);
    title.paintEntireComponent(g, true);
}

void MainComponent::resized()
{
    auto bounds = getLocalBounds().reduced(Bounds::Margins::main);
    auto headerBounds = bounds.removeFromTop(Bounds::Main::headerHeight);
    title.setBounds(headerBounds.reduced(Bounds::Margins::title));
    
    auto generateViewBounds = bounds.removeFromLeft(Bounds::Main::subViewWidth);
    auto spectralBounds = generateViewBounds.removeFromTop(generateViewBounds.getHeight() / 2);
    auto patchBounds = bounds.removeFromLeft(Bounds::Main::subViewWidth);
    
    spectralView.setBounds(spectralBounds.reduced(Bounds::Margins::subView));
    temporalView.setBounds(generateViewBounds.reduced(Bounds::Margins::subView));
    patchView.setBounds(patchBounds.reduced(Bounds::Margins::subView));
}
