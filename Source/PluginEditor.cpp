#include "PluginProcessor.h"
#include "PluginEditor.h"


iphoneAudioAudioProcessorEditor::iphoneAudioAudioProcessorEditor (iphoneAudioAudioProcessor& p): AudioProcessorEditor (&p), audioProcessor (p){
    
    addAndMakeVisible(draggableComponent);
    
    
    draggableComponent.setStartFunction([this](float xpos , float ypos){
        
        float mappedFreq = juce::jmap(xpos , 0.0f , (float)getWidth() , 100.0f , 1000.0f);
        audioProcessor.getSynth().setOscFrequency(mappedFreq);
        audioProcessor.getSynth().startADSR(); 
        
    });
    
    draggableComponent.setMoveFunction([this](float xpos , float ypos){
       
            
        float mappedFreq = juce::jmap(xpos , 0.0f , (float)getWidth() , 100.0f , 1000.0f);
        audioProcessor.getSynth().setOscFrequency(mappedFreq);
        
    });
    
    draggableComponent.setEndFunction([this](){
        
        audioProcessor.getSynth().releaseADSR();

    });
    
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
