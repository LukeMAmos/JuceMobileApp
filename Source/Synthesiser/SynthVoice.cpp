#include "SynthVoice.h"


SynthVoice::SynthVoice(){
    
    
}

void SynthVoice::prepare(const juce::dsp::ProcessSpec& spec){
    
    OSC.prepare(spec);
    OSC.initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f;}); //Initalised as a square wave , implementing OSC switching for individual voicing
    
    ADSR.setSampleRate(spec.sampleRate);
    
}

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound) {
    return true; 
    
}

void SynthVoice::startNote(int midiNoteNumber , float velocity , juce::SynthesiserSound* sound , int currentPitchWheelPosition) {
    
    
}

void SynthVoice::stopNote(float velocity , bool allowTailOff) {
    
    
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer , int startSample , int numSamples) {
    
    
}

void SynthVoice::pitchWheelMoved(int newValue) {
    
    
    
}

void SynthVoice::controllerMoved(int controllerNumber, int newValue) {
    
    
}
