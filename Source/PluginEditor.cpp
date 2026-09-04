#include "PluginProcessor.h"
#include "PluginEditor.h"


iphoneAudioAudioProcessorEditor::iphoneAudioAudioProcessorEditor (iphoneAudioAudioProcessor& p): AudioProcessorEditor (&p), audioProcessor (p){
    
    addAndMakeVisible(draggableComponent);
    
    
}

iphoneAudioAudioProcessorEditor::~iphoneAudioAudioProcessorEditor(){
    
    
    
}

//==============================================================================
void iphoneAudioAudioProcessorEditor::paint (juce::Graphics& g ){
    
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
}


void iphoneAudioAudioProcessorEditor::resized(){
    
    auto bounds = getLocalBounds();
    
    draggableComponent.setBounds((int)(bounds.getWidth()/ 2.0f), (int)(bounds.getHeight() / 2.0f), (int)draggableComponent.getDiameter(), (int)draggableComponent.getDiameter()); 
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new iphoneAudioAudioProcessor();
}
