#include "PluginProcessor.h"
#include "PluginEditor.h"


iphoneAudioAudioProcessorEditor::iphoneAudioAudioProcessorEditor (iphoneAudioAudioProcessor& p): AudioProcessorEditor (&p), audioProcessor (p){
    
    
    
}

iphoneAudioAudioProcessorEditor::~iphoneAudioAudioProcessorEditor(){
    
    
    
}

//==============================================================================
void iphoneAudioAudioProcessorEditor::paint (juce::Graphics& g ){
    
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
}


void iphoneAudioAudioProcessorEditor::resized(){
    
    auto bounds = getLocalBounds();
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new iphoneAudioAudioProcessor();
}
