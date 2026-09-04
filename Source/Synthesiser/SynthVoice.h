#pragma once
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_dsp/juce_dsp.h>


class ContinousSynth{
    
public:
    
    ContinousSynth();
    
    void prepare(const juce::dsp::ProcessSpec& spec);
    
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer , int startSample , int numSamples);

    void setOscFrequency(float frequency);
    
    void startADSR();
    void releaseADSR(); 
    
private:
    
    juce::dsp::Oscillator<float> OSC;
    juce::ADSR ADSR;
    juce::ADSR::Parameters adsrParams;
    
    
};



