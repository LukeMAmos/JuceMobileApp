#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class iphoneAudioAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    iphoneAudioAudioProcessorEditor (iphoneAudioAudioProcessor& p);
    ~iphoneAudioAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    iphoneAudioAudioProcessor& audioProcessor;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (iphoneAudioAudioProcessorEditor)
};
