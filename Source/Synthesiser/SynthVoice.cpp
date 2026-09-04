#include "SynthVoice.h"

ContinousSynth::ContinousSynth(){
    
    
}

void ContinousSynth::prepare(const juce::dsp::ProcessSpec& spec){
    
    OSC.prepare(spec);
    OSC.initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f;}); //Initalised as a square wave , implementing OSC switching for individual voicing
    
    ADSR.setSampleRate(spec.sampleRate);
    
}

void ContinousSynth::renderNextBlock(juce::AudioBuffer<float>& outputBuffer , int startSample , int numSamples){
    
    juce::ScopedNoDenormals noDenormals;
    
    juce::dsp::AudioBlock<float> block(outputBuffer);
    auto subBlock = block.getSubBlock(0, (size_t)numSamples);
    juce::dsp::ProcessContextReplacing<float> context(subBlock);
    
    OSC.process(context);
    ADSR.applyEnvelopeToBuffer(outputBuffer, 0, numSamples);
    
}

void ContinousSynth::setOscFrequency(float frequency){
    
    OSC.setFrequency(frequency); 
    
}

void ContinousSynth::startADSR(){
    
    ADSR.noteOn();
}
void ContinousSynth::releaseADSR(){
    
    ADSR.noteOff();
}
